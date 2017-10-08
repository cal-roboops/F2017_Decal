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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QPushButton *webcam;
    QSlider *slider;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(845, 384);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        msgEdit = new QTextEdit(centralWidget);
        msgEdit->setObjectName(QStringLiteral("msgEdit"));
        msgEdit->setGeometry(QRect(550, 210, 191, 101));
        sendMSG = new QPushButton(centralWidget);
        sendMSG->setObjectName(QStringLiteral("sendMSG"));
        sendMSG->setGeometry(QRect(90, 190, 93, 28));
        recvLabel = new QLabel(centralWidget);
        recvLabel->setObjectName(QStringLiteral("recvLabel"));
        recvLabel->setGeometry(QRect(320, 10, 101, 21));
        recvLabel->setAlignment(Qt::AlignCenter);
        msgLabel = new QLabel(centralWidget);
        msgLabel->setObjectName(QStringLiteral("msgLabel"));
        msgLabel->setGeometry(QRect(10, 70, 60, 25));
        msgLabel->setAlignment(Qt::AlignCenter);
        ipEdit = new QTextEdit(centralWidget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setGeometry(QRect(110, 30, 171, 25));
        ip_Label = new QLabel(centralWidget);
        ip_Label->setObjectName(QStringLiteral("ip_Label"));
        ip_Label->setGeometry(QRect(10, 30, 91, 25));
        ip_Label->setAlignment(Qt::AlignCenter);
        recvData = new QTextEdit(centralWidget);
        recvData->setObjectName(QStringLiteral("recvData"));
        recvData->setEnabled(true);
        recvData->setGeometry(QRect(320, 40, 331, 141));
        recvData->setReadOnly(true);
        clearRECV = new QPushButton(centralWidget);
        clearRECV->setObjectName(QStringLiteral("clearRECV"));
        clearRECV->setGeometry(QRect(400, 190, 93, 28));
        webcam = new QPushButton(centralWidget);
        webcam->setObjectName(QStringLiteral("webcam"));
        webcam->setGeometry(QRect(90, 280, 93, 28));
        slider = new QSlider(centralWidget);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setGeometry(QRect(330, 310, 160, 22));
        slider->setMaximum(100);
        slider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtMessengerDemo", Q_NULLPTR));
        sendMSG->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        recvLabel->setText(QApplication::translate("MainWindow", "Received Data", Q_NULLPTR));
        msgLabel->setText(QApplication::translate("MainWindow", "Message", Q_NULLPTR));
        ipEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">127.0.0.1</span></p></body></html>", Q_NULLPTR));
        ip_Label->setText(QApplication::translate("MainWindow", "Desitination IP", Q_NULLPTR));
        clearRECV->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        webcam->setText(QApplication::translate("MainWindow", "Webcam", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
