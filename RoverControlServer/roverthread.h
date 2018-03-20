#ifndef ROVERTHREAD_H
#define ROVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QMutex>

#include "../RoverSharedGlobals/rover_json.h"

class RoverThread : public QThread {
    Q_OBJECT
public:
    RoverThread(QObject *parent = nullptr);
    ~RoverThread();

    void run();
    bool connected();

    void add_connection(QTcpSocket *socket);

signals:
    void respond_to_client(int sock_fd, QByteArray res);
    void rover_ready(bool rdy);

public slots:
    void analyze_response();
    void disconnect_rover();
    void disconnect_controller();
    void receive_command(int clientSocketDescriptor, QByteArray command);

    void setup_socket();
    void cleanUp_socket();

private:
    QTcpSocket *roverComm;
    QTcpSocket *roverEmerg;

    int currClientSocketDescriptor;
    QMutex isControlled;
    QMutex isBusy;
    rover_modes mode;

    void emitState();
};

#endif // ROVERTHREAD_H
