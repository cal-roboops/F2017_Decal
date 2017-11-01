#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonObject>
#include <QDebug>
#include <QKeyEvent>
//#include <windows.h>

// change

QJsonObject startJ
{ 
    {"DT_M_RD", 0},
    {"DT_M_LD", 0},
    {"DT_S_FL", 0},
    {"DT_S_FR", 0},
    {"DT_S_ML", 0},
    {"DT_S_MR", 0},
    {"DT_S_BL", 0},
    {"DT_S_BR", 0},
};
QJsonObject zeroJ
{
    {"DT_S_FL", 0},
    {"DT_S_FR", 0},
    {"DT_S_ML", 0},
    {"DT_S_MR", 0},
    {"DT_S_BL", 0},
    {"DT_S_BR", 0},
};
QJsonObject fortyfiveJ
{
    {"DT_S_FL", 45},
    {"DT_S_FR", -45},
    {"DT_S_ML", 0},
    {"DT_S_MR", 0},
    {"DT_S_BL", 45},
    {"DT_S_BR", -45},
};
QJsonObject ninetyJ
{
    {"DT_S_FL", 90},
    {"DT_S_FR", 90},
    {"DT_S_ML", 90},
    {"DT_S_MR", 90},
    {"DT_S_BL", 90},
    {"DT_S_BR", 90},
};
QJsonObject upJ
{
    {"DT_M_RD", 1},
    {"DT_M_LD", 1},
};
QJsonObject downJ
{
    {"DT_M_RD", 0},
    {"DT_M_LD", 0},
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup & create basics
    ui->setupUi(this);
    qDebug() << startJ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radio0_clicked()
{
    qDebug() << zeroJ;
}
void MainWindow::on_radio45_clicked()
{
    qDebug() << fortyfiveJ;
}
void MainWindow::on_radio90_clicked()
{
    qDebug() << ninetyJ;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event-> key() == Qt::Key_W){
        qDebug() << upJ;
    }
    else if(event-> key() == Qt::Key_S){
        qDebug() << downJ;
    }

}

//    switch (event->key())
//    {
//    case Qt::Key_W:
//        QJsonObject ball;
//        ball[0] = "up";
//        qDebug() << ball;
//        return true;
//    case Qt::Key_Return:
//        QJsonObject ball2;
//        ball2[0] = "down";
//        qDebug() << ball2;
//        return true;
//    }
