#include <QApplication>
#include <QObject>
#include "mainwindow.h"
#include "drivecontrolpanel.h"
#include "armcontrolpanel.h"
#include "datavisualizer.h"

int main(int argc, char *argv[])
{
    // Create main application instance
    QApplication a(argc, argv);

    // Create the main control window
    MainWindow w;
    w.show();

    // Create the drive control window
    DriveControlPanel dc(&w);
    dc.hide();

    // Create the arm control window
    ArmControlPanel ac(&w);
    ac.hide();

    // Create the data visualizer window
    DataVisualizer dv(&w);
    dv.hide();

    // Connect send data signals and slots
    QObject::connect(&dc, SIGNAL(send_data(std::list<uint8_t>)), &w, SLOT(send_data(std::list<uint8_t>)));
    QObject::connect(&ac, SIGNAL(send_data(std::list<uint8_t>)), &w, SLOT(send_data(std::list<uint8_t>)));

    // Connect drive enable/show signals and slots
    QObject::connect(&w, SIGNAL(enableDriveControl(bool)), &dc, SLOT(enableDriveControl(bool)));
    QObject::connect(&w, SIGNAL(showDriveControl(bool)), &dc, SLOT(showDriveControl(bool)));
    QObject::connect(&dc, SIGNAL(closed()), &w, SLOT(drive_closed()));

    // Connect arm enable/show signals and slots
    QObject::connect(&w, SIGNAL(enableArmControl(bool)), &ac, SLOT(enableArmControl(bool)));
    QObject::connect(&w, SIGNAL(showArmControl(bool)), &ac, SLOT(showArmControl(bool)));
    QObject::connect(&ac, SIGNAL(closed()), &w, SLOT(arm_closed()));

    // Connect data visualizer show/hide signals and slots
    QObject::connect(&w, SIGNAL(showDataVisualizer(bool)), &dv, SLOT(showDataVisualizer(bool)));
    QObject::connect(&dv, SIGNAL(closed()), &w, SLOT(dataVisualizer_closed()));

    // Start execution
    return a.exec();
}
