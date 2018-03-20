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
    QByteArray resp;

    // Check valid JSON
    std::list<uint8_t> comm;
    for (auto i = command.cbegin(); i != command.cend(); i++)
    {
        comm.push_back((char) (*i));
    }
    if (!Rover_JSON::isValid(comm))
    {
        resp.append((char) rover_keys::COMMAND_STATUS);
        resp.append((char) command_status::invalid);
        emit respond_to_client(clientSocketDescriptor, resp);
        return;
    }

    // Check if emergency command
    char key = (char) command[0];
    switch (key)
    {
        case rover_keys::EMERGENCY_STOP:
        case rover_keys::SHUT_DOWN:
            this->roverEmerg->write(command);
            return;
    }

    // Verify controller thread & valid command
    if ((currClientSocketDescriptor != 0) && (currClientSocketDescriptor != clientSocketDescriptor))
    {
        resp.append((char) rover_keys::COMMAND_STATUS);
        resp.append((char) command_status::not_controller);
        emit respond_to_client(clientSocketDescriptor, resp);
        return;
    }

    // Check if request to be controller or to send message
    char value = (char) command[1];
    switch (key)
    {
        case rover_keys::TAKE_CONTROL:
            resp.append(key);
            switch (value)
            {
                case rover_modes::mode_1:
                case rover_modes::mode_2:
                    if (isControlled.tryLock())
                    {
                        resp.append(value+1);
                        currClientSocketDescriptor = clientSocketDescriptor;
                    } else
                    {
                        resp.append(value+2);
                    }
                    break;
                case rover_modes::no_mode:
                    if (currClientSocketDescriptor == clientSocketDescriptor)
                    {
                        resp.append(value);
                        currClientSocketDescriptor = 0;
                        isControlled.tryLock();
                        isControlled.unlock();
                    }
                    break;
                default:
                    resp.append(value);
                    break;
            }
            break;
        default:
            resp.append((char) rover_keys::COMMAND_STATUS);
            if (isBusy.tryLock())
            {
                roverComm->write(command);
                resp.append((char) command_status::sent);
            } else
            {
                resp.append((char) command_status::busy);
            }
            break;
    }

    emit respond_to_client(clientSocketDescriptor, resp);
}

// Setup rover socket when first data recieved
void RoverThread::setup_socket()
{
    QByteArray buf;
    QTcpSocket *socket = (QTcpSocket*) sender();
    buf = socket->readAll();

    std::list<uint8_t> comm;
    for (auto i = buf.cbegin(); i != buf.cend(); i++)
    {
        comm.push_back((char) (*i));
    }
    if (!Rover_JSON::isValid(comm)) return;

    bool success = false;
    char key = (char) buf[0];
    char value = (char) buf[1];
    switch (key)
    {
        case rover_keys::COMM_CONN:
            if (!this->roverComm && (value == command_status::connect))
            {
                success = true;
                this->roverComm = socket;
                qDebug() << "Rover Comm Connected";
            }
            break;
        case rover_keys::EMERG_CONN:
            if (!this->roverEmerg && (value == command_status::connect))
            {
                success = true;
                this->roverEmerg = socket;
                qDebug() << "Rover Emerg Connected";
            }
            break;
    }

    QByteArray resp;
    resp.append(key);
    if (success)
    {
        resp.append((char) command_status::success);
        disconnect(socket, SIGNAL(readyRead()), this, SLOT(setup_socket()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(analyze_response()));
    } else if (this->roverComm && this->roverEmerg)
    {
        success = false;
        socket->disconnectFromHost();
        resp.append((char) command_status::already_connected);
        qDebug() << "Connection(s) already establised!";
    } else
    {
        resp.append((char) command_status::invalid);
        qDebug() << "Rover JSON Key error!";
    }

    socket->write(resp);
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
