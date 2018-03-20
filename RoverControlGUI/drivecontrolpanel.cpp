#include "drivecontrolpanel.h"
#include "ui_drivecontrolpanel.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

#include "../RoverSharedGlobals/rover_json.h"

DriveControlPanel::DriveControlPanel(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::DriveControlPanel)
{
    ui->setupUi(this);

    // Set start GUI & disable by default
    ui->stackedWidget->setCurrentIndex(0);
    enableDriveControl(false);

    // Set speed validator and value
    ui->speed_lineEdit->setValidator(new QIntValidator(0, 100, this));
    ui->speed_lineEdit->setText("0");

    // Set Regular validator
    ui->regularServoValue_edit->setValidator(new QIntValidator(-45, 45, this));
    ui->regularServoValue_edit->setText("0");

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

/*
 * Slots
 * */

// Used to uncheck box on main GUI if X button pressed on window
void DriveControlPanel::closeEvent(QCloseEvent *event)
{
    emit closed();
    event->accept();
}

// Enable/disable user input
void DriveControlPanel::enableDriveControl(bool en)
{
    // Set class indicator (for transmit enable/disable)
    this->isEnabled = en;

    // Find all widgets in drive GUI
    QList<QWidget*> c = this->findChildren<QWidget*>();

    // Remove widgets to leave enabled
    c.removeAll(ui->centralWidget);
    c.removeAll(ui->regularDrive_radio);
    c.removeAll(ui->tankDrive_radio);
    c.removeAll(ui->customDrive_radio);

    // Loop through and enable/disable all other widgets
    for (auto i = c.cbegin(); i != c.cend(); i++)
    {
        (*i)->setEnabled(en);
    }
}

// Shows/hides the window
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

/*
 * Radio Button Page Switchers
 * */

// Set controls to Regular
void DriveControlPanel::on_regularDrive_radio_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->regularServo_slider->setValue(0);
    ui->regularServoValue_edit->setText("0");

    transmit_command(Rover_JSON::zeroAll);
}

// Set controls to Tank
void DriveControlPanel::on_tankDrive_radio_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tankServo0_radio->setChecked(true);

    transmit_command(Rover_JSON::zeroAll);

}

// Set controls to Custom
void DriveControlPanel::on_customDrive_radio_clicked()
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

// Update regular servo slider when text changed
void DriveControlPanel::on_regularServoValue_edit_textChanged(QString text)
{
    if (!text.isEmpty())
    {
        ui->regularServo_slider->setSliderPosition(text.toInt());
    }
}

// Update regular servo text when slider dragged
void DriveControlPanel::on_regularServo_slider_valueChanged(int value)
{
    ui->regularServoValue_edit->setText(QString::number(value));
}

// Regular servo submit button clicked
void DriveControlPanel::on_regularServoSubmit_button_clicked()
{
    int slider_value = ui->regularServoValue_edit->text().toInt();
    ui->regularServo_slider->setValue(slider_value);
    transmit_command({
                         rover_keys::DT_S_LF, (uint8_t) (servo_dirs::servo_zero + slider_value),
                         rover_keys::DT_S_RF, (uint8_t) (servo_dirs::servo_zero + slider_value)
                     });
}

// Regular drive up button pressed
void DriveControlPanel::on_regularDriveUp_button_pressed()
{
    transmit_command(Rover_JSON::forwardDrive);
}

// Regular drive up button released
void DriveControlPanel::on_regularDriveUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Regular drive down button pressed
void DriveControlPanel::on_regularDriveDown_button_pressed()
{
    transmit_command(Rover_JSON::backwardDrive);
}

// Regular drive down button released
void DriveControlPanel::on_regularDriveDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Regular drive right button clicked
void DriveControlPanel::on_regularDriveRight_button_clicked()
{
    int slider_value = ui->regularServo_slider->value() + 5;
    ui->regularServo_slider->setValue(slider_value);
    on_regularServoSubmit_button_clicked();
}

// Regular drive left button clicked
void DriveControlPanel::on_regularDriveLeft_button_clicked()
{
    int slider_value = ui->regularServo_slider->value() - 5;
    ui->regularServo_slider->setValue(slider_value);
    on_regularServoSubmit_button_clicked();
}

/*
 * Tank Page
 * */

// Tank servo zero selected
void DriveControlPanel::on_tankServo0_radio_clicked()
{
    transmit_command(Rover_JSON::straightServo);
}

// Tank servo forty-five selected
void DriveControlPanel::on_tankServo45_radio_clicked()
{
    transmit_command(Rover_JSON::spinCenterServo);
}

// Tank servo ninety selected
void DriveControlPanel::on_tankServo90_radio_clicked()
{
    transmit_command(Rover_JSON::sidewinderServo);
}

// Tank drive up button pressed
void DriveControlPanel::on_tankUp_button_pressed()
{
    transmit_command(Rover_JSON::forwardDrive);
}

// Tank drive up button released
void DriveControlPanel::on_tankUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Tank drive down button pressed
void DriveControlPanel::on_tankDown_button_pressed()
{
    transmit_command(Rover_JSON::backwardDrive);
}

// Tank drive down button released
void DriveControlPanel::on_tankDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

/*
 * Custom Control Page
 * */

// Custom servo submit button clicked
void DriveControlPanel::on_customServoSubmit_button_clicked()
{
    // Push values on in order
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
        // Required servo to be in same order as pushed on above
        // i.e. LF, LM, LB, RF, RM, RB
        command.push_back(rover_keys::DT_S_LF + i);
        command.push_back(servo_dirs::servo_zero + servo_values[i]);
    }

    transmit_command(command);
}

// Custom left-up button pressed
void DriveControlPanel::on_customLeftUp_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_forward,
                         rover_keys::DT_M_RD, motor_dirs::motor_stop
                    });
}

// Custom left-up button released
void DriveControlPanel::on_customLeftUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom up-down button pressed
void DriveControlPanel::on_customUpDown_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_forward,
                         rover_keys::DT_M_RD, motor_dirs::motor_backward
                    });
}

// Custom up-down button released
void DriveControlPanel::on_customUpDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom left-down button pressed
void DriveControlPanel::on_customLeftDown_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_backward,
                         rover_keys::DT_M_RD, motor_dirs::motor_stop
                    });
}

// Custom left-down button released
void DriveControlPanel::on_customLeftDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom right-up button pressed
void DriveControlPanel::on_customRightUp_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_stop,
                         rover_keys::DT_M_RD, motor_dirs::motor_forward
                    });
}

// Custom right-up button released
void DriveControlPanel::on_customRightUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom down-up button pressed
void DriveControlPanel::on_customDownUp_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_backward,
                         rover_keys::DT_M_RD, motor_dirs::motor_forward
                    });
}

// Custom down-up button released
void DriveControlPanel::on_customDownUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom right-down button pressed
void DriveControlPanel::on_customRightDown_button_pressed()
{
    transmit_command({
                         rover_keys::DT_M_LD, motor_dirs::motor_stop,
                         rover_keys::DT_M_RD, motor_dirs::motor_backward
                    });
}

// Custom right-down button released
void DriveControlPanel::on_customRightDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom up-up button pressed
void DriveControlPanel::on_customUpUp_button_pressed()
{
    transmit_command(Rover_JSON::forwardDrive);
}

// Custom up-up button released
void DriveControlPanel::on_customUpUp_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

// Custom down-down button pressed
void DriveControlPanel::on_customDownDown_button_pressed()
{
    transmit_command(Rover_JSON::backwardDrive);
}

// Custom down-down button released
void DriveControlPanel::on_customDownDown_button_released()
{
    transmit_command(Rover_JSON::stopDrive);
}

/*
 * Speed Setting
 * */

// Update speed slider when text changed
void DriveControlPanel::on_speed_lineEdit_textChanged(QString text)
{
    if (!text.isEmpty())
    {
        ui->speedValue_label->setText(text);
        ui->speedValue_slider->setSliderPosition(text.toInt());
    }
}

// Update speed text when slider dragged
void DriveControlPanel::on_speedValue_slider_valueChanged(int x)
{
    QString s = QString::number(x);
    ui->speedValue_label->setText(s);
    ui->speed_lineEdit->setText(s);
}

// Speed submit button clicked
void DriveControlPanel::on_speedSubmit_button_clicked()
{
     int value = ui->speedValue_slider->value();

     transmit_command({
                          rover_keys::DT_M_Speed, (uint8_t) value
                     });
}

/*
 * Key Handlers
 * */

// Map key press events if in regular drive mode
void DriveControlPanel::keyPressEvent(QKeyEvent * event)
{
    if (!event->isAutoRepeat() && ui->regularDrive_radio->isChecked())
    {
        if(event-> key() == Qt::Key_W)
        {
            on_regularDriveUp_button_pressed();
        } else if(event-> key() == Qt::Key_S)
        {
            on_regularDriveDown_button_pressed();
        } else if(event-> key() == Qt::Key_D)
        {
            on_regularDriveRight_button_clicked();
        } else if(event-> key() == Qt::Key_A)
        {
            on_regularDriveLeft_button_clicked();
        }
    }

}

// Map key release events if in regular drive mode
void DriveControlPanel::keyReleaseEvent(QKeyEvent * event)
{
    if (!event->isAutoRepeat() && ui->regularDrive_radio->isChecked())
    {
        if (event-> key() == Qt::Key_W)
        {
            on_regularDriveUp_button_released();
        } else if (event-> key() == Qt::Key_S)
        {
            on_regularDriveDown_button_released();
        }
    }
}

/*
 * Private Functions
 * */

// Emits the kv pairs to be sent to the server (and then to rover)
void DriveControlPanel::transmit_command(std::list<uint8_t> kv)
{
    if (isEnabled) emit send_data(kv);
}
