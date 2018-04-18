#include "armcontrolpanel.h"
#include "ui_armcontrolpanel.h"

#include "../RoverSharedGlobals/rover_json.h"

#include <QDebug>

#include <QQuickItem>
#include <QQmlProperty>
#include <QQmlContext>

ArmControlPanel::ArmControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmControlPanel)
{
    ui->setupUi(this);
    enableArmControl(false);

    // Set arm model QML
    arm_qml = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(arm_qml, this);
    arm_qml->setResizeMode(QQuickView::SizeRootObjectToView);
    arm_qml->setSource(QUrl("qrc:/main.qml"));
    ui->armLayout->addWidget(container);
    arm_ritem = arm_qml->rootObject();
}

ArmControlPanel::~ArmControlPanel()
{
    delete arm_qml;
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
    en = true;
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

// Poll the QML object and send data
void ArmControlPanel::on_setArm_button_clicked()
{
    int bicepAngle = arm_ritem->property("bicep_ang").toInt();
    int biformAngle = arm_ritem->property("biform_ang").toInt();
    int forearmAngle = arm_ritem->property("forearm_ang").toInt();
    int wristAngle = arm_ritem->property("wrist_ang").toInt();

    transmit_command({
                         rover_keys::ARM_BICEP_ANGLE_UPPER, (uint8_t) ((bicepAngle >> 8) & 0xFF),
                         rover_keys::ARM_BICEP_ANGLE_LOWER, (uint8_t) (bicepAngle & 0xFF)
                     });

    transmit_command({
                         rover_keys::ARM_BIFORM_ANGLE_UPPER, (uint8_t) ((biformAngle >> 8) & 0xFF),
                         rover_keys::ARM_BIFORM_ANGLE_LOWER, (uint8_t) (biformAngle & 0xFF)
                     });

    transmit_command({
                         rover_keys::ARM_FOREARM_ANGLE_UPPER, (uint8_t) ((forearmAngle >> 8) & 0xFF),
                         rover_keys::ARM_FOREARM_ANGLE_LOWER, (uint8_t) (forearmAngle & 0xFF)
                     });

    transmit_command({
                         rover_keys::ARM_WRIST_ANGLE_UPPER, (uint8_t) ((wristAngle >> 8) & 0xFF),
                         rover_keys::ARM_WRIST_ANGLE_LOWER, (uint8_t) (wristAngle & 0xFF)
                     });

    qDebug() << bicepAngle << " " << biformAngle << " " << forearmAngle << " " << wristAngle;
}

// Emits the kv pairs to be sent to the server (and then to rover)
void ArmControlPanel::transmit_command(std::list<uint8_t> kv)
{
    if (isEnabled) emit send_data(kv);
}
