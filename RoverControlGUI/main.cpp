#include <QApplication>
#include <QObject>
#include "mainwindow.h"
#include "controlpanel.h"
#include "armcontrolpanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ControlPanel c;
    c.hide();
    ArmControlPanel ac;
    ac.hide();

    QObject::connect(&c, SIGNAL(send_data(QByteArray)), &w, SLOT(send_data(QByteArray)));
    QObject::connect(&w, SIGNAL(enableDriveControl(bool)), &c, SLOT(enableDriveControl(bool)));
    QObject::connect(&w, SIGNAL(showDriveControl(bool)), &c, SLOT(showDriveControl(bool)));
    QObject::connect(&w, SIGNAL(showArmControl(bool)), &ac, SLOT(showArmControl(bool)));

    return a.exec();
}
