#include "mainwindow.h"
#include "server.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    // Create Main Application Instance
    QApplication a(argc, argv);

    // Create Main Window
    MainWindow w;
    w.show();

    // Create Server
    Server server(&w);

    // Connect Signals and Slots
    QObject::connect(&server, SIGNAL(client_count_update(int)), &w, SLOT(update_client_count(int)));
    QObject::connect(&server, SIGNAL(rover_connected(bool)), &w, SLOT(rover_connected(bool)));
    QObject::connect(&server, SIGNAL(server_on(bool)), &w, SLOT(server_on(bool)));

    QObject::connect(&w, SIGNAL(server_start()), &server, SLOT(start()));
    QObject::connect(&w, SIGNAL(server_terminate()), &server, SLOT(terminate()));
    QObject::connect(&w, SIGNAL(server_exit()), &server, SLOT(server_exit()));

    QObject::connect(&w, SIGNAL(setLogLoc(QString)), &server, SLOT(setLogLoc(QString)));

    return a.exec();
}
