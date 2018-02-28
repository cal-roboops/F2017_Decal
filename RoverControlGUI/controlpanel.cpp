#include "controlpanel.h"
#include "ui_controlpanel.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

#include "../RoverSharedGlobals/rover_json.h"

ControlPanel::ControlPanel(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    enableDriveControl(false);
}

ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::enableDriveControl(bool en)
{
    this->setEnabled(en);
}

void ControlPanel::showDriveControl(bool en)
{
    if (en)
    {
        this->show();
    } else
    {
        this->hide();
    }
}

void ControlPanel::transmit_command(QString kv)
{
    emit send_data(kv);
}

void ControlPanel::transmit_command(std::initializer_list<std::pair<uint8_t, uint8_t>> kv)
{
    char* jsonSTR = Rover_JSON::make_json(kv);
    emit send_data(QString(jsonSTR));
    delete jsonSTR;
}

/*
 * Radio Button Page Switchers
 * */

void ControlPanel::on_regularDrive_radio_clicked() //set controls to regular
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->regularServo_slider->setValue(0);

    transmit_command(QString(Rover_JSON::zeroAll));
}

void ControlPanel::on_tankDrive_radio_clicked() //set controls to tank
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tankServo0_radio->setChecked(true);

    transmit_command(QString(Rover_JSON::zeroAll));

}

void ControlPanel::on_customDrive_radio_clicked() //set controls to custom
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->customServoLeftFront_edit->setText("0");
    ui->customServoLeftMiddle_edit->setText("0");
    ui->customServoLeftBack_edit->setText("0");
    ui->customServoRightFront_edit->setText("0");
    ui->customServoRightMiddle_edit->setText("0");
    ui->customServoRightBack_edit->setText("0");

    transmit_command(QString(Rover_JSON::zeroAll));
}

/*
 * Regular Page
 * */

void ControlPanel::on_regularServo_slider_valueChanged(int value)
{
    ui->regularServoValue_edit->setText(QString::number(value));
}

void ControlPanel::on_regularServoSet_button_clicked() //slider button
{
    int slider_value = ui->regularServoValue_edit->text().toInt();
    ui->regularServo_slider->setValue(slider_value);

    transmit_command({
                         {rover_keys::DT_S_LF, slider_value},
                         {rover_keys::DT_S_RF, slider_value}
                     });
}

void ControlPanel::on_regularDriveUp_button_pressed()
{
    transmit_command(QString(Rover_JSON::forwardDrive));
}

void ControlPanel::on_regularDriveUp_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_regularDriveDown_button_pressed()
{
    transmit_command(QString(Rover_JSON::backwardDrive));
}

void ControlPanel::on_regularDriveDown_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_regularDriveRight_button_clicked()
{
    int slider_value = ui->regularServo_slider->value() + 5;
    ui->regularServo_slider->setValue(slider_value);
    on_regularServoSet_button_clicked();
}

void ControlPanel::on_regularDriveLeft_button_clicked()
{
    int slider_value = ui->regularServo_slider->value() - 5;
    ui->regularServo_slider->setValue(slider_value);
    on_regularServoSet_button_clicked();
}

/*
 * Tank Page
 * */

void ControlPanel::on_tankServo0_radio_clicked()
{
    transmit_command(QString(Rover_JSON::zeroServo));
}
void ControlPanel::on_tankServo45_radio_clicked()
{
    transmit_command(QString(Rover_JSON::fourfiveServo));
}
void ControlPanel::on_tankServo90_radio_clicked()
{
    transmit_command(QString(Rover_JSON::ninezeroServo));
}


void ControlPanel::on_tankUp_button_pressed()
{
    transmit_command(QString(Rover_JSON::forwardDrive));
}

void ControlPanel::on_tankUp_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_tankDown_button_pressed()
{
    transmit_command(QString(Rover_JSON::motor_backward));
}

void ControlPanel::on_tankDown_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}


/*
 * Key Handlers
 * */

void ControlPanel::keyPressEvent(QKeyEvent * event)
{
    if (!event->isAutoRepeat()) {
        if(event-> key() == Qt::Key_W){
            ControlPanel::on_regularDriveUp_button_pressed();
        }
        else if(event-> key() == Qt::Key_S){
            ControlPanel::on_regularDriveDown_button_pressed();
        }
        else if(event-> key() == Qt::Key_D && ui->stackedWidget->currentIndex() == 0){ //enables D and A key only on regular page
            ControlPanel::on_regularDriveRight_button_clicked();
        }
        else if(event-> key() == Qt::Key_A && ui->stackedWidget->currentIndex() == 0){
            ControlPanel::on_regularDriveLeft_button_clicked();
        }
    }

}
void ControlPanel::keyReleaseEvent(QKeyEvent * event)
{
        if (event->isAutoRepeat()) {
            return;
        }
        else {
            if(event-> key() == Qt::Key_W){
                ControlPanel::on_regularDriveUp_button_released();
            }
            else if(event-> key() == Qt::Key_S){
                ControlPanel::on_regularDriveDown_button_released();
            }
        }
}

/*
 *
 * Custom Control Page
 *
 * */

void ControlPanel::on_customServoSet_button_clicked()
{
    int tb1 = ui->customServoLeftFront_edit->toPlainText().toInt();
    int tb2 = ui->customServoLeftMiddle_edit->toPlainText().toInt();
    int tb3 = ui->customServoLeftBack_edit->toPlainText().toInt();
    int tb4 = ui->customServoRightFront_edit->toPlainText().toInt();
    int tb5 = ui->customServoRightMiddle_edit->toPlainText().toInt();
    int tb6 = ui->customServoRightBack_edit->toPlainText().toInt();

    if (tb1 > 90 || tb1 < -90 || tb2 > 90 || tb2 < -90 || tb3 > 90 || tb3 < -90 || tb4 > 90 || tb4 < -90 || tb5 > 90 || tb5 <- 90 || tb6 > 90 || tb6 < -90){
        qDebug() << "Values need to be within the range: [-90, 90]";
    }
    else{
        transmit_command({
                             {rover_keys::DT_S_LF, tb1},
                             {rover_keys::DT_S_LM, tb2},
                             {rover_keys::DT_S_LB, tb3},

                             {rover_keys::DT_S_RF, tb4},
                             {rover_keys::DT_S_RM, tb5},
                             {rover_keys::DT_S_RB, tb6}
                        });
    }
}

void ControlPanel::on_customLeftUp_button_pressed()
{
    transmit_command({
                         {rover_keys::DT_M_LD, Rover_JSON::motor_forward},
                         {rover_keys::DT_M_RD, Rover_JSON::motor_stop}
                    });
}

void ControlPanel::on_customLeftUp_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customUpDown_button_pressed()
{
    transmit_command({
                         {rover_keys::DT_M_LD, Rover_JSON::motor_forward},
                         {rover_keys::DT_M_RD, Rover_JSON::motor_backward}
                    });
}

void ControlPanel::on_customUpDown_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customLeftDown_button_pressed()
{
    transmit_command({
                         {rover_keys::DT_M_LD, Rover_JSON::motor_backward},
                         {rover_keys::DT_M_RD, Rover_JSON::motor_stop}
                    });
}

void ControlPanel::on_customLeftDown_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customRightUp_button_pressed()
{
    transmit_command({
                         {rover_keys::DT_M_LD, Rover_JSON::motor_stop},
                         {rover_keys::DT_M_RD, Rover_JSON::motor_forward}
                    });
}

void ControlPanel::on_customRightUp_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customDownUp_button_pressed()
{
    transmit_command({
                         {rover_keys::DT_M_LD, Rover_JSON::motor_backward},
                         {rover_keys::DT_M_RD, Rover_JSON::motor_forward}
                    });
}

void ControlPanel::on_customDownUp_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customRightDown_button_pressed()
{
    transmit_command({
                         {rover_keys::DT_M_LD, Rover_JSON::motor_stop},
                         {rover_keys::DT_M_RD, Rover_JSON::motor_backward}
                    });
}

void ControlPanel::on_customRightDown_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customUpUp_button_pressed()
{
    transmit_command(QString(Rover_JSON::motor_forward));
}

void ControlPanel::on_customUpUp_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

void ControlPanel::on_customDownDown_button_pressed()
{
    transmit_command(QString(Rover_JSON::motor_backward));
}

void ControlPanel::on_customDownDown_button_released()
{
    transmit_command(QString(Rover_JSON::stopDrive));
}

/*
 *
 * Speed Setting
 *
 * */

void ControlPanel::on_speedValue_slider_sliderPressed() //updates speed slider label
{
    int x = ui->speedValue_slider->value();
    QString s = QString::number(x);
    ui->speedValue_label->setText(s);
}

void ControlPanel::on_speedValue_slider_sliderReleased()
{
    int x = ui->speedValue_slider->value();
    QString s = QString::number(x);
    ui->speedValue_label->setText(s);
}

void ControlPanel::on_speedSubmit_button_clicked()
{
     int value = ui->speedValue_slider->value();

     transmit_command({
                          {rover_keys::DT_M_Speed, value}
                     });
}
