#include "serverthread.h"

#include "../RoverSharedGlobals/rover_json.h"

ServerThread::ServerThread(QObject *parent) :
    QThread(parent)
{
}

ServerThread::~ServerThread()
{
}

void ServerThread::run()
{
    exec();
}

void ServerThread::analyze_response()
{
    QByteArray buf;

    if (!buf.isEmpty())
    {
        emit respond_to_client(this->currClientSocketDescriptor, buf);
    }
}

void ServerThread::receive_command(int clientSocketDescriptor, QByteArray command)
{
    connect(this, SIGNAL(respond_to_client(int, QByteArray)), sender(), SLOT(receive_response(int, QByteArray)), Qt::QueuedConnection);

    this->currClientSocketDescriptor = clientSocketDescriptor;
}
