#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>

#include <QDebug>

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

// Handles if X button pressed on window
void MainWindow::closeEvent(QCloseEvent *event)
{
    emit server_exit();
    event->accept();
}

// Update client count display
void MainWindow::update_client_count(int val)
{
    ui->clientCount->display(val);
}

// Update rover connected display
void MainWindow::rover_connected(bool en)
{
    ui->roverConnected->setValue(en);
}

// Update server on display
void MainWindow::server_on(bool on)
{
    if (on) ui->serverStatus->setText("Online");
    else ui->serverStatus->setText("Offline");

    ui->serverLogLoc_Edit->setEnabled(!on);
    ui->serverLogLoc_button->setEnabled(!on);
}

// Tell server to start
void MainWindow::on_serverOn_clicked()
{
    QString logLoc = ui->serverLogLoc_Edit->text();
    if (!logLoc.isEmpty())
    {
        logLoc += QString::number(QDateTime::currentSecsSinceEpoch());
        logLoc += "_RoverServerLog.txt";
        emit setLogLoc(logLoc);
        emit server_start();
        ui->serverLogLoc_Edit->setStyleSheet("QLineEdit {background-color: white;}");
    } else
    {
        ui->serverLogLoc_Edit->setStyleSheet("QLineEdit {background-color: red;}");
    }
}

// Tell server to stop
void MainWindow::on_serverOff_clicked()
{
    emit server_terminate();
}

// Set new log location
void MainWindow::on_serverLogLoc_button_clicked()
{
    QString logPath;
    logPath = QFileDialog::getExistingDirectory(this, tr("Select Log Directory"),
                                                "", QFileDialog::DontResolveSymlinks);

    if (!logPath.isEmpty())
    {
        if (!logPath.endsWith('/')) logPath += '/';
        ui->serverLogLoc_Edit->setText(logPath);
    }
}
