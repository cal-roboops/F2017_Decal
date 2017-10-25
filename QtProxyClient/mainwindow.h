#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_connect_clicked();
    void on_disconnect_clicked();

    void on_sendMSG_clicked();
    void on_recvMSG();
    void on_clearRECV_clicked();

    void on_openStream_clicked();

    void on_selectTestSuite_clicked();
    void on_runTestSuite_clicked();

    void on_disconnect();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    bool disconnectPressed;
};

#endif // MAINWINDOW_H
