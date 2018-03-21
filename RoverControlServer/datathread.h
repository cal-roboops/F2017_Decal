#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class DataThread : public QThread {
    Q_OBJECT
public:
    DataThread(QObject *parent = nullptr);
    ~DataThread();

    void run();

signals:
    void respond_to_client(int, QByteArray);

public slots:
    void terminate();
    void receive_data(int clientSocketDescriptor, QByteArray data);
    void receive_command(int clientSocketDescriptor, QByteArray command);

private:
    int currClientSocketDescriptor;
};

#endif // DATATHREAD_H
