#include "armcontrolpanel.h"
#include "ui_armcontrolpanel.h"

#include "../RoverSharedGlobals/rover_json.h"

ArmControlPanel::ArmControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmControlPanel)
{
    ui->setupUi(this);
    enableArmControl(false);

    // Setup input validators for the text boxes
    ui->baseAngleLineEdit->setValidator(new QIntValidator(0, 1024, this));
    ui->biformAngleLineEdit->setValidator(new QIntValidator(0, 1024, this));
    ui->elbowAngleLineEdit->setValidator(new QIntValidator(0, 1024, this));

    // SHOULD BE REPLACED BY POLLED VALUES
    ui->baseAngleLineEdit->setText("0");
    ui->biformAngleLineEdit->setText("0");
    ui->elbowAngleLineEdit->setText("0");
}

ArmControlPanel::~ArmControlPanel()
{
    delete ui;
}

// Used to uncheck box on main GUI if X button pressed on window
void ArmControlPanel::closeEvent(QCloseEvent *event)
{
    emit closed();
    event->accept();
}

// Enable/disable user input
void ArmControlPanel::enableArmControl(bool en)
{
    // Set class indicator (for transmit enable/disable)
    this->isEnabled = en;

    // Find all widgets in drive GUI
    QList<QWidget*> c = this->findChildren<QWidget*>();

    // Remove widgets to leave enabled
    c.removeAll(ui->centralWidget);

    // Loop through and enable/disable all other widgets
    for (auto i = c.cbegin(); i != c.cend(); i++)
    {
        (*i)->setEnabled(en);
    }
}

// Shows/hides the window
void ArmControlPanel::showArmControl(bool en)
{
    if (en)
    {
        this->show();
    } else
    {
        this->hide();
    }
}

// Sends kv pair to set arm base angle
void ArmControlPanel::on_setBaseAngleBtn_clicked()
{
    int value = ui->baseAngleLineEdit->text().toInt();

    transmit_command({
                         rover_keys::ARM_BASE_ANGLE_UPPER, (uint8_t) ((value >> 8) & 0xFF),
                         rover_keys::ARM_BASE_ANGLE_LOWER, (uint8_t) (value & 0xFF)
                     });
}

// Sends kv pair to set arm biform angle
void ArmControlPanel::on_setBiformAngleBtn_clicked()
{
    int value = ui->biformAngleLineEdit->text().toInt();

    transmit_command({
                         rover_keys::ARM_BIFORM_ANGLE_UPPER, (uint8_t) ((value >> 8) & 0xFF),
                         rover_keys::ARM_BIFORM_ANGLE_LOWER, (uint8_t) (value & 0xFF)
                     });
}

// Sends kv pair to set arm elbow angle
void ArmControlPanel::on_setElbowAngleBtn_clicked()
{
    int value = ui->elbowAngleLineEdit->text().toInt();

    transmit_command({
                         rover_keys::ARM_ELBOW_ANGLE_UPPER, (uint8_t) ((value >> 8) & 0xFF),
                         rover_keys::ARM_ELBOW_ANGLE_LOWER, (uint8_t) (value & 0xFF)
                     });
}

// Emits the kv pairs to be sent to the server (and then to rover)
void ArmControlPanel::transmit_command(std::list<uint8_t> kv)
{
    if (isEnabled) emit send_data(kv);
}