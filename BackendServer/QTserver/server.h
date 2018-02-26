#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLinkedList>
#include <QLCDNumber>
#include <QProgressBar>
#include <QHostAddress>
#include <QMutex>
#include <QDebug>

#include "clientthread.h"
#include "roverthread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QLCDNumber *client_count, QProgressBar *roverConnected, QObject *parent = nullptr);
    void start();
    void terminate();

signals:

public slots:
    void update_client_count();
    void remove_client();
    void rover_disconnected();

private:
    QLinkedList<ClientThread*> clientThreads;
    RoverThread *roverThread;
    QLCDNumber *client_count;
    QProgressBar *roverConnected;
    QHostAddress *roverIP;



protected:
    void incomingConnection(qintptr socket_descriptor);
};

#endif // SERVER_H
