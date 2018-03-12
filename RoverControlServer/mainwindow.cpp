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

void MainWindow::on_serverOn_clicked()
{
    emit server_start();
    ui->serverStatus->setText("Online");
}

void MainWindow::on_serverOff_clicked()
{
    emit server_terminate();
    ui->serverStatus->setText("Offline");
}

void MainWindow::update_client_count(int val)
{
    ui->clientCount->display(val);
}

void MainWindow::rover_connected(bool en)
{
    ui->roverConnected->setValue(en);
}
