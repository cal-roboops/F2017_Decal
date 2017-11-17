#include "mainwindow.h"
#include <QApplication>
#include "controlpanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    ControlPanel c;
//    c.show();

    return a.exec();
}


