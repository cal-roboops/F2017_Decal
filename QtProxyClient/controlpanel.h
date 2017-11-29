#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include <QMainWindow>
#include <QTcpSocket>
#include "mainwindow.h"

namespace Ui {
class ControlPanel;
}

class ControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlPanel(MainWindow *mw, QWidget *parent = 0);
    ~ControlPanel();
    void send_data(QString data);
    void format_JSON(QJsonObject input);

private slots:

    void on_button_set_clicked();

    void on_pushButton_up_pressed();

    void on_pushButton_up_released();

    void on_radioButton_clicked();

    void on_radioButton_tank_clicked();

    void on_radioButton_custom_clicked();

    void on_radio0_clicked();
    void on_radio45_clicked();
    void on_radio90_clicked();

    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void on_tank_up_pressed();

    void on_tank_up_released();

    void on_tank_down_pressed();

    void on_tank_down_released();

    void on_pushButton_submit_clicked();

    void on_pushButton_down_pressed();

    void on_pushButton_down_released();

    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

    void on_button_submit_servo_clicked();

    void on_button_left_up_pressed();

    void on_button_left_up_released();

    void on_button_left_up_down_pressed();

    void on_button_left_up_down_released();

    void on_button_left_down_pressed();

    void on_button_left_down_released();

    void on_button_right_up_pressed();

    void on_button_right_up_released();

    void on_button_right_down_up_pressed();

    void on_button_right_down_up_released();

    void on_button_right_down_pressed();

    void on_button_right_down_released();

    void on_button_middle_up_up_pressed();

    void on_button_middle_up_up_released();

    void on_button_middle_down_down_pressed();

    void on_button_middle_down_down_released();

    void on_horizontalSlider_speed_sliderPressed();

    void on_horizontalSlider_speed_sliderReleased();

private:
    Ui::ControlPanel *ui;
    MainWindow *w;
};

#endif // CONTROLPANEL_H
