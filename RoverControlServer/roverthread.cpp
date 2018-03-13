#include "roverthread.h"

#include "../RoverSharedGlobals/rover_json.h"

RoverThread::RoverThread(QObject *parent) :
    QThread(parent)
{
    this->roverComm = nullptr;
    this->roverEmerg = nullptr;
    this->isBusy = false;
    this->currClientSocketDescriptor = 0;
    emitState();
}

RoverThread::~RoverThread()
{
    if (this->roverComm)
    {
        this->roverComm->disconnect();
        this->roverComm->deleteLater();
    }

    if (this->roverEmerg)
    {
        this->roverEmerg->disconnect();
        this->roverEmerg->deleteLater();
    }
}

void RoverThread::run()
{
    exec();
}

bool RoverThread::connected()
{
    return (this->roverComm && this->roverEmerg);
}

void RoverThread::add_connection(QTcpSocket *socket)
{
    if (!this->roverComm || !this->roverEmerg)
    {
        connect(socket, SIGNAL(readyRead()), this, SLOT(setup_socket()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(cleanUp_socket()));
    }

    emitState();
}

void RoverThread::analyze_response()
{
    QByteArray buf;
    buf = this->roverComm->readAll();

    if (!buf.isEmpty())
    {
        emit respond_to_client(this->currClientSocketDescriptor, buf);
    }

    this->currClientSocketDescriptor = 0;
    this->isBusy = false;
}

void RoverThread::disconnect_rover()
{
    if (this->roverComm) this->roverComm->disconnect();
    if (this->roverEmerg) this->roverEmerg->disconnect();

    emitState();
}

void RoverThread::receive_command(int clientSocketDescriptor, QByteArray command)
{
    if (this->isBusy)
    {
        emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, 2});
        return;
    }

    this->isBusy = true;
    this->currClientSocketDescriptor = clientSocketDescriptor;
    connect(this, SIGNAL(respond_to_client(int, QByteArray)), sender(), SLOT(receive_response(int, QByteArray)));

    this->roverComm->write(command);
}

void RoverThread::setup_socket()
{
    QByteArray buf;
    QTcpSocket *socket = (QTcpSocket*) sender();
    buf = socket->readAll();

    if ((buf.size() != 2) || (buf[1] != 1)) return;

    bool success = false;
    if ((buf[0] == rover_keys::COMM_CONN) && !this->roverComm)
    {
        success = true;
        this->roverComm = socket;
        qDebug() << "Rover Comm Connected";
    } else if ((buf[0] == rover_keys::EMERG_CONN) && !this->roverEmerg)
    {
        success = true;
        this->roverEmerg = socket;
        qDebug() << "Rover Emerg Connected";
    } else
    {
        success = false;
        qDebug() << "Rover has command and emergency connections";
    }

    if (success)
    {
        disconnect(socket, SIGNAL(readyRead()), this, SLOT(setup_tempSocket()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    }

    emitState();
}

void RoverThread::cleanUp_socket()
{
    QTcpSocket *socket = (QTcpSocket*) sender();
    socket->deleteLater();

    if (socket == this->roverComm) this->roverComm = nullptr;
    else if (socket == this->roverEmerg) this->roverEmerg = nullptr;

    emitState();
}

void RoverThread::emitState()
{
    if (this->roverComm && this->roverEmerg) emit rover_ready(true);
    else emit rover_ready(false);
}
