#include "thread.h"

Thread::Thread(QTcpSocket *clientSocket, QTcpSocket *roverComm, QTcpSocket *roverEmerg, QMutex *roverCommMutex,
               QMutex *roverEmergMutex, QMutex *threadsMutex, QObject *parent) : QThread(parent) {
    this->clientSocket = clientSocket;
    this->roverComm = roverComm;
    this->roverEmerg = roverEmerg;
    this->socket_descriptor = clientSocket->socketDescriptor();
    this->roverCommMutex = roverCommMutex;
    this->roverEmergMutex = roverEmergMutex;
    this->threadsMutex = threadsMutex;
    this->tempThread = NULL;
}

void Thread::run() {
    connect(this->clientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(this->clientSocket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    exec();
}

void Thread::add_all_threads(QLinkedList<Thread*> *threads) {
    this->threads = threads;
}

void Thread::readyRead() {
    QByteArray buf;
    QJsonDocument document;
    QJsonObject jobj;
    QJsonObject tempData;

    buf = this->clientSocket->readAll();
    document = QJsonDocument::fromJson(buf);

    if (document.isNull()) {
        this->clientSocket->write("ERROR: not a valid JSON object\n");
        return;
    } else if (this->roverComm == NULL || this->roverEmerg == NULL) {
        this->clientSocket->write("ERROR: rover not connected\n");
        return;
    }

    jobj = document.object();

    if (jobj.begin().key().toInt() == -1) {
        this->roverEmergMutex->lock();
        QJsonDocument *doc = new QJsonDocument(jobj);
        QString *strJson = new QString(doc->toJson(QJsonDocument::Compact));
        this->roverEmerg->write(strJson->toStdString().c_str());

        this->roverEmergMutex->unlock();
    } else if (this->tempThread == NULL || this->tempThread->isFinished()){
        tempData = document.object();
        this->tempThread = new TempThread(this->clientSocket, this->roverComm, this->roverCommMutex, &tempData);

        connect(this->tempThread, SIGNAL(finished()), this->tempThread, SLOT(deleteLater()));
        this->tempThread->start();
    } else {
        this->clientSocket->write("ERROR: rover busy\n");
    }

}

void Thread::add_rover_sockets(QTcpSocket *roverComm, QTcpSocket *roverEmerg) {
    this->roverComm = roverComm;
    this->roverEmerg = roverEmerg;
}

void Thread::rover_disconnected() {
    if (this->tempThread != NULL && !this->tempThread->isFinished()) {
        this->tempThread->end();
    }
    this->roverComm = NULL;
    this->roverEmerg = NULL;
}

void Thread::disconnected() {
    this->threadsMutex->lock();

    QLinkedList<Thread*>::iterator i;

    for (i = this->threads->begin(); i != this->threads->end(); i++) {
        Thread *thread = *i;

        if (thread->get_socket_descriptor() == this->socket_descriptor) {
            this->threads->erase(i);
            break;
        }
    }

    if (this->tempThread != NULL && !this->tempThread->isFinished()) {
        this->tempThread->end();
    }

    this->clientSocket->deleteLater();
    this->threadsMutex->unlock();
    exit(0);
}

int Thread::get_socket_descriptor() {
    return this->socket_descriptor;
}
