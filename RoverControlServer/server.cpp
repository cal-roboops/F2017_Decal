#include "server.h"

#include "../RoverSharedGlobals/rover_general.h"
#include "../RoverSharedGlobals/rover_json.h"
#include <QDebug>

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    // Setup data management thread
    this->dataThread = new DataThread(this);

    // Setup rover management thread
    this->roverIP = new QHostAddress(rover_ip);
    this->roverThread = new RoverThread(this);

    // Connect Rover signals to server slots
    connect(this->roverThread, SIGNAL(rover_ready(bool)), this, SLOT(rover_ready(bool)));

    // Connect Rover signals to data slots
    connect(this->roverThread, SIGNAL(respond_to_client(int,QByteArray)),
            this->dataThread, SLOT(receive_data(int,QByteArray)), Qt::QueuedConnection);

    // Start threads
    this->dataThread->start();
    this->roverThread->start();

    // Start server (in non-listening)
    if (this->listen(QHostAddress::Any, 8088)) this->pauseAccepting();
    else qDebug() << "Failed to bind socket";
}

Server::~Server()
{
    this->terminate();
    delete this->roverIP;
}

// Start server execution
void Server::start()
{
    if (this->isListening() || this->listen(QHostAddress::Any, 8088))
    {
        dataThread->start();
        emit server_on(true);
        this->resumeAccepting();
    } else
    {
        emit server_on(false);
        qDebug() << "Failed to bind socket";
    }
}

// Terminate server execution
void Server::terminate() {
    // Stop accepting connections
    this->pauseAccepting();

    // Disconnect rover
    if (this->roverThread->isRunning())
    {
        this->roverThread->disconnect_rover();
    }

    // Stop data logger
    if (this->dataThread->isRunning())
    {
        this->dataThread->terminate();
    }

    // Disconnect all clients
    for (auto i = this->clientThreads.begin(); i != this->clientThreads.end(); i++)
    {
        (*i)->disconnect_client();
    }

    // Update main gui client count
    update_client_count();

    // Emit off state
    emit server_on(false);
}

// Handles killing all threads
void Server::server_exit()
{
    this->terminate();

    this->roverThread->exit();
    this->dataThread->exit();

    this->roverThread->deleteLater();
    this->dataThread->deleteLater();
}

// Set the log location in datathread
void Server::setLogLoc(QString logLoc)
{
    this->dataThread->setLogLoc(logLoc);
}

// Handle all incoming connection requests
void Server::incomingConnection(qintptr socket_descriptor)
{
    // Create new socket and bind the incoming socket to it
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(socket_descriptor);

    if (socket->peerAddress().isEqual(*(this->roverIP)))
    {
        if (!this->roverThread->connected())
        {
            this->roverThread->add_connection(socket);
        } else
        {
            socket->disconnectFromHost();
            qDebug() << "Error too many rover connections";
        }
    } else
    {
        // Create new client thread with the new socket
        ClientThread *clientThread = new ClientThread(socket, this->roverReady, this);
        this->clientThreads.append(clientThread);

        // Connect Client Signals to Rover Slots
        connect(clientThread, SIGNAL(send_command(int, QByteArray)), this->roverThread,
                SLOT(receive_command(int, QByteArray)), Qt::QueuedConnection);

        // Connect Rover Signals to Client Slots
        connect(this->roverThread, SIGNAL(respond_to_client(int, QByteArray)), clientThread,
                SLOT(receive_response(int, QByteArray)));
        connect(this->roverThread, SIGNAL(rover_ready(bool)), clientThread,
                SLOT(rover_ready(bool)));

        // Connect Client to Server delete connections
        connect(clientThread, SIGNAL(finished()), this, SLOT(remove_client()));

        // Start Client Thread
        clientThread->start();
        update_client_count();
    }
}

// Emit the updated client count
void Server::update_client_count()
{
    emit client_count_update(this->clientThreads.size());
}

// Set/forward if rover is ready
void Server::rover_ready(bool rdy)
{
    this->roverReady = rdy;
    emit rover_connected(rdy);
}

// Remove and cleanup disconnected client threads/sockets
void Server::remove_client()
{
    this->clientThreads.removeAll((ClientThread*) sender());
    sender()->deleteLater();

    // Update the client counts
    update_client_count();
}
