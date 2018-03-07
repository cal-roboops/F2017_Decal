#include "armcontrolpanel.h"
#include "ui_armcontrolpanel.h"

ArmControlPanel::ArmControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmControlPanel)
{
    ui->setupUi(this);
    ui->baseAngleLineEdit->setValidator(new QIntValidator(0, 1024, this));
    ui->biformAngleLineEdit->setValidator(new QIntValidator(0, 1024, this));
    ui->elbowAngleLineEdit->setValidator(new QIntValidator(0, 1024, this));
}

ArmControlPanel::~ArmControlPanel()
{
    delete ui;
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


void ArmControlPanel::on_setBaseAngleBtn_clicked()
{
    int value = ui->baseAngleLineEdit->text().toInt();
    // Mitch - send base angle JSON with variable 'value' as angle
}

void ArmControlPanel::on_setBiformAngleBtn_clicked()
{
    int value = ui->biformAngleLineEdit->text().toInt();
    // Mitch - send base angle JSON with variable 'value' as angle
}

void ArmControlPanel::on_setElbowAngleBtn_clicked()
{
    int value = ui->elbowAngleLineEdit->text().toInt();
    // Mitch - send elbow angle JSON with variable 'value' as angle
}

