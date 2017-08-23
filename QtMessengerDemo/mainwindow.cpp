#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include <iostream>

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

void MainWindow::on_button1_clicked()
{
    qDebug() << "Pushed button1"; // printing to console

}

void MainWindow::on_submitData_clicked()
{
    QString data = ui->data->toPlainText();
    QByteArray arr = data.toLocal8Bit();
    char* processedData = arr.data();
    qDebug() << processedData;
}
