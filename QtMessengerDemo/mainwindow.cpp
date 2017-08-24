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

    receive_data_over_network();
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
    QUdpSocket socket2;
    socket2.writeDatagram(arr, QHostAddress("127.0.0.1"), 8088);
}

void MainWindow::receive_data_over_network()
{
    socket = new QUdpSocket(this);
    socket->bind(8088);
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_receive()));
}

void MainWindow::on_receive()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());
        ui->receivedData->append(datagram.data());
    }
}
