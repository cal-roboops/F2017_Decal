#include "clientthread.h"

#include "../RoverSharedGlobals/rover_json.h"

ClientThread::ClientThread(QTcpSocket *clientSocket, bool roverReady, QObject *parent) :
    QThread(parent)
{
    this->threadSocketDescriptor = clientSocket->socketDescriptor();
    this->clientSocket = clientSocket;
    this->roverReady = roverReady;
}

void ClientThread::run()
{
    connect(this->clientSocket, SIGNAL(readyRead()), this, SLOT(read_and_send_command()));
    connect(this->clientSocket, SIGNAL(disconnected()), this, SLOT(disconnect_client()));
    exec();
}

void ClientThread::disconnect_client()
{
    QByteArray close_ctrl;
    close_ctrl.append((char) rover_keys::TAKE_CONTROL);
    close_ctrl.append((char) rover_modes::no_mode);
    emit send_command(this->threadSocketDescriptor, close_ctrl);

    if (this->clientSocket->state() == QTcpSocket::ConnectedState)
    {
        this->clientSocket->disconnectFromHost();
    }

    this->exit();
}

void ClientThread::rover_ready(bool en)
{
    this->roverReady = en;
}

void ClientThread::read_and_send_command()
{
    QByteArray buf;
    buf = this->clientSocket->readAll();

    std::list<uint8_t> comm;
    comm.insert(comm.end(), buf.begin(), buf.end());
    if (!Rover_JSON::isValid(comm)) return;

    if (this->roverReady)
    {
        emit send_command(this->threadSocketDescriptor, buf);
    } else
    {
        QByteArray err;
        err.append((char) rover_keys::COMMAND_STATUS);
        err.append((char) command_status::rover_not_ready);
        this->clientSocket->write(err);
    }
}

void ClientThread::receive_response(int clientSocketDescriptor, QByteArray response)
{
    if ((clientSocketDescriptor != 0) && (this->threadSocketDescriptor != clientSocketDescriptor))
    {
        return;
    }

    this->clientSocket->write(response);
}
