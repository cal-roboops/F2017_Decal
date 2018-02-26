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
    QJsonDocument document;
    QJsonObject command;

    buf = this->clientSocket->readAll();
    document = QJsonDocument::fromJson(buf);

    if (document.isNull()) {
        QString err = error("ERROR: not a valid command");

        this->clientSocket->write(err.toStdString().c_str());
        return;
    }

    command = document.object();

    /*if (command.begin().key().toInt() == -1) {
        //EMERGENCY
    } else*/ if (!this->isBusy && this->roverThread && this->roverThread->isRunning()) {
        emit send_command(this->clientSocket->socketDescriptor(), command);
        this->isBusy = true;
    } else {
        QString err = error("ERROR: rover busy or disconnected");

        this->clientSocket->write(err.toStdString().c_str());
    }
}

void ClientThread::receive_response(int clientSocketDescriptor, QJsonObject response) {
    if (this->clientSocket->socketDescriptor() != clientSocketDescriptor) {
        return;
    }

    QJsonDocument *doc = new QJsonDocument(response);
    QString *strJson = new QString(doc->toJson(QJsonDocument::Compact));

    this->clientSocket->write(strJson->toStdString().c_str());
    this->isBusy = false;

    disconnect(sender(), SIGNAL(respond_to_client(int, QJsonObject)), this, SLOT(receive_response(int, QJsonObject)));

    //update other clients if needed
}

void ClientThread::add_rover_connection(RoverThread *roverThread) {
    this->roverThread = roverThread;

    connect(this, SIGNAL(send_command(int, QJsonObject)), this->roverThread,
            SLOT(receive_command(int, QJsonObject)), Qt::QueuedConnection);
}

void ClientThread::remove_rover_connection() {
    disconnect(this, SIGNAL(send_command(int, QJsonObject)), this->roverThread, SLOT(receive_command(int, QJsonObject)));
    this->roverThread = nullptr;
    this->isBusy = false;
}

QString ClientThread::error(QString message) {
    QJsonObject *error = new QJsonObject();
    error->insert(message, -1);

    QJsonDocument *doc = new QJsonDocument(*error);
    QString *strJson = new QString(doc->toJson(QJsonDocument::Compact));

    return *strJson + "\n";
}

void ClientThread::disconnect_client() {
    this->clientSocket->deleteLater();
    exit(0);
}

