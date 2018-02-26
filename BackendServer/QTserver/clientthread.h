#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include "roverthread.h"

class ClientThread : public QThread {
    Q_OBJECT
public:
    explicit ClientThread(QTcpSocket *clientSocket, QObject *parent = nullptr);
    void run();
    void add_rover_connection(RoverThread *roverThread);
    void remove_rover_connection();

private:
    QTcpSocket *clientSocket;
    RoverThread *roverThread;
    bool isBusy;
    QString error(QString message);

signals:
    void send_command(int clientSocketDescriptor, QJsonObject command);

public slots:
    void read_and_send_command();
    void receive_response(int clientSocketDescriptor, QJsonObject response);
    void disconnect_client();
};

#endif // CLIENTTHREAD_H
