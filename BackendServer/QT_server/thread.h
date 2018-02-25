#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QLinkedList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostAddress>
#include <QMutex>
#include <QDebug>

#include "tempthread.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QTcpSocket *clientSocket, QTcpSocket *roverComm, QTcpSocket *roverEmerg, QMutex *roverCommMutex,
                    QMutex *roverEmergMutex, QMutex *threadsMutex, QObject *parent = nullptr);
    void run();
    void add_all_threads(QLinkedList<Thread*> *threads);
    void add_rover_sockets(QTcpSocket *roverComm, QTcpSocket *roverEmerg);
    void rover_disconnected();
    int get_socket_descriptor();

signals:

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *clientSocket;
    QTcpSocket *roverComm;
    QTcpSocket *roverEmerg;
    QMutex *roverCommMutex;
    QMutex *roverEmergMutex;
    QMutex *threadsMutex;
    QLinkedList<Thread*> *threads;
    QHostAddress *roverIP;
    TempThread *tempThread;
    int socket_descriptor;
};

#endif // THREAD_H
