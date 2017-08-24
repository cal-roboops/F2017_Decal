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

    setup_network();
}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}

void MainWindow::setup_network()
{
    socket = new QUdpSocket(this);
    socket->bind(8088);
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_recvMSG()));
}

void MainWindow::on_sendMSG_clicked()
{
    QByteArray data = ui->msgEdit->toPlainText().toLocal8Bit();
    QHostAddress ip = QHostAddress(ui->ipEdit->toPlainText());
    socket->writeDatagram(data, ip, 8088);
}

void MainWindow::on_recvMSG()
{
    QByteArray datagram;
    while (socket->hasPendingDatagrams())
    {
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());
        ui->recvData->append(datagram.data());
    }
}

void MainWindow::on_clearRECV_clicked()
{
    ui->recvData->clear();
}
