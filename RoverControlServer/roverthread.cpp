#include "roverthread.h"

#include "../RoverSharedGlobals/rover_json.h"

RoverThread::RoverThread(QObject *parent) :
    QThread(parent)
{
    this->roverComm = nullptr;
    this->roverEmerg = nullptr;
    this->currClientSocketDescriptor = 0;
    emitState();
}

RoverThread::~RoverThread()
{
    if (this->roverComm)
    {
        this->roverComm->disconnectFromHost();
        this->roverComm->deleteLater();
    }

    if (this->roverEmerg)
    {
        this->roverEmerg->disconnectFromHost();
        this->roverEmerg->deleteLater();
    }
}

// Start thread execution
void RoverThread::run()
{
    exec();
}

// Returns if the rover is fully connected
bool RoverThread::connected()
{
    return (this->roverComm && this->roverEmerg);
}

// Adds a potential connection to the rover thread (i.e. has rover IP)
void RoverThread::add_connection(QTcpSocket *socket)
{
    if (!this->roverComm || !this->roverEmerg)
    {
        connect(socket, SIGNAL(readyRead()), this, SLOT(setup_socket()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(cleanUp_socket()));
    }

    emitState();
}

// Parses data received from the rover and emits it to the correct party
void RoverThread::analyze_response()
{
    QByteArray buf;
    buf = this->roverComm->readAll();

    // buf not empty and busy mutex locked (add checks for response type here)
    if (!buf.isEmpty() && !this->isBusy.tryLock())
    {
        emit respond_to_client(this->currClientSocketDescriptor, buf);
        isBusy.tryLock();
        isBusy.unlock();
    }
}

// Disconnects the rover tcp connections
void RoverThread::disconnect_rover()
{
    if (this->roverComm) this->roverComm->disconnectFromHost();
    if (this->roverEmerg) this->roverEmerg->disconnectFromHost();

    disconnect_controller();

    emitState();
}

// Forcefully disconnect the controller thread
void RoverThread::disconnect_controller()
{
    this->currClientSocketDescriptor = 0;

    isControlled.tryLock();
    isControlled.unlock();
    isBusy.tryLock();
    isBusy.unlock();
}

// Gets a command from the client and passes it to the rover
void RoverThread::receive_command(int clientSocketDescriptor, QByteArray command)
{
    // Check valid JSON
    std::list<uint8_t> comm;
    for (auto i = command.cbegin(); i != command.cend(); i++)
    {
        comm.push_back((char) (*i));
    }
    if (!Rover_JSON::isValid(comm))
    {
        emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, command_status::invalid});
        return;
    }

    // Check if emergency command
    char key = (char) command[0];
    if ((command.length() == 2)
               && ((key == rover_keys::EMERGENCY_STOP)
                   || (key == rover_keys::SHUT_DOWN)))
    {
        this->roverEmerg->write(command);
    }

    // Verify controller thread & valid command
    if ((currClientSocketDescriptor != 0) && (currClientSocketDescriptor != clientSocketDescriptor))
    {
        emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, command_status::not_controller});
        return;
    }

    // Check if requested to be controller or to send message
    if ((command.length() == 2) && (key == rover_keys::TAKE_CONTROL))
    {
        char value = (char) command[1];
        if ((value == rover_modes::drive) || (value == rover_modes::arm))
        {
            if (isControlled.tryLock())
            {
                emit respond_to_client(clientSocketDescriptor, command);
                this->currClientSocketDescriptor = clientSocketDescriptor;
                this->mode = (rover_modes) (char) command[1];
                return;
            } else
            {
                emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, command_status::failed});
                return;
            }
        } else if ((value == rover_modes::none)
                   && (this->currClientSocketDescriptor == clientSocketDescriptor))
        {
            emit respond_to_client(clientSocketDescriptor, command);
            this->currClientSocketDescriptor = 0;
            isControlled.tryLock();
            isControlled.unlock();
            return;
        } else
        {
            emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, command_status::not_controller});
            return;
        }
    } else if (currClientSocketDescriptor == clientSocketDescriptor)
    {
        if (this->isBusy.tryLock())
        {
            this->roverComm->write(command);
        } else
        {
            emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, command_status::busy});
            return;
        }
    } else
    {
        emit respond_to_client(clientSocketDescriptor, {rover_keys::COMMAND_STATUS, command_status::not_controller});
        return;
    }
}

// Setup rover socket when first data recieved
void RoverThread::setup_socket()
{
    QByteArray buf;
    QTcpSocket *socket = (QTcpSocket*) sender();
    buf = socket->readAll();

    if ((buf.length() != 2) || (((char) buf[1]) != 1)) return;

    char key = (char) buf[0];
    bool success = false;
    if ((key == rover_keys::COMM_CONN) && !this->roverComm)
    {
        success = true;
        this->roverComm = socket;
        qDebug() << "Rover Comm Connected";
    } else if ((key == rover_keys::EMERG_CONN) && !this->roverEmerg)
    {
        success = true;
        this->roverEmerg = socket;
        qDebug() << "Rover Emerg Connected";
    } else if (this->roverComm && this->roverEmerg)
    {
        success = false;
        socket->disconnectFromHost();
        qDebug() << "Connection(s) already establised!";
    } else
    {
        success = false;
        qDebug() << "JSON Key error!";
    }

    if (success)
    {
        disconnect(socket, SIGNAL(readyRead()), this, SLOT(setup_socket()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    }

    emitState();
}

// Remove and clean stored socket data
void RoverThread::cleanUp_socket()
{
    QTcpSocket *socket = (QTcpSocket*) sender();
    socket->deleteLater();

    if (socket == this->roverComm)
    {
        this->roverComm = nullptr;
        qDebug() << "Rover Comm Disconnected";
    }
    else if (socket == this->roverEmerg)
    {
        this->roverEmerg = nullptr;
        qDebug() << "Rover Emerg Disconnected";
    }

    emitState();
}

// Send update about rover connection state
void RoverThread::emitState()
{
    if (this->roverComm && this->roverEmerg) emit rover_ready(true);
    else emit rover_ready(false);
}
