#include "armcontrolpanel.h"
#include "ui_armcontrolpanel.h"

ArmControlPanel::ArmControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmControlPanel)
{
    ui->setupUi(this);
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
