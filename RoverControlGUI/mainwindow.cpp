#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QProcess>
#include <QHostAddress>
#include <QMainWindow>
#include <QDebug>

#include "../RoverSharedGlobals/rover_json.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup & create basics
    ui->setupUi(this);

    socket = new QTcpSocket();
    disconnectPressed = false;
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_recvMSG()), Qt::QueuedConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(on_disconnect()));

    ui->driveMode_NonControl_Radio->setChecked(true);
    ui->armMode_NonControl_Radio->setChecked(true);

    ui->drawer_LineEdit->setValidator(new QIntValidator(0, 100, this));
    ui->camera_LineEdit->setValidator(new QIntValidator(0, 360, this));

    ui->drawer_LineEdit->setText("0");
    ui->drawerValue_label->setText("0%");
    ui->cameraDial_Label->setText("180°");
    ui->camera_LineEdit->setText("180");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Handles if X button pressed on window
void MainWindow::closeEvent(QCloseEvent *event)
{
    on_disconnect_clicked();
    event->accept();
}

void MainWindow::send_data(std::list<uint8_t> data)
{
    if (Rover_JSON::isValid(data))
    {
        QByteArray byte_data;
        for (auto it = data.begin(); it != data.end(); it++)
        {
            byte_data.append((char) *it);
        }

        socket->write(byte_data);
        qDebug() << byte_data;
    } else
    {
        qDebug() << "Invalid JSON";
    }
}

void MainWindow::drive_closed()
{
    ui->showDriveControl_Check->setChecked(false);
}

void MainWindow::arm_closed()
{
    ui->showArmControl_Check->setChecked(false);
}

void MainWindow::dataVisualizer_closed()
{
    ui->dataVisualCheckBox->setChecked(false);
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
        socket->readAll();
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
    if (connected())
    {
        socket->disconnectFromHost();
    }

    // Need to wait for disconnection
    if (!unconnected() && !socket->waitForDisconnected(5000))
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
    data = socket->readAll();
    ui->recvData->append(data.data());

    qDebug() << data;

    if ((data.length() == 2) && ((char) data[0] == rover_keys::TAKE_CONTROL))
    {
        switch ((char) data[1])
        {
            case rover_modes::drive:
                emit enableDriveControl(true);
                emit enableArmControl(false);
                break;
            case rover_modes::arm:
                emit enableDriveControl(false);
                emit enableArmControl(true);
                break;
            default:
                emit enableDriveControl(false);
                emit enableArmControl(false);
                break;
        }
    }
}

void MainWindow::on_clearRECV_clicked()
{
    ui->recvData->clear();
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

    ui->driveMode_NonControl_Radio->setChecked(true);
    emit enableDriveControl(false);

    ui->armMode_NonControl_Radio->setChecked(true);
    emit enableArmControl(false);
}

void MainWindow::on_showDriveControl_Check_clicked()
{
    if(ui->showDriveControl_Check->isChecked())
    {
        emit showDriveControl(true);
    } else
    {
       emit showDriveControl(false);
    }
}

void MainWindow::on_driveMode_Control_Radio_clicked()
{
    // Only enter drive control if connected and arm control not enabled
    if (connected() && !ui->armMode_Control_Radio->isChecked())
    {
        send_data({
                      rover_keys::TAKE_CONTROL,
                      rover_modes::drive
                  });
    } else
    {
        ui->driveMode_NonControl_Radio->setChecked(true);
    }
}

void MainWindow::on_driveMode_NonControl_Radio_clicked()
{
    send_data({
                  rover_keys::TAKE_CONTROL,
                  rover_modes::none
              });
}

void MainWindow::on_showArmControl_Check_clicked()
{
    if (ui->showArmControl_Check->isChecked())
    {
        emit showArmControl(true);
    } else
    {
        emit showArmControl(false);
    }
}

void MainWindow::on_armMode_Control_Radio_clicked()
{
    // Only enter arm control if connected and drive control not enabled
    if (connected() && !ui->driveMode_Control_Radio->isChecked())
    {
        send_data({
                      rover_keys::TAKE_CONTROL,
                      rover_modes::arm
                  });
    } else
    {
        ui->armMode_NonControl_Radio->setChecked(true);
    }
}

void MainWindow::on_armMode_NonControl_Radio_clicked()
{
    send_data({
                  rover_keys::TAKE_CONTROL,
                  rover_modes::none
              });
}

void MainWindow::on_cameraMast_dial_valueChanged(int position)
{
    QString s = QString::number(position);
    ui->camera_LineEdit->setText(s);
    ui->cameraDial_Label->setText(s + "°");
}

void MainWindow::on_camera_LineEdit_textChanged(QString text)
{
    if (!text.isEmpty())
    {
        ui->cameraDial_Label->setText(text + "°");
        ui->cameraMast_dial->setValue(text.toInt());
    }
}

void MainWindow::on_cameraSubmitBtn_clicked()
{
    int value = ui->cameraMast_dial->value();

    send_data({
                 rover_keys::CAMERA_PAN, (uint8_t) (value / 2)
             });
}

void MainWindow::on_drawerValue_slider_valueChanged(int x)
{
    QString s = QString::number(x);
    ui->drawer_LineEdit->setText(s);
    ui->drawerValue_label->setText(s + "%");
}

void MainWindow::on_drawer_LineEdit_textChanged(QString text) {
    if (!text.isEmpty())
    {
        ui->drawerValue_label->setText(text + "%");
        ui->drawerValue_slider->setSliderPosition(text.toInt());
    }
}

void MainWindow::on_drawerSubmitBtn_clicked()
{
    int value = ui->drawerValue_slider->value();

    send_data({
                 rover_keys::DRAWER_OPEN, (uint8_t) value
             });
}

void MainWindow::on_eStopButton_clicked()
{
    send_data({
                 rover_keys::EMERGENCY_STOP, 1
             });
}

void MainWindow::on_shutdownBtn_clicked()
{
    // Need to have pop up dialog say "restart? Shutdown?"

    send_data({
                 rover_keys::SHUT_DOWN, 1
             });
}

void MainWindow::on_dataVisualCheckBox_clicked()
{
    qDebug() << "Data visualizer selected.";
    if (ui->dataVisualCheckBox->isChecked()) {
        emit showDataVisualizer(true);
    }
    else {
        emit showDataVisualizer(false);
    }
}

bool MainWindow::connected()
{
    return (socket->state() == QTcpSocket::ConnectedState);
}

bool MainWindow::unconnected()
{
    return (socket->state() == QTcpSocket::UnconnectedState);
}

