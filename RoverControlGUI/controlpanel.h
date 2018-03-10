#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QMainWindow>

namespace Ui {
class ControlPanel;
}

class ControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    ControlPanel(QWidget *parent = 0);
    ~ControlPanel();

signals:
    void send_data(QByteArray data);

public slots:
    void enableDriveControl(bool en);
    void showDriveControl(bool en);

private slots:
    // Select drive mode
    void on_regularDrive_radio_clicked();
    void on_tankDrive_radio_clicked();
    void on_customDrive_radio_clicked();

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    // Regular Drive
    void on_regularServo_slider_valueChanged(int value);
    void on_regularServoSet_button_clicked();

    void on_regularDriveUp_button_pressed();
    void on_regularDriveUp_button_released();
    void on_regularDriveDown_button_pressed();
    void on_regularDriveDown_button_released();
    void on_regularDriveRight_button_clicked();
    void on_regularDriveLeft_button_clicked();

    // Tank Drive
    void on_tankServo0_radio_clicked();
    void on_tankServo45_radio_clicked();
    void on_tankServo90_radio_clicked();

    void on_tankUp_button_pressed();
    void on_tankUp_button_released();
    void on_tankDown_button_pressed();
    void on_tankDown_button_released();

    // Custom Drive
    void on_customServoSet_button_clicked();

    void on_customLeftUp_button_pressed();
    void on_customLeftUp_button_released();
    void on_customUpDown_button_pressed();
    void on_customUpDown_button_released();
    void on_customLeftDown_button_pressed();
    void on_customLeftDown_button_released();

    void on_customRightUp_button_pressed();
    void on_customRightUp_button_released();
    void on_customDownUp_button_pressed();
    void on_customDownUp_button_released();
    void on_customRightDown_button_pressed();
    void on_customRightDown_button_released();

    void on_customUpUp_button_pressed();
    void on_customUpUp_button_released();
    void on_customDownDown_button_pressed();
    void on_customDownDown_button_released();

    // Speed Setting
    void on_speedValue_slider_valueChanged(int x);
    void on_speedSubmit_button_clicked();
    void on_speed_setBtn_clicked();


private:
    Ui::ControlPanel *ui;

    void transmit_command(std::list<uint8_t> kv);
};

#endif // CONTROLPANEL_H
