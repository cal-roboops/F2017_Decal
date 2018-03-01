#include "roverthread.h"

RoverThread::RoverThread(QTcpSocket *roverComm, QObject *parent) : QThread(parent) {
    this->roverComm = roverComm;
    this->roverEmerg = nullptr;
    this->isBusy = false;

    connect(this->roverComm, SIGNAL(disconnected()), this, SLOT(disconnect_rover()));
}

void RoverThread::run() {
    connect(this->roverComm, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    exec();
}

void RoverThread::analyze_response() {
    QByteArray buf;
    buf = this->roverComm->readAll();

    if (buf.isEmpty()) {
        //error
    } else {
        emit respond_to_client(this->currClientSocketDescriptor, buf);
    }
    this->isBusy = false;
}

void RoverThread::receive_command(int clientSocketDescriptor, QByteArray command) {
    if (this->isBusy) {
        if (this->currClientSocketDescriptor != clientSocketDescriptor) {
            connect(this, SIGNAL(respond_to_client(int, QByteArray)), sender(), SLOT(receive_response(int, QByteArray)), Qt::QueuedConnection);
        }

//        emit respond_to_client(clientSocketDescriptor, *err);
        return;
    }

    connect(this, SIGNAL(respond_to_client(int, QByteArray)), sender(), SLOT(receive_response(int, QByteArray)), Qt::QueuedConnection);

    this->currClientSocketDescriptor = clientSocketDescriptor;
    this->roverComm->write(command);
    this->isBusy = true;
}

void RoverThread::add_emerg_connection(QTcpSocket *roverEmerg) {
    this->roverEmerg = roverEmerg;
    connect(this->roverEmerg, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    connect(this->roverEmerg, SIGNAL(disconnected()), this, SLOT(disconnect_rover()));
}

void RoverThread::disconnect_rover() {
    if (!this->isRunning()) {
        return;
    }

    this->roverComm->deleteLater();

    if (this->roverEmerg) {
        this->roverEmerg->deleteLater();
    }
    exit(0);
}
