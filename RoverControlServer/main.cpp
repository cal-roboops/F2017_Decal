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

    QObject::connect(&w, SIGNAL(server_start()), &server, SLOT(start()));
    QObject::connect(&w, SIGNAL(server_terminate()), &server, SLOT(terminate()));

    return a.exec();
}
