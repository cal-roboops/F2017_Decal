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
#include <QtWidgets/QLineEdit>
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
    QLabel *sliderValue;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *box1;
    QLineEdit *box2;
    QLineEdit *box3;
    QLineEdit *box4;
    QLineEdit *box5;
    QLineEdit *box6;
    QLineEdit *box7;
    QLineEdit *box8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(845, 704);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        msgEdit = new QTextEdit(centralWidget);
        msgEdit->setObjectName(QStringLiteral("msgEdit"));
        msgEdit->setGeometry(QRect(90, 80, 191, 101));
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
        slider->setGeometry(QRect(470, 420, 160, 22));
        slider->setMaximum(100);
        slider->setOrientation(Qt::Horizontal);
        sliderValue = new QLabel(centralWidget);
        sliderValue->setObjectName(QStringLiteral("sliderValue"));
        sliderValue->setGeometry(QRect(510, 390, 60, 16));
        sliderValue->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 380, 61, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 440, 61, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 510, 61, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 570, 61, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 390, 61, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 450, 61, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(350, 510, 61, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(350, 570, 61, 20));
        box1 = new QLineEdit(centralWidget);
        box1->setObjectName(QStringLiteral("box1"));
        box1->setGeometry(QRect(100, 380, 111, 41));
        box2 = new QLineEdit(centralWidget);
        box2->setObjectName(QStringLiteral("box2"));
        box2->setGeometry(QRect(220, 380, 111, 41));
        box3 = new QLineEdit(centralWidget);
        box3->setObjectName(QStringLiteral("box3"));
        box3->setGeometry(QRect(100, 440, 111, 41));
        box4 = new QLineEdit(centralWidget);
        box4->setObjectName(QStringLiteral("box4"));
        box4->setGeometry(QRect(220, 440, 111, 41));
        box5 = new QLineEdit(centralWidget);
        box5->setObjectName(QStringLiteral("box5"));
        box5->setGeometry(QRect(100, 500, 111, 41));
        box6 = new QLineEdit(centralWidget);
        box6->setObjectName(QStringLiteral("box6"));
        box6->setGeometry(QRect(220, 500, 111, 41));
        box7 = new QLineEdit(centralWidget);
        box7->setObjectName(QStringLiteral("box7"));
        box7->setGeometry(QRect(100, 560, 111, 41));
        box8 = new QLineEdit(centralWidget);
        box8->setObjectName(QStringLiteral("box8"));
        box8->setGeometry(QRect(220, 560, 111, 41));
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
        sliderValue->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextBox 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TextBox 3", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "TextBox 5", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "TextBox 7", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "TextBox 2", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "TextBox 4", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "TextBox 6", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "TextBox 8", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
