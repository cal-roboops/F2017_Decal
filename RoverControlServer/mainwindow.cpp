#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->server = new Server(ui->clientCount, ui->roverConnected);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_serverOn_clicked() {
    this->server->start();
    ui->serverStatus->setText("Online");
}

void MainWindow::on_serverOff_clicked() {
    this->server->terminate();
    ui->serverStatus->setText("Offline");
}
