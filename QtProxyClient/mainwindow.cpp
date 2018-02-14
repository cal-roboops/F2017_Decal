#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controlpanel.h"

#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QTextStream>
#include <QProcess>
#include <qglobal.h>
#include <QMainWindow>
#include <QJsonObject>
#include <QDebug>

#include <QJsonDocument>

//#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup & create basics
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    disconnectPressed = false;
    ui->sendMSG->setEnabled(false);
    ui->radioButton_nc_mode->setChecked(true);
    ui->nonControlArm->setChecked(true);
    on_radioButton_nc_mode_clicked();
    // Connect desired SIGNALs and SLOTs
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_recvMSG()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(on_disconnect()));
    ui->infoLabel->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
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
        ui->sendMSG->setEnabled(true);
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

void MainWindow::on_sendMSG_clicked()
{
    socket->write(ui->msgEdit->toPlainText().toLocal8Bit());
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


void MainWindow::send_data(QString data) {
    socket->write(data.toLocal8Bit());
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

    ui->sendMSG->setEnabled(false);
}

void MainWindow::format_JSON(QJsonObject input) //formates JSON Object
{
    QJsonDocument doc(input);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    qDebug() << strJson;
}


void MainWindow::on_checkBox_show_cp_clicked() //Show Control Panel Checkbox clicked
{
    if(ui->checkBox_show_cp->isChecked() == true){
        c.show();
    }
   else{
       c.hide();
    }
}

void MainWindow::on_radioButton_nc_mode_clicked() //radio button disables control panel
{
    c.setEnabled(false);
    if (ui->checkBox_show_cp->isChecked()) {
        c.show();
    }
    QJsonObject input;
    input["Controller"] = 0;
    format_JSON(input);
}

void MainWindow::on_radioButton_c_mode_clicked() //radio button enables control panel
{
    c.setEnabled(true);
    QJsonObject input;
    input["Controller"] = 1;
    format_JSON(input);
}

void MainWindow::on_armGraphic_clicked()
{
    // Enable window
    ag.show();
    // Set up JSON object and send
}

void MainWindow::uncheck_checkBox_show_cp()
{
    ui->checkBox_show_cp->setChecked(false);
}

void MainWindow::on_cameraMast_valueChanged(int position)
{
    qDebug() << position;
}
