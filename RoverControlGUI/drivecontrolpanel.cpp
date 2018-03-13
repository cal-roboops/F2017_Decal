#include "drivecontrolpanel.h"
#include "ui_drivecontrolpanel.h"

#include <QKeyEvent>
#include <QMessageBox>

#include "../RoverSharedGlobals/rover_json.h"

DriveControlPanel::DriveControlPanel(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::DriveControlPanel)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    enableDriveControl(false);
    ui->speed_lineEdit->setValidator(new QIntValidator(0, 100, this));
    ui->speed_lineEdit->setText("0");

    // Set Regular validator
    ui->regularServoValue_edit->setValidator(new QIntValidator(-45, 45, this));

    // Set custom validators
    ui->customServoLeftFront_edit->setValidator(new QIntValidator(-90, 90, this));
    ui->customServoLeftMiddle_edit->setValidator(new QIntValidator(-90, 90, this));
    ui->customServoLeftBack_edit->setValidator(new QIntValidator(-90, 90, this));
    ui->customServoRightFront_edit->setValidator(new QIntValidator(-90, 90, this));
    ui->customServoRightMiddle_edit->setValidator(new QIntValidator(-90, 90, this));
    ui->customServoRightBack_edit->setValidator(new QIntValidator(-90, 90, this));
}

DriveControlPanel::~DriveControlPanel()
{
    delete ui;
}

void DriveControlPanel::closeEvent(QCloseEvent *event)
{
    emit closed();
    event->accept();
}

void DriveControlPanel::enableDriveControl(bool en)
{
    this->setEnabled(en);
}

void DriveControlPanel::showDriveControl(bool en)
{
    if (en)
    {
        this->show();
    } else
    {
        this->hide();
    }
}

void DriveControlPanel::transmit_command(std::list<uint8_t> kv)
{
    emit send_data(kv);
}

/*
 * Radio Button Page Switchers
 * */

void DriveControlPanel::on_regularDrive_radio_clicked() //set controls to regular
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->regularServo_slider->setValue(0);
    ui->regularServoValue_edit->setText("0");

    transmit_command(Rover_JSON::zeroAll);
}

void DriveControlPanel::on_tankDrive_radio_clicked() //set controls to tank
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tankServo0_radio->setChecked(true);

    transmit_command(Rover_JSON::zeroAll);

}

void DriveControlPanel::on_customDrive_radio_clicked() //set controls to custom
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->customServoLeftFront_edit->setText("0");
    ui->customServoLeftMiddle_edit->setText("0");
    ui->customServoLeftBack_edit->setText("0");
    ui->customServoRightFront_edit->setText("0");
    ui->customServoRightMiddle_edit->setText("0");
    ui->customServoRightBack_edit->setText("0");

    transmit_command(Rover_JSON::zeroAll);
}

/*
 * Regular Page
 * */

void DriveControlPanel::on_regularServoValue_edit_textChanged(QString text)
{
    if (!text.isEmpty())
    {
        ui->regularServo_slider->setSliderPosition(text.toInt());
    }
}

void DriveControlPanel::on_regularServo_slider_valueChanged(int value)
{
    ui->regularServoValue_edit->setText(QString::number(value));
}

void DriveControlPanel::on_regularServoSubmit_button_clicked() //slider button
{
    int slider_value = ui->regularServoValue_edit->text().toInt();
    ui->regularServo_slider->setValue(slider_value);
    transmit_command({
                         rover_keys::DT_S_LF, (uint8_t) (servo_dirs::servo_zero + slider_value),
                         rover_keys::DT_S_RF, (uint8_t) (servo_dirs::servo_zero + slider_value)
                     });
}

void DriveControlPanel::on_regularDriveUp_button_pressed()
{
    transmit_command(Rover_JSON::forwardDrive);
}

void DriveControlPanel::on_regularDriveUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_regularDriveDown_button_pressed()
{
    transmit_command(Rover_JSON::backwardDrive);
}

void DriveControlPanel::on_regularDriveDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_regularDriveRight_button_clicked()
{
    int slider_value = ui->regularServo_slider->value() + 5;
    ui->regularServo_slider->setValue(slider_value);
    on_regularServoSubmit_button_clicked();
}

void DriveControlPanel::on_regularDriveLeft_button_clicked()
{
    int slider_value = ui->regularServo_slider->value() - 5;
    ui->regularServo_slider->setValue(slider_value);
    on_regularServoSubmit_button_clicked();
}

/*
 * Tank Page
 * */

void DriveControlPanel::on_tankServo0_radio_clicked()
{
    transmit_command(Rover_JSON::straightServo);
}

void DriveControlPanel::on_tankServo45_radio_clicked()
{
    transmit_command(Rover_JSON::spinCenterServo);
}

void DriveControlPanel::on_tankServo90_radio_clicked()
{
    transmit_command(Rover_JSON::sidewinderServo);
}

void DriveControlPanel::on_tankUp_button_pressed()
{
    transmit_command(Rover_JSON::forwardDrive);
}

void DriveControlPanel::on_tankUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_tankDown_button_pressed()
{
    transmit_command(Rover_JSON::backwardDrive);
}

void DriveControlPanel::on_tankDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

/*
 * Key Handlers
 * */

void DriveControlPanel::keyPressEvent(QKeyEvent * event)
{
    if (!event->isAutoRepeat()) {
        if(event-> key() == Qt::Key_W){
            DriveControlPanel::on_regularDriveUp_button_pressed();
        }
        else if(event-> key() == Qt::Key_S){
            DriveControlPanel::on_regularDriveDown_button_pressed();
        }
        else if(event-> key() == Qt::Key_D && ui->stackedWidget->currentIndex() == 0){ //enables D and A key only on regular page
            DriveControlPanel::on_regularDriveRight_button_clicked();
        }
        else if(event-> key() == Qt::Key_A && ui->stackedWidget->currentIndex() == 0){
            DriveControlPanel::on_regularDriveLeft_button_clicked();
        }
    }

}
void DriveControlPanel::keyReleaseEvent(QKeyEvent * event)
{
        if (event->isAutoRepeat()) {
            return;
        }
        else {
            if(event-> key() == Qt::Key_W){
                DriveControlPanel::on_regularDriveUp_button_released();
            }
            else if(event-> key() == Qt::Key_S){
                DriveControlPanel::on_regularDriveDown_button_released();
            }
        }
}

/*
 *
 * Custom Control Page
 *
 * */

void DriveControlPanel::on_customServoSubmit_button_clicked()
{
    QList<int> servo_values;
    servo_values.push_back(ui->customServoLeftFront_edit->text().toInt());
    servo_values.push_back(ui->customServoLeftMiddle_edit->text().toInt());
    servo_values.push_back(ui->customServoLeftBack_edit->text().toInt());
    servo_values.push_back(ui->customServoRightFront_edit->text().toInt());
    servo_values.push_back(ui->customServoRightMiddle_edit->text().toInt());
    servo_values.push_back(ui->customServoRightBack_edit->text().toInt());

    std::list<uint8_t> command;
    for (int i = 0; i < servo_values.length(); i++)
    {
        command.push_back(rover_keys::DT_S_LF + i);
        command.push_back(servo_dirs::servo_zero + servo_values[i]);
    }

    transmit_command(command);
}

void DriveControlPanel::on_customLeftUp_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_forward,
                         rover_keys::DT_M_RD, motor_dirs::motor_stop
                    });
}

void DriveControlPanel::on_customLeftUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customUpDown_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_forward,
                         rover_keys::DT_M_RD, motor_dirs::motor_backward
                    });
}

void DriveControlPanel::on_customUpDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customLeftDown_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_backward,
                         rover_keys::DT_M_RD, motor_dirs::motor_stop
                    });
}

void DriveControlPanel::on_customLeftDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customRightUp_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_stop,
                         rover_keys::DT_M_RD, motor_dirs::motor_forward
                    });
}

void DriveControlPanel::on_customRightUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customDownUp_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_backward,
                         rover_keys::DT_M_RD, motor_dirs::motor_forward
                    });
}

void DriveControlPanel::on_customDownUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customRightDown_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_stop,
                         rover_keys::DT_M_RD, motor_dirs::motor_backward
                    });
}

void DriveControlPanel::on_customRightDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customUpUp_button_pressed()
{
    transmit_command(Rover_JSON::forwardDrive);
}

void DriveControlPanel::on_customUpUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

void DriveControlPanel::on_customDownDown_button_pressed()
{
    transmit_command(Rover_JSON::backwardDrive);
}

void DriveControlPanel::on_customDownDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

/*
 *
 * Speed Setting
 *
 * */

void DriveControlPanel::on_speed_lineEdit_textChanged(QString text)
{
    if (!text.isEmpty())
    {
        ui->speedValue_label->setText(text);
        ui->speedValue_slider->setSliderPosition(text.toInt());
    }
}

void DriveControlPanel::on_speedValue_slider_valueChanged(int x)
{
    QString s = QString::number(x);
    ui->speedValue_label->setText(s);
    ui->speed_lineEdit->setText(s);
}

void DriveControlPanel::on_speedSubmit_button_clicked()
{
     int value = ui->speedValue_slider->value();

     transmit_command({
                          rover_keys::DT_M_Speed, (uint8_t) value
                     });
}
