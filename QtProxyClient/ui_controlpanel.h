/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *regular;
    QPushButton *pushButton_up;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit_input;
    QPushButton *button_set;
    QPushButton *pushButton_right;
    QPushButton *pushButton_down;
    QPushButton *pushButton_left;
    QLabel *label;
    QWidget *tank;
    QLabel *label_2;
    QRadioButton *radio45;
    QRadioButton *radio90;
    QRadioButton *radio0;
    QPushButton *tank_down;
    QPushButton *tank_up;
    QWidget *custom;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_tank;
    QRadioButton *radioButton_custom;
    QMenuBar *menuBar;
    QMenu *menuControls;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QStringLiteral("ControlPanel"));
        ControlPanel->resize(617, 427);
        centralWidget = new QWidget(ControlPanel);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(170, 0, 441, 371));
        regular = new QWidget();
        regular->setObjectName(QStringLiteral("regular"));
        pushButton_up = new QPushButton(regular);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setGeometry(QRect(180, 140, 71, 51));
        horizontalSlider = new QSlider(regular);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 50, 301, 20));
        horizontalSlider->setMinimum(-45);
        horizontalSlider->setMaximum(45);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(10);
        lineEdit_input = new QLineEdit(regular);
        lineEdit_input->setObjectName(QStringLiteral("lineEdit_input"));
        lineEdit_input->setGeometry(QRect(130, 80, 91, 31));
        button_set = new QPushButton(regular);
        button_set->setObjectName(QStringLiteral("button_set"));
        button_set->setGeometry(QRect(230, 80, 80, 24));
        pushButton_right = new QPushButton(regular);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));
        pushButton_right->setGeometry(QRect(250, 190, 71, 51));
        pushButton_down = new QPushButton(regular);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        pushButton_down->setGeometry(QRect(180, 240, 71, 51));
        pushButton_left = new QPushButton(regular);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));
        pushButton_left->setGeometry(QRect(110, 190, 71, 51));
        label = new QLabel(regular);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 131, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        stackedWidget->addWidget(regular);
        tank = new QWidget();
        tank->setObjectName(QStringLiteral("tank"));
        label_2 = new QLabel(tank);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 131, 21));
        label_2->setFont(font);
        radio45 = new QRadioButton(tank);
        radio45->setObjectName(QStringLiteral("radio45"));
        radio45->setGeometry(QRect(180, 70, 41, 20));
        radio90 = new QRadioButton(tank);
        radio90->setObjectName(QStringLiteral("radio90"));
        radio90->setGeometry(QRect(270, 70, 41, 20));
        radio0 = new QRadioButton(tank);
        radio0->setObjectName(QStringLiteral("radio0"));
        radio0->setGeometry(QRect(90, 70, 41, 20));
        tank_down = new QPushButton(tank);
        tank_down->setObjectName(QStringLiteral("tank_down"));
        tank_down->setGeometry(QRect(170, 230, 71, 51));
        tank_up = new QPushButton(tank);
        tank_up->setObjectName(QStringLiteral("tank_up"));
        tank_up->setGeometry(QRect(170, 160, 71, 51));
        stackedWidget->addWidget(tank);
        custom = new QWidget();
        custom->setObjectName(QStringLiteral("custom"));
        label_3 = new QLabel(custom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 131, 21));
        label_3->setFont(font);
        stackedWidget->addWidget(custom);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 60, 100, 22));
        radioButton->setChecked(true);
        radioButton_tank = new QRadioButton(centralWidget);
        radioButton_tank->setObjectName(QStringLiteral("radioButton_tank"));
        radioButton_tank->setGeometry(QRect(40, 160, 100, 22));
        radioButton_custom = new QRadioButton(centralWidget);
        radioButton_custom->setObjectName(QStringLiteral("radioButton_custom"));
        radioButton_custom->setGeometry(QRect(40, 260, 100, 22));
        ControlPanel->setCentralWidget(centralWidget);
        radioButton_custom->raise();
        stackedWidget->raise();
        radioButton->raise();
        radioButton_tank->raise();
        menuBar = new QMenuBar(ControlPanel);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 22));
        menuControls = new QMenu(menuBar);
        menuControls->setObjectName(QStringLiteral("menuControls"));
        ControlPanel->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ControlPanel);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ControlPanel->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ControlPanel);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ControlPanel->setStatusBar(statusBar);

        menuBar->addAction(menuControls->menuAction());

        retranslateUi(ControlPanel);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QMainWindow *ControlPanel)
    {
        ControlPanel->setWindowTitle(QApplication::translate("ControlPanel", "MainWindow", Q_NULLPTR));
        pushButton_up->setText(QApplication::translate("ControlPanel", "Up", Q_NULLPTR));
        button_set->setText(QApplication::translate("ControlPanel", "Set", Q_NULLPTR));
        pushButton_right->setText(QApplication::translate("ControlPanel", "Right", Q_NULLPTR));
        pushButton_down->setText(QApplication::translate("ControlPanel", "Down", Q_NULLPTR));
        pushButton_left->setText(QApplication::translate("ControlPanel", "Left", Q_NULLPTR));
        label->setText(QApplication::translate("ControlPanel", "Regular Mode", Q_NULLPTR));
        label_2->setText(QApplication::translate("ControlPanel", "Tank Mode", Q_NULLPTR));
        radio45->setText(QApplication::translate("ControlPanel", "45", Q_NULLPTR));
        radio90->setText(QApplication::translate("ControlPanel", "90", Q_NULLPTR));
        radio0->setText(QApplication::translate("ControlPanel", "0", Q_NULLPTR));
        tank_down->setText(QApplication::translate("ControlPanel", "Down", Q_NULLPTR));
        tank_up->setText(QApplication::translate("ControlPanel", "Up", Q_NULLPTR));
        label_3->setText(QApplication::translate("ControlPanel", "Custom Mode", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ControlPanel", "Regular", Q_NULLPTR));
        radioButton_tank->setText(QApplication::translate("ControlPanel", "Tank", Q_NULLPTR));
        radioButton_custom->setText(QApplication::translate("ControlPanel", "Custom", Q_NULLPTR));
        menuControls->setTitle(QApplication::translate("ControlPanel", "Controls", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
