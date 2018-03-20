#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    emit server_terminate();
    delete ui;
}

// Handles if X button pressed on window
void MainWindow::closeEvent(QCloseEvent *event)
{
    on_serverOff_clicked();
    event->accept();
}

// Tell server to start
void MainWindow::on_serverOn_clicked()
{
    emit server_start();
    ui->serverStatus->setText("Online");
}

// Tell server to stop
void MainWindow::on_serverOff_clicked()
{
    emit server_terminate();
    ui->serverStatus->setText("Offline");
}

// Update client count display
void MainWindow::update_client_count(int val)
{
    ui->clientCount->display(val);
}

// Update rover connected display
void MainWindow::rover_connected(bool en)
{
    ui->roverConnected->setValue(en);
}
