#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include "roverthread.h"

class ClientThread : public QThread {
    Q_OBJECT
public:
    explicit ClientThread(QTcpSocket *clientSocket, bool roverReady, QObject *parent = nullptr);
    void run();

signals:
    void send_command(int clientSocketDescriptor, QByteArray command);

public slots:
    void disconnect_client();
    void rover_ready(bool en);
    void read_and_send_command();

    void receive_response(int clientSocketDescriptor, QByteArray response);

private:
    bool isBusy;
    bool roverReady;
    QTcpSocket *clientSocket;
    QString error(QString message);
};

#endif // CLIENTTHREAD_H
