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

// Sets log file location & text
void DataThread::setLogLoc(QString logLoc)
{
    logLocation = logLoc;
}

// Opens and starts recording data
void DataThread::start()
{
    if (logLocation.isEmpty()) return;

    uint32_t enumFlags = QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append;
    logFile = new QFile(logLocation);

    if (!logFile->open((QIODevice::OpenModeFlag) enumFlags)) return;
    logStream = new QTextStream(logFile);
    *logStream << "Server Online\n";
    logStream->flush();
}

void DataThread::terminate()
{
    // Write to log and close everything
    if (logStream != nullptr)
    {
        logStream->flush();
        delete logStream;
        logStream = nullptr;
    }

    if (logFile != nullptr)
    {
        logFile->close();
        delete logFile;
        logFile = nullptr;
    }
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
    if (clientSocketDescriptor != 0) return;

    if (logStream != nullptr)
    {
        for (auto i = data.begin(); i != data.end(); i++)
            *logStream << QString::number((char) (*i));

        logStream->flush();
    }
}
