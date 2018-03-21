#include "datathread.h"

#include "../RoverSharedGlobals/rover_json.h"

DataThread::DataThread(QObject *parent) :
    QThread(parent)
{
}

DataThread::~DataThread()
{
}

// Start thread execution
void DataThread::run()
{
    exec();
}

void DataThread::terminate()
{
    // Write to log and close everything
}

// Analyze and respond to each request
void DataThread::receive_command(int clientSocketDescriptor, QByteArray command)
{
    connect(this, SIGNAL(respond_to_client(int, QByteArray)), sender(), SLOT(receive_response(int, QByteArray)), Qt::QueuedConnection);

    this->currClientSocketDescriptor = clientSocketDescriptor;
}

// Parse and log the recieved data
void DataThread::receive_data(int clientSocketDescriptor, QByteArray data)
{
    // Parse and log data here
}
