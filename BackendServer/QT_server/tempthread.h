#ifndef TEMPTHREAD_H
#define TEMPTHREAD_H

#include <QObject>
#include <QThread>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QMutex>

class TempThread : public QThread {
    Q_OBJECT
public:
    explicit TempThread(QTcpSocket *clientSocket, QTcpSocket *roverComm, QMutex *roverCommMutex, QJsonObject *data, QObject *parent = nullptr);
    void run();
    void end();

private:
    QTcpSocket *clientSocket;
    QTcpSocket *roverComm;
    QMutex *roverCommMutex;
    bool isLocked;
    QJsonObject *data;

signals:

public slots:
    void analyze_response();
};

#endif // TEMPTHREAD_H
