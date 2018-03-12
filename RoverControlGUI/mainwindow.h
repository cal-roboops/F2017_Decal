#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void enableDriveControl(bool en);
    void showDriveControl(bool en);

    void enableArmControl(bool en);
    void showArmControl(bool en);

public slots:
    void send_data(std::list<uint8_t> data);

private slots:
    void on_connect_clicked();
    void on_disconnect_clicked();

    void on_recvMSG();
    void on_clearRECV_clicked();

    void on_openStream_clicked();
    void on_disconnect();

    void on_showDriveControl_Check_clicked();
    void on_driveMode_Control_Radio_clicked();
    void on_driveMode_NonControl_Radio_clicked();

    void on_showArmControl_Check_clicked();
    void on_armMode_Control_Radio_clicked();
    void on_armMode_NonControl_Radio_clicked();

    // #################### ARM ####################

    // TODO: Declare arm buttons here

    // #############################################

    void on_cameraMast_dial_valueChanged(int position);
    void on_camera_LineEdit_textChanged(QString text);
    void on_cameraSubmitBtn_clicked();

    void on_drawerValue_slider_valueChanged(int x);
    void on_drawer_LineEdit_textChanged(QString text);
    void on_drawerSubmitBtn_clicked();

    void on_shutdownBtn_clicked();
    void on_eStopButton_clicked();

private:
    Ui::MainWindow *ui;

    QTcpSocket *socket;
    bool disconnectPressed;
};

#endif // MAINWINDOW_H
