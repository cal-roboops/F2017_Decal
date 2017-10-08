#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <QProcess>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_network();
    setup_slider();
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

void MainWindow::on_webcam_clicked()
{

    //QString command = "\"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe\" -vvvv dshow://\"Lenovo EasyCamera\"";
    QString command = "open -a VLC /Users/Joni/Documents/Berkeley/MarsRover/F2017_Decal/QtMessengerDemo/usbcam.m3u";

    QProcess::execute(command);
}

void MainWindow::setup_slider()
{   
    ui->slider->setValue(50);
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(on_slider()));
}
void MainWindow::on_slider()
{
    QString text = QString::number(ui->slider->value());
    ui->sliderValue->setText(text);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ( (event->key()==Qt::Key_Enter) || (event->key()==Qt::Key_Return) )
    {
        QLineEdit* boxes[8] = { ui->box1, ui->box2, ui->box3, ui->box4, ui->box5, ui->box6, ui->box7, ui->box8};
        for(int i = 0; i < 8; i++)
        {
            if (boxes[i]->text()!="")
            {
                QString s = QString::number(i+1);
                qDebug() << "Textbox " +s + ": " + boxes[i]->text();
            }
        }

    }
}



