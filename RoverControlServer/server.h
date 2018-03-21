#ifndef SERVER_H
#define SERVER_H

#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

#include "datathread.h"
#include "clientthread.h"
#include "roverthread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);
    ~Server();

signals:
    void client_count_update(int val);
    void rover_connected(bool en);
    void server_on(bool on);

public slots:
    void start();
    void terminate();
    void server_exit();

    void remove_client();
    void update_client_count();
    void rover_ready(bool rdy);

private:
    DataThread *dataThread;

    QList<ClientThread*> clientThreads;
    RoverThread *roverThread;
    QHostAddress *roverIP;
    bool roverReady;

protected:
    void incomingConnection(qintptr socket_descriptor);
};

#endif // SERVER_H
