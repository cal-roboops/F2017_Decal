#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

void MainWindow::on_radioButton_custom_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
