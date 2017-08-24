#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTcpSocket>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void receive_data_over_network();

private slots:
    void on_button1_clicked();
    void on_submitData_clicked();
    void on_receive();

private:
    Ui::MainWindow *ui;
    QTextEdit *data;
    QTextEdit *receivedData;
    QUdpSocket *socket;
};

#endif // MAINWINDOW_H
