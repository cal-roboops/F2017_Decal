#ifndef ROVERTHREAD_H
#define ROVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

class RoverThread : public QThread {
    Q_OBJECT
public:
    explicit RoverThread(QTcpSocket *roverComm, QObject *parent = nullptr);
    void add_emerg_connection(QTcpSocket *roverEmerg);
    void run();

private:
    QTcpSocket *roverComm;
    QTcpSocket *roverEmerg;
    int currClientSocketDescriptor;
    bool isBusy;

signals:
    void respond_to_client(int, QJsonObject);

public slots:
    void analyze_response();
    void disconnect_rover();
    void receive_command(int clientSocketDescriptor, QJsonObject command);
};

#endif // ROVERTHREAD_H
