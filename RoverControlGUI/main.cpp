#include <QApplication>
#include <QObject>
#include "mainwindow.h"
#include "drivecontrolpanel.h"
#include "armcontrolpanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DriveControlPanel dc;
    dc.hide();
    ArmControlPanel ac;
    ac.hide();

    // Connect send data signals and slots
    QObject::connect(&dc, SIGNAL(send_data(std::list<uint8_t>)), &w, SLOT(send_data(std::list<uint8_t>)));
    QObject::connect(&ac, SIGNAL(send_data(std::list<uint8_t>)), &w, SLOT(send_data(std::list<uint8_t>)));

    // Connect drive enable/show signals and slots
    QObject::connect(&w, SIGNAL(enableDriveControl(bool)), &dc, SLOT(enableDriveControl(bool)));
    QObject::connect(&w, SIGNAL(showDriveControl(bool)), &dc, SLOT(showDriveControl(bool)));

    // Connect arm enable/show signals and slots
    QObject::connect(&w, SIGNAL(enableArmControl(bool)), &ac, SLOT(enableArmControl(bool)));
    QObject::connect(&w, SIGNAL(showArmControl(bool)), &ac, SLOT(showArmControl(bool)));

    return a.exec();
}
