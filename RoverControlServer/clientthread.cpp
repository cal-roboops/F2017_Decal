#include "clientthread.h"

ClientThread::ClientThread(QTcpSocket *clientSocket, bool roverReady, QObject *parent) :
    QThread(parent)
{
    this->clientSocket = clientSocket;
    this->roverReady = roverReady;
    this->isBusy = false;
}

void ClientThread::run()
{
    connect(this->clientSocket, SIGNAL(readyRead()), this, SLOT(read_and_send_command()));
    connect(this->clientSocket, SIGNAL(disconnected()), this, SLOT(disconnect_client()));
    exec();
}

void ClientThread::disconnect_client()
{
    this->clientSocket->deleteLater();
    exit(0);
}

void ClientThread::rover_ready(bool en)
{
    this->roverReady = en;
}

void ClientThread::read_and_send_command()
{
    QByteArray buf;
    buf = this->clientSocket->readAll();

    if (buf.isEmpty())
    {
//        QString err = error("ERROR: not a valid command");
//        this->clientSocket->write(err.toStdString().c_str());
        return;
    }

    /*if (command.begin().key().toInt() == -1)
     * {
        //EMERGENCY
    } else*/ if (!this->isBusy && this->roverReady)
    {
        emit send_command(this->clientSocket->socketDescriptor(), buf);
        this->isBusy = true;
    } else
    {
        QString err = error("ERROR: rover busy or disconnected");
        this->clientSocket->write(buf);
    }
}

void ClientThread::receive_response(int clientSocketDescriptor, QByteArray response)
{
    if (this->clientSocket->socketDescriptor() != clientSocketDescriptor)
    {
        return;
    }

    QString *strJson = new QString(response);

    this->clientSocket->write(strJson->toStdString().c_str());
    this->isBusy = false;

    disconnect(sender(), SIGNAL(respond_to_client(int, QByteArray)), this, SLOT(receive_response(int, QByteArray)));

    //update other clients if needed
}

QString ClientThread::error(QString message)
{
    return message + "\n";
}
