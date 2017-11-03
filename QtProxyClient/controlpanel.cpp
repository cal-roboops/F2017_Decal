#include "controlpanel.h"
#include "ui_controlpanel.h"
#include "controlpanel.h"
#include "tank_json.cpp"
#include "mainwindow.h"
#include "mainwindow.cpp"
#include <QMainWindow>
#include <QJsonObject>
#include <QDebug>
#include <QKeyEvent>

ControlPanel::ControlPanel(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);
}

ControlPanel::~ControlPanel()
{
    delete ui;
}
//regular page
void ControlPanel::on_button_set_clicked()
{
    int slider_value = ui->lineEdit_input->text().toInt();
    ui->horizontalSlider->setValue(slider_value);

}

void ControlPanel::on_pushButton_up_pressed()
{
    //move fwd3
}

void ControlPanel::on_pushButton_up_released()
{
    //stop moving fwd
}

void ControlPanel::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ControlPanel::on_radioButton_tank_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    qDebug() << startJ;
}

void ControlPanel::on_radioButton_custom_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// tank page

void ControlPanel::on_radio0_clicked()
{
    qDebug() << zeroJ;
}
void ControlPanel::on_radio45_clicked()
{
    qDebug() << fortyfiveJ;
}
void ControlPanel::on_radio90_clicked()
{
    qDebug() << ninetyJ;
}

void ControlPanel::keyPressEvent(QKeyEvent * event)
{
    if(event-> key() == Qt::Key_W){
        qDebug() << upJ;
    }
    else if(event-> key() == Qt::Key_S){
        qDebug() << downJ;
    }

}
void ControlPanel::keyReleaseEvent(QKeyEvent * event)
{
    if(event-> key() == Qt::Key_W || event-> key() == Qt::Key_S){
        qDebug() << stopJ;
    }

}

void ControlPanel::on_tank_up_pressed()
{
    qDebug() << upJ;
}

void ControlPanel::on_tank_up_released()
{
    qDebug() << stopJ;
}

void ControlPanel::on_tank_down_pressed()
{
    qDebug() << downJ;
}

void ControlPanel::on_tank_down_released()
{
    qDebug() << stopJ;
}
