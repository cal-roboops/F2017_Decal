#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QTcpSocket>
#include <QTextStream>

class DataThread : public QThread {
    Q_OBJECT
public:
    DataThread(QObject *parent = nullptr);
    ~DataThread();

    void run();
    void setLogLoc(QString logLoc);

signals:
    void respond_to_client(int, QByteArray);

public slots:
    void start();
    void terminate();
    void receive_data(int clientSocketDescriptor, QByteArray data);
    void receive_command(int clientSocketDescriptor, QByteArray command);

private:
    int currClientSocketDescriptor;
    QString logLocation;
    QFile *logFile;
    QTextStream *logStream;
};

#endif // DATATHREAD_H
