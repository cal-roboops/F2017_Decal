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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QRadioButton *radio0;
    QRadioButton *radio45;
    QRadioButton *radio90;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(847, 420);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        radio0 = new QRadioButton(centralWidget);
        radio0->setObjectName(QStringLiteral("radio0"));
        radio0->setGeometry(QRect(160, 140, 100, 20));
        radio45 = new QRadioButton(centralWidget);
        radio45->setObjectName(QStringLiteral("radio45"));
        radio45->setGeometry(QRect(310, 140, 100, 20));
        radio90 = new QRadioButton(centralWidget);
        radio90->setObjectName(QStringLiteral("radio90"));
        radio90->setGeometry(QRect(480, 140, 100, 20));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtProxyClient", Q_NULLPTR));
        radio0->setText(QApplication::translate("MainWindow", "0\302\260", Q_NULLPTR));
        radio45->setText(QApplication::translate("MainWindow", "45\302\260", Q_NULLPTR));
        radio90->setText(QApplication::translate("MainWindow", "90\302\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
