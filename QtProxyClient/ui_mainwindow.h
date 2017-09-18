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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *msgEdit;
    QPushButton *sendMSG;
    QLabel *recvLabel;
    QLabel *msgLabel;
    QTextEdit *ipEdit;
    QLabel *ip_Label;
    QTextEdit *recvData;
    QPushButton *clearRECV;
    QPushButton *connect;
    QLabel *infoLabel;
    QTextEdit *portEdit;
    QLabel *port_Label;
    QPushButton *disconnect;
    QPushButton *runTestSuite;
    QTextEdit *testPathEdit;
    QPushButton *selectTestSuite;
    QLabel *test_Label;
    QProgressBar *testProgress;
    QTextEdit *testOut;
    QLabel *test_Label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(685, 413);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        msgEdit = new QTextEdit(centralWidget);
        msgEdit->setObjectName(QStringLiteral("msgEdit"));
        msgEdit->setGeometry(QRect(80, 100, 221, 101));
        sendMSG = new QPushButton(centralWidget);
        sendMSG->setObjectName(QStringLiteral("sendMSG"));
        sendMSG->setGeometry(QRect(140, 210, 93, 28));
        recvLabel = new QLabel(centralWidget);
        recvLabel->setObjectName(QStringLiteral("recvLabel"));
        recvLabel->setGeometry(QRect(330, 10, 80, 21));
        recvLabel->setAlignment(Qt::AlignCenter);
        msgLabel = new QLabel(centralWidget);
        msgLabel->setObjectName(QStringLiteral("msgLabel"));
        msgLabel->setGeometry(QRect(10, 100, 60, 25));
        msgLabel->setAlignment(Qt::AlignCenter);
        ipEdit = new QTextEdit(centralWidget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setGeometry(QRect(100, 30, 91, 25));
        ip_Label = new QLabel(centralWidget);
        ip_Label->setObjectName(QStringLiteral("ip_Label"));
        ip_Label->setGeometry(QRect(10, 30, 81, 25));
        ip_Label->setAlignment(Qt::AlignCenter);
        recvData = new QTextEdit(centralWidget);
        recvData->setObjectName(QStringLiteral("recvData"));
        recvData->setEnabled(true);
        recvData->setGeometry(QRect(330, 30, 331, 171));
        recvData->setReadOnly(true);
        clearRECV = new QPushButton(centralWidget);
        clearRECV->setObjectName(QStringLiteral("clearRECV"));
        clearRECV->setGeometry(QRect(450, 220, 93, 28));
        connect = new QPushButton(centralWidget);
        connect->setObjectName(QStringLiteral("connect"));
        connect->setGeometry(QRect(210, 30, 93, 25));
        infoLabel = new QLabel(centralWidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(20, 240, 331, 20));
        infoLabel->setAlignment(Qt::AlignCenter);
        portEdit = new QTextEdit(centralWidget);
        portEdit->setObjectName(QStringLiteral("portEdit"));
        portEdit->setGeometry(QRect(100, 60, 91, 25));
        port_Label = new QLabel(centralWidget);
        port_Label->setObjectName(QStringLiteral("port_Label"));
        port_Label->setGeometry(QRect(10, 60, 81, 25));
        port_Label->setAlignment(Qt::AlignCenter);
        disconnect = new QPushButton(centralWidget);
        disconnect->setObjectName(QStringLiteral("disconnect"));
        disconnect->setGeometry(QRect(210, 60, 93, 25));
        runTestSuite = new QPushButton(centralWidget);
        runTestSuite->setObjectName(QStringLiteral("runTestSuite"));
        runTestSuite->setGeometry(QRect(560, 310, 93, 25));
        testPathEdit = new QTextEdit(centralWidget);
        testPathEdit->setObjectName(QStringLiteral("testPathEdit"));
        testPathEdit->setGeometry(QRect(80, 280, 471, 51));
        selectTestSuite = new QPushButton(centralWidget);
        selectTestSuite->setObjectName(QStringLiteral("selectTestSuite"));
        selectTestSuite->setGeometry(QRect(560, 280, 93, 25));
        test_Label = new QLabel(centralWidget);
        test_Label->setObjectName(QStringLiteral("test_Label"));
        test_Label->setGeometry(QRect(10, 280, 60, 25));
        test_Label->setAlignment(Qt::AlignCenter);
        testProgress = new QProgressBar(centralWidget);
        testProgress->setObjectName(QStringLiteral("testProgress"));
        testProgress->setGeometry(QRect(560, 350, 118, 23));
        testProgress->setValue(0);
        testOut = new QTextEdit(centralWidget);
        testOut->setObjectName(QStringLiteral("testOut"));
        testOut->setGeometry(QRect(80, 340, 471, 51));
        testOut->setReadOnly(true);
        test_Label_2 = new QLabel(centralWidget);
        test_Label_2->setObjectName(QStringLiteral("test_Label_2"));
        test_Label_2->setGeometry(QRect(10, 340, 60, 25));
        test_Label_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtProxyClient", Q_NULLPTR));
        sendMSG->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        recvLabel->setText(QApplication::translate("MainWindow", "Received Data", Q_NULLPTR));
        msgLabel->setText(QApplication::translate("MainWindow", "Message", Q_NULLPTR));
        ipEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">127.0.0.1</p></body></html>", Q_NULLPTR));
        ip_Label->setText(QApplication::translate("MainWindow", "Desitination IP", Q_NULLPTR));
        clearRECV->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        infoLabel->setText(QString());
        portEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">8088</p></body></html>", Q_NULLPTR));
        port_Label->setText(QApplication::translate("MainWindow", "Desitination Port", Q_NULLPTR));
        disconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        runTestSuite->setText(QApplication::translate("MainWindow", "Run Test Suite", Q_NULLPTR));
        selectTestSuite->setText(QApplication::translate("MainWindow", "Select Test Suite", Q_NULLPTR));
        test_Label->setText(QApplication::translate("MainWindow", "Test Path", Q_NULLPTR));
        test_Label_2->setText(QApplication::translate("MainWindow", "Test Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
