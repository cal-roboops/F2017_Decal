#include "server.h"

Server::Server(QLCDNumber *client_count, QProgressBar *roverConnected, QObject *parent) : QTcpServer(parent) {
    this->client_count = client_count;
    this->roverConnected = roverConnected;
    this->roverIP = new QHostAddress("192.0.0.10");
    this->roverComm = NULL;
    this->roverEmerg = NULL;
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

    if (socket->localAddress().isEqual(*(this->roverIP))) {
        if (this->roverComm == NULL) {
            this->roverComm = socket;
        } else {
            this->roverEmerg = socket;

            QLinkedList<Thread*>::iterator i;
            for (i = this->threads.begin(); i != this->threads.end(); i++) {
                (*i)->add_rover_sockets(this->roverComm, this->roverEmerg);
            }
            connect(this->roverComm, SIGNAL(disconnected()), this, SLOT(rover_disconnected()));
            this->roverConnected->setValue(100);
        }

    } else {
        Thread *thread = new Thread(socket, this->roverComm, this->roverEmerg, &this->roverCommMutex, &this->roverEmergMutex, &this->threadsMutex, this);

        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), this, SLOT(update_client_count()));

        this->threads.append(thread);

        thread->add_all_threads(&this->threads);
        thread->start();
    }

    update_client_count();
}

void Server::update_client_count() {
    this->client_count->display(this->threads.size());
}

void Server::rover_disconnected() {
    //attempt emergency stop

    this->roverComm->deleteLater();
    this->roverEmerg->deleteLater();
    this->roverComm = NULL;
    this->roverEmerg = NULL;
    this->roverConnected->setValue(0);

    this->threadsMutex.lock();

    QLinkedList<Thread*>::iterator i;
    for (i = this->threads.begin(); i != this->threads.end(); i++) {
        (*i)->rover_disconnected();
    }

    this->threadsMutex.unlock();
}

void Server::terminate() {
    if (this->isListening()) {
        QLinkedList<Thread*> del_threads;

        QLinkedList<Thread*>::iterator i;
        for (i = this->threads.begin(); i != this->threads.end(); i++) {
            del_threads.append(*i);
        }

        for (i = del_threads.begin(); i != del_threads.end(); i++) {
            (*i)->disconnected();
        }
        this->roverComm = NULL;
        this->roverEmerg = NULL;
        this->close();
        update_client_count();
        this->roverConnected->setValue(0);
    }
}



