#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controlpanel.h"

#include <QFile>
#include <QProcess>
#include <QHostAddress>
#include <QMainWindow>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup & create basics
    ui->setupUi(this);

    socket = new QTcpSocket();
    disconnectPressed = false;
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_recvMSG()));

    ui->driveMode_NonControl_Radio->setChecked(true);
    ui->armMode_NonControl_Radio->setChecked(true);
    on_driveMode_NonControl_Radio_clicked();

    ui->infoLabel->setVisible(false);
    ui->drawer_LineEdit->setText("0");
    ui->drawer_LineEdit->setValidator(new QIntValidator(0, 100, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawerValue_slider_valueChanged(int x)
{
    QString s = QString::number(x);
    ui->drawer_LineEdit->setText(s);
    ui->drawerValue_label->setText(s);
}

void MainWindow::on_eStopButton_clicked()
{
    // Mitch - Send Emergency Stop JSON values
}

void MainWindow::on_connect_clicked()
{
    // Disconnect from existing socket
    on_disconnect_clicked();
    if (ui->infoLabel->text().contains("Failed"))
    {
        return;
    }

    // Setup & connect to socket
    QString ipAddr = ui->serv_ipEdit->toPlainText();
    int port = (ui->serv_portEdit->toPlainText()).toInt();
    socket->connectToHost(ipAddr, port);

    // Need to wait for connection
    QString msg = ui->infoLabel->text();
    QString newPeer = ipAddr + ":" + QString::number(port) + "! ";
    if (!socket->waitForConnected(5000))
    {
        msg += "Failed to connect to " + newPeer;
    } else
    {
        msg += "Connected to " + newPeer;
    }

    // Update info label
    ui->infoLabel->setText(msg);
}

void MainWindow::on_disconnect_clicked()
{
    disconnectPressed = true;
    QString disMsg = "";

    // Get current connection info
    QString conPeer = (socket->peerAddress()).toString() + ":";
    conPeer += QString::number(socket->peerPort()) + "! ";

    // Disconnect if connected
    if (socket->state() == QTcpSocket::ConnectedState)
    {
        socket->disconnectFromHost();
    }

    // Need to wait for disconnection
    if (socket->state() != QTcpSocket::UnconnectedState
            && !socket->waitForDisconnected(5000))
    {
        disMsg = "Failed to disconnect from " + conPeer;
    } else
    {
        disMsg = "Disconnected from " + conPeer;
    }

    ui->infoLabel->setText(disMsg);
    disconnectPressed = false;
}

void MainWindow::on_recvMSG()
{
    QByteArray data;
    while (!socket->atEnd())
    {
        data = socket->readAll();
        ui->recvData->append(data.data());
    }
}

void MainWindow::on_clearRECV_clicked()
{
    ui->recvData->clear();
}


void MainWindow::send_data(QByteArray data)
{
    socket->write(data);
    qDebug() << data;
}

void MainWindow::on_openStream_clicked()
{
    QString command;
    #ifdef Q_OS_WIN32
    command = "C:\\Program Files\\VideoLAN\\VLC\\vlc.exe";
    if (!QFile::exists(command))
    {
        command = "C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe";
    }
    #else
    command = "/usr/bin/vlc";
    #endif

    if (!QFile::exists(command))
    {
        ui->infoLabel->setText("ERROR: VLC not found!");
        return;
    }

    #ifdef Q_OS_WIN32
    command = "\"" + command + "\"";
    #endif

    command += " rtp://@";
    command += ui->st_ipEdit->toPlainText();
    command += ":" + ui->st_portEdit->toPlainText();

    QProcess *process = new QProcess(this);
    process->start(command);
}


void MainWindow::on_disconnect()
{
    if (!disconnectPressed)
    {
        ui->infoLabel->setText("Connection Lost!");
    }
}


void MainWindow::on_showArmControl_Check_clicked()
{
    if (ui->showArmControl_Check->isChecked()) {
//        qDebug()
        emit showArmControl(true);
    } else {
        emit showArmControl(false);
    }
}


void MainWindow::on_showDriveControl_Check_clicked() // Show Control Panel Checkbox clicked
{
    if(ui->showDriveControl_Check->isChecked()){
        emit showDriveControl(true);
    }
    else{
       emit showDriveControl(false);
    }
}

void MainWindow::on_driveMode_NonControl_Radio_clicked() //radio button disables control panel
{
    emit enableDriveControl(false);
    if (ui->showDriveControl_Check->isChecked()) {
        emit showDriveControl(true);
    }
}

void MainWindow::on_driveMode_Control_Radio_clicked() //radio button enables control panel
{
    emit enableDriveControl(true);
}

void MainWindow::on_cameraMast_dial_valueChanged(int position)
{
    qDebug() << position;
}


void MainWindow::on_drawerSetValue_button_clicked() {
    if (ui->drawer_LineEdit->text().isEmpty()) {
        qDebug() << "Nothing to set";
    } else {
        ui->drawerValue_label->setText(ui->drawer_LineEdit->text());
        ui->drawerValue_slider->setSliderPosition(ui->drawer_LineEdit->text().toInt());
        // Mitch - SEND DRAWER JSON VALUE TO SERVER
    }
}
