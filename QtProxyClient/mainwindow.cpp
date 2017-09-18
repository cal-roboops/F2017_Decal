#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QTextStream>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup & create basics
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    disconnectPressed = false;
    ui->sendMSG->setEnabled(false);

    // Connect desired SIGNALs and SLOTs
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_recvMSG()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(on_disconnect()));
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
    QString ipAddr = ui->ipEdit->toPlainText();
    int port = (ui->portEdit->toPlainText()).toInt();
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

void MainWindow::on_clearRECV_clicked()
{
    ui->recvData->clear();
}

void MainWindow::on_selectTestSuite_clicked()
{
    QStringList filePaths;
    QFileDialog newTestFS(this);
    newTestFS.setFileMode(QFileDialog::AnyFile);
    newTestFS.setViewMode(QFileDialog::Detail);
    if (newTestFS.exec())
    {
        filePaths = newTestFS.selectedFiles();
    }

    ui->testPathEdit->setText(filePaths[0]);
}

void MainWindow::on_runTestSuite_clicked()
{
    QString filePath = ui->testPathEdit->toPlainText();
    if (filePath.isEmpty())
    {
        ui->testOut->setText("Must select a suite before running!");
        return;
    } else if (socket->state() != QTcpSocket::ConnectedState)
    {
        ui->testOut->setText("Must connect to server before running!");
        return;
    }

    on_clearRECV_clicked();
    ui->testOut->clear();

    int progress = 0;
    ui->testProgress->setValue(progress);

    QFile testFile(filePath);
    if (testFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream testStream(&testFile);

        int testLines = 0;
        QString testMSG = testStream.readLine();;
        while (!testStream.atEnd() && (!testMSG.isEmpty()))
        {
            testLines += 1;
            testMSG = testStream.readLine();
        }
        testStream.seek(0);

        int curLine = 0;
        while (curLine < testLines)
        {
            curLine += 1;
            testMSG = testStream.readLine();

            socket->write(testMSG.toLocal8Bit());
            socket->waitForReadyRead(5000);

            ui->testProgress->setValue((100*curLine)/testLines);
            qApp->processEvents();
            Sleep(100);
        }
        testStream.readLine();

        QStringList testRECV = ui->recvData->toPlainText().split('\n');
        QStringList testRESP;
        while (!testStream.atEnd())
        {
            testRESP << testStream.readLine();
        }

        int i, tRSP, tRCV, mRSL;
        QString msg;
        tRSP = testRESP.length();
        tRCV = testRECV.length();
        mRSL = qMin(tRSP, tRCV);
        for (i = 0; i < mRSL; i++)
        {
            if (testRESP[i] != testRECV[i])
            {
                msg = "Test " + QString::number(i) + ": received ";
                msg += testRECV[i] + " expected " + testRESP[i];
                ui->testOut->append(msg);
            }
        }

        if (mRSL < tRSP)
        {
            for (i = mRSL; i < tRSP; i++)
            {
                msg = QString::number(i) + " received [NOTHING]";
                msg += " expected " + testRESP[i];
                ui->testOut->append(msg);
            }
        } else if (mRSL < tRCV)
        {
            for (i = mRSL; i < tRCV; i++)
            {
                msg = QString::number(i) + " Received " + testRECV[i];
                msg += " expected [NOTHING]";
                ui->testOut->append(msg);
            }
        }

        if (ui->testOut->toPlainText().isEmpty())
        {
            ui->testOut->setText("Test Suite Passed!");
        }

        testFile.close();
    } else
    {
        ui->infoLabel->setText("Error opening test file!");
        return;
    }
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

void MainWindow::on_disconnect()
{
    if (!disconnectPressed)
    {
        ui->infoLabel->setText("Connection Lost!");
    }

    ui->sendMSG->setEnabled(false);
}
