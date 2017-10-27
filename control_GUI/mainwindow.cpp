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
    delete ui;
}



void MainWindow::on_button_regular_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_button_tank_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
