/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
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
    QFrame *line;
    QFrame *line_2;
    QMenuBar *menuBar;
    QMenu *menuControls;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QStringLiteral("ControlPanel"));
        ControlPanel->resize(629, 543);
        centralWidget = new QWidget(ControlPanel);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(210, 10, 441, 451));
        regular = new QWidget();
        regular->setObjectName(QStringLiteral("regular"));
        pushButton_up = new QPushButton(regular);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setGeometry(QRect(160, 230, 71, 51));
        QFont font;
        font.setPointSize(14);
        pushButton_up->setFont(font);
        horizontalSlider = new QSlider(regular);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 70, 311, 31));
        horizontalSlider->setMinimum(-45);
        horizontalSlider->setMaximum(45);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(10);
        lineEdit_input = new QLineEdit(regular);
        lineEdit_input->setObjectName(QStringLiteral("lineEdit_input"));
        lineEdit_input->setGeometry(QRect(60, 130, 101, 31));
        button_set = new QPushButton(regular);
        button_set->setObjectName(QStringLiteral("button_set"));
        button_set->setGeometry(QRect(180, 130, 80, 31));
        button_set->setFont(font);
        pushButton_right = new QPushButton(regular);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));
        pushButton_right->setGeometry(QRect(240, 290, 71, 51));
        pushButton_right->setFont(font);
        pushButton_down = new QPushButton(regular);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        pushButton_down->setGeometry(QRect(160, 350, 71, 51));
        pushButton_down->setFont(font);
        pushButton_left = new QPushButton(regular);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));
        pushButton_left->setGeometry(QRect(80, 290, 71, 51));
        pushButton_left->setFont(font);
        label = new QLabel(regular);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 10, 191, 41));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        stackedWidget->addWidget(regular);
        tank = new QWidget();
        tank->setObjectName(QStringLiteral("tank"));
        label_2 = new QLabel(tank);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 151, 31));
        label_2->setFont(font1);
        radio45 = new QRadioButton(tank);
        radio45->setObjectName(QStringLiteral("radio45"));
        radio45->setGeometry(QRect(170, 90, 51, 20));
        radio45->setFont(font);
        radio90 = new QRadioButton(tank);
        radio90->setObjectName(QStringLiteral("radio90"));
        radio90->setGeometry(QRect(280, 90, 61, 20));
        radio90->setFont(font);
        radio0 = new QRadioButton(tank);
        radio0->setObjectName(QStringLiteral("radio0"));
        radio0->setGeometry(QRect(70, 90, 41, 20));
        radio0->setFont(font);
        tank_down = new QPushButton(tank);
        tank_down->setObjectName(QStringLiteral("tank_down"));
        tank_down->setGeometry(QRect(150, 270, 91, 71));
        tank_up = new QPushButton(tank);
        tank_up->setObjectName(QStringLiteral("tank_up"));
        tank_up->setGeometry(QRect(150, 170, 91, 71));
        stackedWidget->addWidget(tank);
        custom = new QWidget();
        custom->setObjectName(QStringLiteral("custom"));
        label_3 = new QLabel(custom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 0, 191, 31));
        label_3->setFont(font1);
        front_left_servo_box = new QTextEdit(custom);
        front_left_servo_box->setObjectName(QStringLiteral("front_left_servo_box"));
        front_left_servo_box->setGeometry(QRect(60, 50, 91, 31));
        middle_left_servo_box = new QTextEdit(custom);
        middle_left_servo_box->setObjectName(QStringLiteral("middle_left_servo_box"));
        middle_left_servo_box->setGeometry(QRect(60, 110, 91, 31));
        back_left_servo_box = new QTextEdit(custom);
        back_left_servo_box->setObjectName(QStringLiteral("back_left_servo_box"));
        back_left_servo_box->setGeometry(QRect(60, 170, 91, 31));
        back_right_servo_box = new QTextEdit(custom);
        back_right_servo_box->setObjectName(QStringLiteral("back_right_servo_box"));
        back_right_servo_box->setGeometry(QRect(260, 170, 91, 31));
        front_right_servo_box = new QTextEdit(custom);
        front_right_servo_box->setObjectName(QStringLiteral("front_right_servo_box"));
        front_right_servo_box->setGeometry(QRect(260, 50, 91, 31));
        middle_right_servo_box = new QTextEdit(custom);
        middle_right_servo_box->setObjectName(QStringLiteral("middle_right_servo_box"));
        middle_right_servo_box->setGeometry(QRect(260, 110, 91, 31));
        button_submit_servo = new QPushButton(custom);
        button_submit_servo->setObjectName(QStringLiteral("button_submit_servo"));
        button_submit_servo->setGeometry(QRect(100, 390, 221, 61));
        QFont font2;
        font2.setPointSize(12);
        button_submit_servo->setFont(font2);
        button_left_up = new QPushButton(custom);
        button_left_up->setObjectName(QStringLiteral("button_left_up"));
        button_left_up->setGeometry(QRect(110, 230, 41, 31));
        button_left_up->setFont(font2);
        button_left_up_down = new QPushButton(custom);
        button_left_up_down->setObjectName(QStringLiteral("button_left_up_down"));
        button_left_up_down->setGeometry(QRect(110, 280, 41, 31));
        button_left_up_down->setFont(font2);
        button_left_down = new QPushButton(custom);
        button_left_down->setObjectName(QStringLiteral("button_left_down"));
        button_left_down->setGeometry(QRect(110, 330, 41, 31));
        button_left_down->setFont(font2);
        button_middle_down_down = new QPushButton(custom);
        button_middle_down_down->setObjectName(QStringLiteral("button_middle_down_down"));
        button_middle_down_down->setGeometry(QRect(180, 330, 41, 31));
        button_middle_down_down->setFont(font2);
        button_right_down = new QPushButton(custom);
        button_right_down->setObjectName(QStringLiteral("button_right_down"));
        button_right_down->setGeometry(QRect(250, 330, 41, 31));
        button_right_down->setFont(font2);
        button_right_down_up = new QPushButton(custom);
        button_right_down_up->setObjectName(QStringLiteral("button_right_down_up"));
        button_right_down_up->setGeometry(QRect(250, 280, 41, 31));
        button_right_down_up->setFont(font2);
        button_right_up = new QPushButton(custom);
        button_right_up->setObjectName(QStringLiteral("button_right_up"));
        button_right_up->setGeometry(QRect(250, 230, 41, 31));
        button_right_up->setFont(font2);
        button_middle_up_up = new QPushButton(custom);
        button_middle_up_up->setObjectName(QStringLiteral("button_middle_up_up"));
        button_middle_up_up->setGeometry(QRect(180, 230, 41, 31));
        button_middle_up_up->setFont(font2);
        stackedWidget->addWidget(custom);
        label_3->raise();
        front_left_servo_box->raise();
        middle_left_servo_box->raise();
        back_left_servo_box->raise();
        back_right_servo_box->raise();
        front_right_servo_box->raise();
        middle_right_servo_box->raise();
        button_submit_servo->raise();
        button_left_up->raise();
        button_left_up_down->raise();
        button_left_down->raise();
        button_middle_down_down->raise();
        button_right_down->raise();
        button_right_down_up->raise();
        button_right_up->raise();
        button_middle_up_up->raise();
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 40, 101, 31));
        radioButton->setFont(font);
        radioButton->setChecked(true);
        radioButton_tank = new QRadioButton(centralWidget);
        radioButton_tank->setObjectName(QStringLiteral("radioButton_tank"));
        radioButton_tank->setGeometry(QRect(40, 100, 100, 22));
        radioButton_tank->setFont(font);
        radioButton_custom = new QRadioButton(centralWidget);
        radioButton_custom->setObjectName(QStringLiteral("radioButton_custom"));
        radioButton_custom->setGeometry(QRect(40, 160, 100, 22));
        radioButton_custom->setFont(font);
        horizontalSlider_speed = new QSlider(centralWidget);
        horizontalSlider_speed->setObjectName(QStringLiteral("horizontalSlider_speed"));
        horizontalSlider_speed->setGeometry(QRect(20, 360, 161, 31));
        horizontalSlider_speed->setMaximum(100);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);
        pushButton_submit = new QPushButton(centralWidget);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));
        pushButton_submit->setGeometry(QRect(50, 410, 101, 31));
        pushButton_submit->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 310, 81, 31));
        QFont font3;
        font3.setPointSize(16);
        label_4->setFont(font3);
        speed_label = new QLabel(centralWidget);
        speed_label->setObjectName(QStringLiteral("speed_label"));
        speed_label->setGeometry(QRect(120, 310, 31, 31));
        speed_label->setFont(font3);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(190, 0, 20, 481));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 470, 631, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        ControlPanel->setCentralWidget(centralWidget);
        radioButton_custom->raise();
        stackedWidget->raise();
        radioButton->raise();
        radioButton_tank->raise();
        horizontalSlider_speed->raise();
        pushButton_submit->raise();
        label_4->raise();
        speed_label->raise();
        line->raise();
        line_2->raise();
        menuBar = new QMenuBar(ControlPanel);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 26));
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
        label_4->setText(QApplication::translate("ControlPanel", "Speed:", Q_NULLPTR));
        speed_label->setText(QApplication::translate("ControlPanel", "0", Q_NULLPTR));
        menuControls->setTitle(QApplication::translate("ControlPanel", "Controls", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
