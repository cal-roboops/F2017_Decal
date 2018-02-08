#include "armgraphic.h"
#include "ui_armgraphic.h"

ArmGraphic::ArmGraphic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmGraphic)
{
    ui->setupUi(this);
}

ArmGraphic::~ArmGraphic()
{
    delete ui;
}
