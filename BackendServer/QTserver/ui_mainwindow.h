/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *serverOn;
    QPushButton *serverOff;
    QLabel *numClientsLabel;
    QLCDNumber *clientCount;
    QLabel *serverStatusLabel;
    QLabel *serverStatus;
    QLabel *label;
    QProgressBar *roverConnected;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(437, 260);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        serverOn = new QPushButton(centralWidget);
        serverOn->setObjectName(QStringLiteral("serverOn"));
        serverOn->setGeometry(QRect(100, 60, 113, 32));
        QFont font;
        font.setPointSize(15);
        serverOn->setFont(font);
        serverOff = new QPushButton(centralWidget);
        serverOff->setObjectName(QStringLiteral("serverOff"));
        serverOff->setGeometry(QRect(210, 60, 113, 32));
        serverOff->setFont(font);
        numClientsLabel = new QLabel(centralWidget);
        numClientsLabel->setObjectName(QStringLiteral("numClientsLabel"));
        numClientsLabel->setGeometry(QRect(20, 140, 271, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        numClientsLabel->setFont(font1);
        clientCount = new QLCDNumber(centralWidget);
        clientCount->setObjectName(QStringLiteral("clientCount"));
        clientCount->setGeometry(QRect(290, 140, 101, 41));
        serverStatusLabel = new QLabel(centralWidget);
        serverStatusLabel->setObjectName(QStringLiteral("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(122, 20, 131, 31));
        serverStatusLabel->setFont(font1);
        serverStatus = new QLabel(centralWidget);
        serverStatus->setObjectName(QStringLiteral("serverStatus"));
        serverStatus->setGeometry(QRect(250, 20, 61, 31));
        QFont font2;
        font2.setPointSize(18);
        font2.setItalic(true);
        font2.setKerning(true);
        serverStatus->setFont(font2);
        serverStatus->setAutoFillBackground(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 110, 131, 21));
        label->setFont(font);
        roverConnected = new QProgressBar(centralWidget);
        roverConnected->setObjectName(QStringLiteral("roverConnected"));
        roverConnected->setGeometry(QRect(150, 110, 16, 23));
        roverConnected->setMaximum(100);
        roverConnected->setValue(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 437, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        serverOn->setText(QApplication::translate("MainWindow", "Server On", Q_NULLPTR));
        serverOff->setText(QApplication::translate("MainWindow", "Server Off", Q_NULLPTR));
        numClientsLabel->setText(QApplication::translate("MainWindow", "Number of Connected Clients:", Q_NULLPTR));
        serverStatusLabel->setText(QApplication::translate("MainWindow", "Server Status:", Q_NULLPTR));
        serverStatus->setText(QApplication::translate("MainWindow", "Offline", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Rover Connected:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
