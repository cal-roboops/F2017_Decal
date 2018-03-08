/********************************************************************************
** Form generated from reading UI file 'armgraphic.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMGRAPHIC_H
#define UI_ARMGRAPHIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArmGraphic
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ArmGraphic)
    {
        if (ArmGraphic->objectName().isEmpty())
            ArmGraphic->setObjectName(QStringLiteral("ArmGraphic"));
        ArmGraphic->resize(800, 600);
        centralwidget = new QWidget(ArmGraphic);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 20, 71, 16));
        ArmGraphic->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ArmGraphic);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ArmGraphic->setMenuBar(menubar);
        statusbar = new QStatusBar(ArmGraphic);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ArmGraphic->setStatusBar(statusbar);

        retranslateUi(ArmGraphic);

        QMetaObject::connectSlotsByName(ArmGraphic);
    } // setupUi

    void retranslateUi(QMainWindow *ArmGraphic)
    {
        ArmGraphic->setWindowTitle(QApplication::translate("ArmGraphic", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("ArmGraphic", "Arm Graphic", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ArmGraphic: public Ui_ArmGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMGRAPHIC_H
