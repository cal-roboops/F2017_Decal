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
    void setup_network();
    void setup_slider();
    //void detectTextBox();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_sendMSG_clicked();
    void on_recvMSG();
    void on_clearRECV_clicked();
    void on_webcam_clicked();
    void on_slider();
    //void on_textboxes();

private:
    Ui::MainWindow *ui;
    QUdpSocket *socket;
};

#endif // MAINWINDOW_H
