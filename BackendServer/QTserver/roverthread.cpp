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
    QJsonDocument document;
    QJsonObject response;

    buf = this->roverComm->readAll();
    document = QJsonDocument::fromJson(buf);

    if (document.isNull()) {
        //error
    } else {
        response = document.object();
        emit respond_to_client(this->currClientSocketDescriptor, response);
    }
    this->isBusy = false;
}

void RoverThread::receive_command(int clientSocketDescriptor, QJsonObject command) {
    if (this->isBusy) {
        QJsonObject *err = new QJsonObject();
        err->insert("ERROR: rover busy", -1);

        if (this->currClientSocketDescriptor != clientSocketDescriptor) {
            connect(this, SIGNAL(respond_to_client(int, QJsonObject)), sender(), SLOT(receive_response(int, QJsonObject)), Qt::QueuedConnection);
        }

        emit respond_to_client(clientSocketDescriptor, *err);
        return;
    }

    QJsonDocument *doc = new QJsonDocument(command);
    QString *strJson = new QString(doc->toJson(QJsonDocument::Compact));

    connect(this, SIGNAL(respond_to_client(int, QJsonObject)), sender(), SLOT(receive_response(int, QJsonObject)), Qt::QueuedConnection);

    this->currClientSocketDescriptor = clientSocketDescriptor;
    this->roverComm->write(strJson->toStdString().c_str());
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
