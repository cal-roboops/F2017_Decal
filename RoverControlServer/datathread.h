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
    void receive_command(int clientSocketDescriptor, QByteArray command);
    void receive_data(QByteArray data);

private:
    int currClientSocketDescriptor;
};

#endif // DATATHREAD_H
