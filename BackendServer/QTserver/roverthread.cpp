#include "roverthread.h"
#include <QDebug>

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
        emit respond_to_client(response);
    }
    this->isBusy = false;
    this->currClient = nullptr;
}

void RoverThread::receive_command(QJsonObject command) {
    if (this->isBusy) {
        QJsonObject *err = new QJsonObject();
        err->insert("ERROR: rover busy", -1);

        connect(this, SIGNAL(respond_to_client(QJsonObject)), sender(), SLOT(receive_response(QJsonObject)), Qt::QueuedConnection);
        emit respond_to_client(*err);

        return;
    }


    QJsonDocument *doc = new QJsonDocument(command);
    QString *strJson = new QString(doc->toJson(QJsonDocument::Compact));

    connect(this, SIGNAL(respond_to_client(QJsonObject)), sender(), SLOT(receive_response(QJsonObject)), Qt::QueuedConnection);

    this->currClient = sender();
    this->roverComm->write(strJson->toStdString().c_str());
    this->isBusy = true;
}

void RoverThread::add_emerg_connection(QTcpSocket *roverEmerg) {
    this->roverEmerg = roverEmerg;
    connect(this->roverEmerg, SIGNAL(readyRead()), this, SLOT(analyze_response()));
}

void RoverThread::disconnect_rover() {
    this->roverComm->deleteLater();

    if (this->roverEmerg) {
        this->roverEmerg->deleteLater();
    }
    exit(0);
}
