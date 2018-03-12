#include "armcontrolpanel.h"
#include "ui_armcontrolpanel.h"

#include "../RoverSharedGlobals/rover_json.h"

ArmControlPanel::ArmControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmControlPanel)
{
    ui->setupUi(this);
    enableArmControl(false);

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

void ArmControlPanel::enableArmControl(bool en)
{
    this->setEnabled(en);
}

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

void ArmControlPanel::transmit_command(std::list<uint8_t> kv)
{
    emit send_data(kv);
}


void ArmControlPanel::on_setBaseAngleBtn_clicked()
{
    int value = ui->baseAngleLineEdit->text().toInt();

    transmit_command({
                         rover_keys::ARM_BASE_ANGLE, (uint8_t) value
                     });
}

void ArmControlPanel::on_setBiformAngleBtn_clicked()
{
    int value = ui->biformAngleLineEdit->text().toInt();

    transmit_command({
                         rover_keys::ARM_BIFORM_ANGLE, (uint8_t) value
                     });
}

void ArmControlPanel::on_setElbowAngleBtn_clicked()
{
    int value = ui->elbowAngleLineEdit->text().toInt();

    transmit_command({
                         rover_keys::ARM_ELBOW_ANGLE, (uint8_t) value
                     });
}

