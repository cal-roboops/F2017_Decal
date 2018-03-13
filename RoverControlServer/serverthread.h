#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class ServerThread : public QThread {
    Q_OBJECT
public:
    ServerThread(QObject *parent = nullptr);
    ~ServerThread();

    void run();

signals:
    void respond_to_client(int, QByteArray);
    void rover_ready(bool rdy);

public slots:
    void analyze_response();
    void receive_command(int clientSocketDescriptor, QByteArray command);

private:
    int currClientSocketDescriptor;
};

#endif // SERVERTHREAD_H
