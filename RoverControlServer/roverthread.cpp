#include "roverthread.h"

RoverThread::RoverThread(QObject *parent) :
    QThread(parent)
{
    this->roverComm = nullptr;
    this->roverEmerg = nullptr;
    this->isBusy = false;
}

RoverThread::~RoverThread()
{
    if (roverComm)
    {
        roverComm->disconnect();
        roverComm->deleteLater();
    }

    if (roverEmerg)
    {
        roverEmerg->disconnect();
        roverEmerg->deleteLater();
    }
}

void RoverThread::run()
{
    if (!roverComm || !roverEmerg) return;

    emit rover_ready(true);
    exec();
}

bool RoverThread::commConnected()
{
    return (roverComm != nullptr);
}

void RoverThread::add_emerg_connection(QTcpSocket *roverEmerg)
{
    this->roverEmerg = roverEmerg;

    connect(this->roverEmerg, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    connect(this->roverEmerg, SIGNAL(disconnected()), this, SLOT(disconnect_rover()));
}

void RoverThread::add_comm_connection(QTcpSocket *roverComm)
{
    this->roverComm = roverComm;
    connect(this->roverComm, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    connect(this->roverComm, SIGNAL(disconnected()), this, SLOT(disconnect_rover()));
}

void RoverThread::analyze_response()
{
    QByteArray buf;
    buf = this->roverComm->readAll();

    if (!buf.isEmpty())
    {
        emit respond_to_client(this->currClientSocketDescriptor, buf);
    }

    this->isBusy = false;
}

void RoverThread::receive_command(int clientSocketDescriptor, QByteArray command)
{
    if (this->isBusy)
    {
        if (this->currClientSocketDescriptor != clientSocketDescriptor)
        {
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

void RoverThread::disconnect_rover()
{
    if (!this->isRunning()) return;

    emit rover_ready(false);

    if (roverComm)
    {
        roverComm->disconnect();
        roverComm->deleteLater();
    }

    if (roverEmerg)
    {
        roverEmerg->disconnect();
        roverEmerg->deleteLater();
    }
}
