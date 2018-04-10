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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArmGraphic
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsViewARM;
    QLabel *labelBase;
    QLabel *labelMiddle;
    QLabel *labelEnd;
    QSlider *verticalSliderBase;
    QFrame *line;
    QFrame *line_2;
    QSlider *verticalSliderMiddle;
    QSlider *verticalSliderEnd;
    QFrame *line_3;
    QLineEdit *lineEditBase;
    QLineEdit *lineEditMiddle;
    QLineEdit *lineEditEnd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ArmGraphic)
    {
        if (ArmGraphic->objectName().isEmpty())
            ArmGraphic->setObjectName(QStringLiteral("ArmGraphic"));
        ArmGraphic->resize(800, 612);
        centralwidget = new QWidget(ArmGraphic);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsViewARM = new QGraphicsView(centralwidget);
        graphicsViewARM->setObjectName(QStringLiteral("graphicsViewARM"));
        graphicsViewARM->setGeometry(QRect(70, 30, 581, 331));
        labelBase = new QLabel(centralwidget);
        labelBase->setObjectName(QStringLiteral("labelBase"));
        labelBase->setGeometry(QRect(60, 370, 91, 51));
        labelBase->setMaximumSize(QSize(16777215, 51));
        labelBase->setScaledContents(false);
        labelMiddle = new QLabel(centralwidget);
        labelMiddle->setObjectName(QStringLiteral("labelMiddle"));
        labelMiddle->setGeometry(QRect(290, 370, 111, 61));
        labelEnd = new QLabel(centralwidget);
        labelEnd->setObjectName(QStringLiteral("labelEnd"));
        labelEnd->setGeometry(QRect(520, 370, 91, 51));
        verticalSliderBase = new QSlider(centralwidget);
        verticalSliderBase->setObjectName(QStringLiteral("verticalSliderBase"));
        verticalSliderBase->setGeometry(QRect(180, 400, 22, 161));
        verticalSliderBase->setOrientation(Qt::Vertical);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(220, 390, 20, 171));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 370, 691, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        verticalSliderMiddle = new QSlider(centralwidget);
        verticalSliderMiddle->setObjectName(QStringLiteral("verticalSliderMiddle"));
        verticalSliderMiddle->setGeometry(QRect(420, 400, 22, 160));
        verticalSliderMiddle->setOrientation(Qt::Vertical);
        verticalSliderEnd = new QSlider(centralwidget);
        verticalSliderEnd->setObjectName(QStringLiteral("verticalSliderEnd"));
        verticalSliderEnd->setGeometry(QRect(660, 400, 22, 160));
        verticalSliderEnd->setOrientation(Qt::Vertical);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(460, 390, 20, 171));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lineEditBase = new QLineEdit(centralwidget);
        lineEditBase->setObjectName(QStringLiteral("lineEditBase"));
        lineEditBase->setGeometry(QRect(50, 430, 113, 21));
        lineEditMiddle = new QLineEdit(centralwidget);
        lineEditMiddle->setObjectName(QStringLiteral("lineEditMiddle"));
        lineEditMiddle->setGeometry(QRect(280, 430, 113, 20));
        lineEditEnd = new QLineEdit(centralwidget);
        lineEditEnd->setObjectName(QStringLiteral("lineEditEnd"));
        lineEditEnd->setGeometry(QRect(520, 430, 113, 20));
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
#ifndef QT_NO_TOOLTIP
        labelBase->setToolTip(QApplication::translate("ArmGraphic", "<html><head/><body><p><span style=\" font-size:16pt;\">BaseJoint</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelBase->setText(QApplication::translate("ArmGraphic", "<html><head/><body><p><span style=\" font-size:16pt;\">BaseJoint</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelMiddle->setToolTip(QApplication::translate("ArmGraphic", "<html><head/><body><p><span style=\" font-size:16pt;\">MiddleJoint<br/></span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelMiddle->setText(QApplication::translate("ArmGraphic", "<html><head/><body><p><span style=\" font-size:16pt;\">MiddleJoint</span></p></body></html>", Q_NULLPTR));
        labelEnd->setText(QApplication::translate("ArmGraphic", "<html><head/><body><p><span style=\" font-size:16pt;\">EndJoint</span></p></body></html>", Q_NULLPTR));
        lineEditBase->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ArmGraphic: public Ui_ArmGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMGRAPHIC_H
