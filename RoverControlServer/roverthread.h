#ifndef ROVERTHREAD_H
#define ROVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class RoverThread : public QThread {
    Q_OBJECT
public:
    RoverThread(QObject *parent = nullptr);
    ~RoverThread();

    void run();
    bool commConnected();

    void add_comm_connection(QTcpSocket *roverComm);
    void add_emerg_connection(QTcpSocket *roverEmerg);

signals:
    void respond_to_client(int, QByteArray);
    void rover_ready(bool rdy);

public slots:
    void analyze_response();
    void disconnect_rover();
    void receive_command(int clientSocketDescriptor, QByteArray command);

private:
    QTcpSocket *roverComm;
    QTcpSocket *roverEmerg;
    int currClientSocketDescriptor;
    bool isBusy;
};

#endif // ROVERTHREAD_H
