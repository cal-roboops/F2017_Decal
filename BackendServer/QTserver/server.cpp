#include "server.h"

Server::Server(QLCDNumber *client_count, QProgressBar *roverConnected, QObject *parent) : QTcpServer(parent) {
    this->client_count = client_count;
    this->roverConnected = roverConnected;
    this->roverIP = new QHostAddress("192.0.0.10");
    this->roverThread = nullptr;
}


void Server::start() {
    if (this->isListening()) {
        return;
    } else if (!this->listen(QHostAddress::Any, 8088)) {
        qDebug() << "failed to bind socket";
    }
}

void Server::incomingConnection(qintptr socket_descriptor) {
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(socket_descriptor);

    if (socket->peerAddress().isEqual(*(this->roverIP))) {
        if (this->roverThread) {
            this->roverThread->add_emerg_connection(socket);
            this->roverThread->start();
            this->roverConnected->setValue(100);

            connect(this->roverThread, SIGNAL(finished()), this->roverThread, SLOT(deleteLater()));
            connect(this->roverThread, SIGNAL(finished()), this, SLOT(rover_disconnected()));

            QLinkedList<ClientThread*>::iterator i;
            for (i = this->clientThreads.begin(); i != this->clientThreads.end(); i++) {
                (*i)->add_rover_connection(this->roverThread);
            }
        } else {
            this->roverThread = new RoverThread(socket);
        }

    } else {
        ClientThread *clientThread = new ClientThread(socket);
        this->clientThreads.append(clientThread);

        if (this->roverThread && this->roverThread->isRunning()) {
            clientThread->add_rover_connection(this->roverThread);
        }

        connect(clientThread, SIGNAL(finished()), clientThread, SLOT(deleteLater()));
        connect(clientThread, SIGNAL(finished()), this, SLOT(remove_client()));

        clientThread->start();
        update_client_count();
    }
}

void Server::update_client_count() {
    this->client_count->display(this->clientThreads.size());
}

void Server::remove_client() {

    QLinkedList<ClientThread*>::iterator i;
    for (i = this->clientThreads.begin(); i != this->clientThreads.end(); i++) {
        if ((*i)->isFinished()) {
            this->clientThreads.erase(i);
            break;
        }
    }
    update_client_count();
}

void Server::rover_disconnected() {
    QLinkedList<ClientThread*>::iterator i;

    for (i = this->clientThreads.begin(); i != this->clientThreads.end(); i++) {
        (*i)->remove_rover_connection();
    }

    this->roverConnected->setValue(0);
    this->roverThread = nullptr;
}

void Server::terminate() {
    if (this->isListening()) {

        if (this->roverThread) {
            this->roverThread->disconnect_rover();
            this->roverThread = nullptr;
        }

        QLinkedList<ClientThread*>::iterator i;
        for (i = this->clientThreads.begin(); i != this->clientThreads.end(); i++) {
            (*i)->disconnect_client();
        }

        this->clientThreads.clear();
        this->close();
        update_client_count();
        this->roverConnected->setValue(0);
    }
}



