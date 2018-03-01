#include "clientthread.h"

ClientThread::ClientThread(QTcpSocket *clientSocket, QObject *parent) : QThread(parent) {
    this->clientSocket = clientSocket;
    this->roverThread = nullptr;
    this->isBusy = false;
}

void ClientThread::run() {
    connect(this->clientSocket, SIGNAL(readyRead()), this, SLOT(read_and_send_command()));
    connect(this->clientSocket, SIGNAL(disconnected()), this, SLOT(disconnect_client()));
    exec();
}

void ClientThread::read_and_send_command() {
    QByteArray buf;
    buf = this->clientSocket->readAll();

    if (buf.isEmpty()) {
//        QString err = error("ERROR: not a valid command");
//        this->clientSocket->write(err.toStdString().c_str());
        return;
    }

    /*if (command.begin().key().toInt() == -1) {
        //EMERGENCY
    } else*/ if (!this->isBusy && this->roverThread && this->roverThread->isRunning()) {
        emit send_command(this->clientSocket->socketDescriptor(), buf);
        this->isBusy = true;
    } else {
        QString err = error("ERROR: rover busy or disconnected");

        this->clientSocket->write(buf);
    }
}

void ClientThread::receive_response(int clientSocketDescriptor, QByteArray response) {
    if (this->clientSocket->socketDescriptor() != clientSocketDescriptor) {
        return;
    }

    QString *strJson = new QString(response);

    this->clientSocket->write(strJson->toStdString().c_str());
    this->isBusy = false;

    disconnect(sender(), SIGNAL(respond_to_client(int, QByteArray)), this, SLOT(receive_response(int, QByteArray)));

    //update other clients if needed
}

void ClientThread::add_rover_connection(RoverThread *roverThread) {
    this->roverThread = roverThread;

    connect(this, SIGNAL(send_command(int, QByteArray)), this->roverThread,
            SLOT(receive_command(int, QByteArray)), Qt::QueuedConnection);
}

void ClientThread::remove_rover_connection() {
    disconnect(this, SIGNAL(send_command(int, QByteArray)), this->roverThread, SLOT(receive_command(int, QByteArray)));
    this->roverThread = nullptr;
    this->isBusy = false;
}

QString ClientThread::error(QString message) {
    return message + "\n";
}

void ClientThread::disconnect_client() {
    this->clientSocket->deleteLater();
    exit(0);
}

