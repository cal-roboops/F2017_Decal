#include "mainwindow.h"
#include "controlpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ControlPanel c(&w);
    c.show();

    return a.exec();
}
