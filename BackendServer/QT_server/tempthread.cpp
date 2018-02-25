#include "tempthread.h"

TempThread::TempThread(QTcpSocket *clientSocket, QTcpSocket *roverComm, QMutex *roverCommMutex, QJsonObject *data, QObject *parent) : QThread(parent) {
    this->clientSocket = clientSocket;
    this->roverComm = roverComm;
    this->roverCommMutex = roverCommMutex;
    this->isLocked = false;
    this->data = data;
}

void TempThread::run() {
    if (this->roverCommMutex->try_lock()) {
        this->isLocked = true;
        QJsonDocument *doc = new QJsonDocument(*this->data);
        QString *strJson = new QString(doc->toJson(QJsonDocument::Compact));

        this->roverComm->write(strJson->toStdString().c_str());

        connect(this->roverComm, SIGNAL(readyRead()), this, SLOT(analyze_response()));
        exec();
    } else {
        this->clientSocket->write("ERROR: rover busy");
        exit(0);
    }
}

void TempThread::analyze_response() {
    QByteArray buf;
    QJsonDocument document;

    buf = this->roverComm->readAll();
    document = QJsonDocument::fromJson(buf);

    if (document.isNull()) {
        this->clientSocket->write("ERROR: could not parse rover response");
    } else {
        QString strJson(document.toJson(QJsonDocument::Compact));
        this->clientSocket->write(strJson.toStdString().c_str());
    }

    this->roverCommMutex->unlock();
    this->isLocked = false;
    exit(0);
}

void TempThread::end() {
    if (this->isLocked) {
        this->roverCommMutex->unlock();
        this->isLocked = false;
    }
    exit(0);
}



