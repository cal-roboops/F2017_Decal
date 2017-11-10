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
#include <QtWidgets/QTextEdit>
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
    QTextEdit *front_left_servo_box;
    QTextEdit *middle_left_servo_box;
    QTextEdit *back_left_servo_box;
    QTextEdit *back_right_servo_box;
    QTextEdit *front_right_servo_box;
    QTextEdit *middle_right_servo_box;
    QPushButton *button_submit_servo;
    QPushButton *button_left_up;
    QPushButton *button_left_up_down;
    QPushButton *button_left_down;
    QPushButton *button_middle_down_down;
    QPushButton *button_right_down;
    QPushButton *button_right_down_up;
    QPushButton *button_right_up;
    QPushButton *button_middle_up_up;
    QRadioButton *radioButton;
    QRadioButton *radioButton_tank;
    QRadioButton *radioButton_custom;
    QSlider *horizontalSlider_speed;
    QPushButton *pushButton_submit;
    QLabel *label_4;
    QLabel *speed_label;
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
        stackedWidget->setGeometry(QRect(180, 0, 441, 371));
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
        front_left_servo_box = new QTextEdit(custom);
        front_left_servo_box->setObjectName(QStringLiteral("front_left_servo_box"));
        front_left_servo_box->setGeometry(QRect(60, 40, 81, 31));
        middle_left_servo_box = new QTextEdit(custom);
        middle_left_servo_box->setObjectName(QStringLiteral("middle_left_servo_box"));
        middle_left_servo_box->setGeometry(QRect(60, 90, 81, 31));
        back_left_servo_box = new QTextEdit(custom);
        back_left_servo_box->setObjectName(QStringLiteral("back_left_servo_box"));
        back_left_servo_box->setGeometry(QRect(60, 140, 81, 31));
        back_right_servo_box = new QTextEdit(custom);
        back_right_servo_box->setObjectName(QStringLiteral("back_right_servo_box"));
        back_right_servo_box->setGeometry(QRect(260, 140, 81, 31));
        front_right_servo_box = new QTextEdit(custom);
        front_right_servo_box->setObjectName(QStringLiteral("front_right_servo_box"));
        front_right_servo_box->setGeometry(QRect(260, 40, 81, 31));
        middle_right_servo_box = new QTextEdit(custom);
        middle_right_servo_box->setObjectName(QStringLiteral("middle_right_servo_box"));
        middle_right_servo_box->setGeometry(QRect(260, 90, 81, 31));
        button_submit_servo = new QPushButton(custom);
        button_submit_servo->setObjectName(QStringLiteral("button_submit_servo"));
        button_submit_servo->setGeometry(QRect(120, 300, 171, 61));
        button_left_up = new QPushButton(custom);
        button_left_up->setObjectName(QStringLiteral("button_left_up"));
        button_left_up->setGeometry(QRect(120, 180, 41, 31));
        button_left_up_down = new QPushButton(custom);
        button_left_up_down->setObjectName(QStringLiteral("button_left_up_down"));
        button_left_up_down->setGeometry(QRect(120, 220, 41, 31));
        button_left_down = new QPushButton(custom);
        button_left_down->setObjectName(QStringLiteral("button_left_down"));
        button_left_down->setGeometry(QRect(120, 260, 41, 31));
        button_middle_down_down = new QPushButton(custom);
        button_middle_down_down->setObjectName(QStringLiteral("button_middle_down_down"));
        button_middle_down_down->setGeometry(QRect(190, 260, 41, 31));
        button_right_down = new QPushButton(custom);
        button_right_down->setObjectName(QStringLiteral("button_right_down"));
        button_right_down->setGeometry(QRect(260, 260, 41, 31));
        button_right_down_up = new QPushButton(custom);
        button_right_down_up->setObjectName(QStringLiteral("button_right_down_up"));
        button_right_down_up->setGeometry(QRect(260, 220, 41, 31));
        button_right_up = new QPushButton(custom);
        button_right_up->setObjectName(QStringLiteral("button_right_up"));
        button_right_up->setGeometry(QRect(260, 180, 41, 31));
        button_middle_up_up = new QPushButton(custom);
        button_middle_up_up->setObjectName(QStringLiteral("button_middle_up_up"));
        button_middle_up_up->setGeometry(QRect(190, 180, 41, 31));
        stackedWidget->addWidget(custom);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 60, 100, 22));
        radioButton->setChecked(true);
        radioButton_tank = new QRadioButton(centralWidget);
        radioButton_tank->setObjectName(QStringLiteral("radioButton_tank"));
        radioButton_tank->setGeometry(QRect(40, 110, 100, 22));
        radioButton_custom = new QRadioButton(centralWidget);
        radioButton_custom->setObjectName(QStringLiteral("radioButton_custom"));
        radioButton_custom->setGeometry(QRect(40, 170, 100, 22));
        horizontalSlider_speed = new QSlider(centralWidget);
        horizontalSlider_speed->setObjectName(QStringLiteral("horizontalSlider_speed"));
        horizontalSlider_speed->setGeometry(QRect(20, 270, 160, 16));
        horizontalSlider_speed->setMaximum(100);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);
        pushButton_submit = new QPushButton(centralWidget);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));
        pushButton_submit->setGeometry(QRect(60, 300, 80, 24));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 250, 60, 16));
        speed_label = new QLabel(centralWidget);
        speed_label->setObjectName(QStringLiteral("speed_label"));
        speed_label->setGeometry(QRect(80, 250, 60, 16));
        ControlPanel->setCentralWidget(centralWidget);
        radioButton_custom->raise();
        stackedWidget->raise();
        radioButton->raise();
        radioButton_tank->raise();
        horizontalSlider_speed->raise();
        pushButton_submit->raise();
        label_4->raise();
        speed_label->raise();
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

        stackedWidget->setCurrentIndex(0);


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
        button_submit_servo->setText(QApplication::translate("ControlPanel", "Submit Servo Positions", Q_NULLPTR));
        button_left_up->setText(QApplication::translate("ControlPanel", "\342\206\221", Q_NULLPTR));
        button_left_up_down->setText(QApplication::translate("ControlPanel", "\342\206\221\342\206\223", Q_NULLPTR));
        button_left_down->setText(QApplication::translate("ControlPanel", "\342\206\223", Q_NULLPTR));
        button_middle_down_down->setText(QApplication::translate("ControlPanel", "\342\206\223\342\206\223", Q_NULLPTR));
        button_right_down->setText(QApplication::translate("ControlPanel", "\342\206\223", Q_NULLPTR));
        button_right_down_up->setText(QApplication::translate("ControlPanel", "\342\206\223\342\206\221", Q_NULLPTR));
        button_right_up->setText(QApplication::translate("ControlPanel", "\342\206\221", Q_NULLPTR));
        button_middle_up_up->setText(QApplication::translate("ControlPanel", "\342\206\221\342\206\221", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ControlPanel", "Regular", Q_NULLPTR));
        radioButton_tank->setText(QApplication::translate("ControlPanel", "Tank", Q_NULLPTR));
        radioButton_custom->setText(QApplication::translate("ControlPanel", "Custom", Q_NULLPTR));
        pushButton_submit->setText(QApplication::translate("ControlPanel", "Submit", Q_NULLPTR));
        label_4->setText(QApplication::translate("ControlPanel", "Speed", Q_NULLPTR));
        speed_label->setText(QApplication::translate("ControlPanel", "0", Q_NULLPTR));
        menuControls->setTitle(QApplication::translate("ControlPanel", "Controls", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
