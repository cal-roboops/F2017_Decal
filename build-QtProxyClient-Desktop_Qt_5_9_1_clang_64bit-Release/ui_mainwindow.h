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
    QTextEdit *serv_ipEdit;
    QLabel *serv_ip_Label;
    QTextEdit *recvData;
    QPushButton *clearRECV;
    QPushButton *connect;
    QLabel *infoLabel;
    QTextEdit *serv_portEdit;
    QLabel *serv_port_Label;
    QPushButton *disconnect;
    QPushButton *runTestSuite;
    QTextEdit *testPathEdit;
    QPushButton *selectTestSuite;
    QLabel *test_Label;
    QProgressBar *testProgress;
    QTextEdit *testOut;
    QLabel *test_Label_2;
    QLabel *st_ip_Label;
    QPushButton *openStream;
    QTextEdit *st_portEdit;
    QTextEdit *st_ipEdit;
    QLabel *st_port_Label;
    QLabel *streamLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1626, 534);
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
        serv_ipEdit = new QTextEdit(centralWidget);
        serv_ipEdit->setObjectName(QStringLiteral("serv_ipEdit"));
        serv_ipEdit->setGeometry(QRect(100, 30, 91, 25));
        serv_ip_Label = new QLabel(centralWidget);
        serv_ip_Label->setObjectName(QStringLiteral("serv_ip_Label"));
        serv_ip_Label->setGeometry(QRect(30, 30, 60, 25));
        serv_ip_Label->setAlignment(Qt::AlignCenter);
        recvData = new QTextEdit(centralWidget);
        recvData->setObjectName(QStringLiteral("recvData"));
        recvData->setEnabled(true);
        recvData->setGeometry(QRect(330, 30, 331, 171));
        recvData->setReadOnly(true);
        clearRECV = new QPushButton(centralWidget);
        clearRECV->setObjectName(QStringLiteral("clearRECV"));
        clearRECV->setGeometry(QRect(450, 210, 93, 28));
        connect = new QPushButton(centralWidget);
        connect->setObjectName(QStringLiteral("connect"));
        connect->setGeometry(QRect(210, 30, 93, 25));
        infoLabel = new QLabel(centralWidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(20, 250, 331, 20));
        infoLabel->setAlignment(Qt::AlignCenter);
        serv_portEdit = new QTextEdit(centralWidget);
        serv_portEdit->setObjectName(QStringLiteral("serv_portEdit"));
        serv_portEdit->setGeometry(QRect(100, 60, 91, 25));
        serv_port_Label = new QLabel(centralWidget);
        serv_port_Label->setObjectName(QStringLiteral("serv_port_Label"));
        serv_port_Label->setGeometry(QRect(30, 60, 60, 25));
        serv_port_Label->setAlignment(Qt::AlignCenter);
        disconnect = new QPushButton(centralWidget);
        disconnect->setObjectName(QStringLiteral("disconnect"));
        disconnect->setGeometry(QRect(210, 60, 93, 25));
        runTestSuite = new QPushButton(centralWidget);
        runTestSuite->setObjectName(QStringLiteral("runTestSuite"));
        runTestSuite->setGeometry(QRect(720, 330, 93, 25));
        testPathEdit = new QTextEdit(centralWidget);
        testPathEdit->setObjectName(QStringLiteral("testPathEdit"));
        testPathEdit->setGeometry(QRect(80, 290, 621, 51));
        selectTestSuite = new QPushButton(centralWidget);
        selectTestSuite->setObjectName(QStringLiteral("selectTestSuite"));
        selectTestSuite->setGeometry(QRect(720, 300, 93, 25));
        test_Label = new QLabel(centralWidget);
        test_Label->setObjectName(QStringLiteral("test_Label"));
        test_Label->setGeometry(QRect(10, 290, 60, 25));
        test_Label->setAlignment(Qt::AlignCenter);
        testProgress = new QProgressBar(centralWidget);
        testProgress->setObjectName(QStringLiteral("testProgress"));
        testProgress->setGeometry(QRect(720, 370, 118, 23));
        testProgress->setValue(0);
        testOut = new QTextEdit(centralWidget);
        testOut->setObjectName(QStringLiteral("testOut"));
        testOut->setGeometry(QRect(80, 350, 621, 51));
        testOut->setReadOnly(true);
        test_Label_2 = new QLabel(centralWidget);
        test_Label_2->setObjectName(QStringLiteral("test_Label_2"));
        test_Label_2->setGeometry(QRect(10, 350, 60, 25));
        test_Label_2->setAlignment(Qt::AlignCenter);
        st_ip_Label = new QLabel(centralWidget);
        st_ip_Label->setObjectName(QStringLiteral("st_ip_Label"));
        st_ip_Label->setGeometry(QRect(680, 50, 60, 25));
        st_ip_Label->setAlignment(Qt::AlignCenter);
        openStream = new QPushButton(centralWidget);
        openStream->setObjectName(QStringLiteral("openStream"));
        openStream->setGeometry(QRect(710, 130, 93, 25));
        st_portEdit = new QTextEdit(centralWidget);
        st_portEdit->setObjectName(QStringLiteral("st_portEdit"));
        st_portEdit->setGeometry(QRect(750, 90, 91, 25));
        st_ipEdit = new QTextEdit(centralWidget);
        st_ipEdit->setObjectName(QStringLiteral("st_ipEdit"));
        st_ipEdit->setGeometry(QRect(750, 50, 91, 25));
        st_port_Label = new QLabel(centralWidget);
        st_port_Label->setObjectName(QStringLiteral("st_port_Label"));
        st_port_Label->setGeometry(QRect(680, 90, 60, 25));
        st_port_Label->setAlignment(Qt::AlignCenter);
        streamLabel = new QLabel(centralWidget);
        streamLabel->setObjectName(QStringLiteral("streamLabel"));
        streamLabel->setGeometry(QRect(720, 20, 70, 21));
        streamLabel->setAlignment(Qt::AlignCenter);
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
        serv_ipEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">127.0.0.1</span></p></body></html>", Q_NULLPTR));
        serv_ip_Label->setText(QApplication::translate("MainWindow", "Server IP", Q_NULLPTR));
        clearRECV->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        infoLabel->setText(QString());
        serv_portEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">8088</span></p></body></html>", Q_NULLPTR));
        serv_port_Label->setText(QApplication::translate("MainWindow", "Server Port", Q_NULLPTR));
        disconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        runTestSuite->setText(QApplication::translate("MainWindow", "Run Test Suite", Q_NULLPTR));
        selectTestSuite->setText(QApplication::translate("MainWindow", "Select Test Suite", Q_NULLPTR));
        test_Label->setText(QApplication::translate("MainWindow", "Test Path", Q_NULLPTR));
        test_Label_2->setText(QApplication::translate("MainWindow", "Test Output", Q_NULLPTR));
        st_ip_Label->setText(QApplication::translate("MainWindow", "Stream IP", Q_NULLPTR));
        openStream->setText(QApplication::translate("MainWindow", "Open Stream", Q_NULLPTR));
        st_portEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">9001</span></p></body></html>", Q_NULLPTR));
        st_ipEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">239.0.0.1</span></p></body></html>", Q_NULLPTR));
        st_port_Label->setText(QApplication::translate("MainWindow", "Stream Port", Q_NULLPTR));
        streamLabel->setText(QApplication::translate("MainWindow", "RTP Stream", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
