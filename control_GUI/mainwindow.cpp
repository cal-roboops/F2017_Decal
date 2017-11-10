#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tank_json.cpp"

#include <QJsonObject>
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//regular page
void MainWindow::on_button_set_clicked()
{
    int slider_value = ui->lineEdit_input->text().toInt();
//    if (slider_value > 45 || slider_value < -45){

//    }
    ui->horizontalSlider->setValue(slider_value);

}

void MainWindow::on_pushButton_up_pressed()
{
    //move fwd3
}

void MainWindow::on_pushButton_up_released()
{
    //stop moving fwd
}

void MainWindow::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioButton_tank_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    qDebug() << startJ;
}

void MainWindow::on_radioButton_custom_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// tank page

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
void MainWindow::on_tank_up_clicked()
{
    qDebug() << upJ;
}
void MainWindow::on_tank_down_clicked()
{
    qDebug() << downJ;
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
