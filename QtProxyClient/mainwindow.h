#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "controlpanel.h"
#include "armgraphic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void send_data(QString data);
    void format_JSON(QJsonObject input);
    void uncheck_checkBox_show_cp();
private slots:
    void on_setDrawerValue_clicked();
    void drawerSliderChanged(int value);

    void on_connect_clicked();
    void on_disconnect_clicked();

    void on_recvMSG();
    void on_clearRECV_clicked();

    void on_openStream_clicked();

    void on_disconnect();

    void on_checkBox_show_cp_clicked();

    void on_radioButton_nc_mode_clicked();

    void on_radioButton_c_mode_clicked();

    // #################### ARM ####################

    // TODO: Declare arm buttons here

    // #############################################

    void on_armGraphic_clicked();

    void on_cameraMast_valueChanged(int position);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    ControlPanel c;
    ArmGraphic ag;
    bool disconnectPressed;
};

#endif // MAINWINDOW_H
