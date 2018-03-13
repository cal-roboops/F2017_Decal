#include "server.h"

#include <QDebug>

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    this->roverIP = new QHostAddress("127.0.0.1");
    this->roverThread = new RoverThread();
    this->roverReady = false;

    connect(this->roverThread, SIGNAL(rover_ready(bool)), this, SLOT(rover_ready(bool)));
    this->roverThread->start();
}

Server::~Server()
{
    this->terminate();
    delete this->roverIP;
}

void Server::start()
{
    if (this->isListening()) return;

    if (!this->listen(QHostAddress::Any, 8088))
    {
        qDebug() << "Failed to bind socket";
    }
}

void Server::terminate() {
    if (this->isListening())
    {
        if (this->roverThread->isRunning())
        {
            this->roverThread->disconnect_rover();
            this->roverThread->deleteLater();
        }

        for (auto i = this->clientThreads.begin(); i != this->clientThreads.end(); i++)
        {
            (*i)->disconnect_client();
            (*i)->deleteLater();
        }

        this->clientThreads.clear();
        this->close();

        update_client_count();
    }
}

void Server::incomingConnection(qintptr socket_descriptor)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(socket_descriptor);

    if (socket->peerAddress().isEqual(*(this->roverIP)))
    {
        if (!this->roverThread->connected())
        {
            this->roverThread->add_connection(socket);
        } else
        {
            qDebug() << "Error too many rover connections";
        }
    } else
    {
        // Create new client thread
        ClientThread *clientThread = new ClientThread(socket, this->roverReady, this);
        this->clientThreads.append(clientThread);

        // Client to Rover Connections
        connect(clientThread, SIGNAL(send_command(int, QByteArray)), this->roverThread,
                SLOT(receive_command(int, QByteArray)), Qt::QueuedConnection);

        // Rover to Client Connections
        connect(clientThread, SIGNAL(receive_response(int, QByteArray)), this->roverThread,
                SLOT(respond_to_client(int, QByteArray)));
        connect(this->roverThread, SIGNAL(rover_ready(bool)), clientThread,
                SLOT(rover_ready(bool)));

        // Client to delete connections
        connect(clientThread, SIGNAL(finished()), clientThread, SLOT(deleteLater()));
        connect(clientThread, SIGNAL(finished()), this, SLOT(remove_client()));

        // Start Client Thread
        clientThread->start();
        update_client_count();
    }
}

void Server::update_client_count()
{
    emit client_count_update(this->clientThreads.size());
}

void Server::rover_ready(bool rdy)
{
    this->roverReady = rdy;
    emit rover_connected(rdy);
}

void Server::remove_client()
{
    for (auto i = this->clientThreads.begin(); i != this->clientThreads.end(); i++)
    {
        if ((*i)->isFinished())
        {
            this->clientThreads.erase(i);
            break;
        }
    }
    update_client_count();
}
