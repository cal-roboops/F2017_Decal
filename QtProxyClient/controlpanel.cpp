#include "controlpanel.h"
#include "ui_controlpanel.h"
#include "controlpanel.h"
#include "tank_json.cpp"
#include "mainwindow.h"
#include "mainwindow.cpp"
#include "regular_json.cpp"
#include <QMainWindow>
#include <QJsonObject>
#include <QDebug>
#include <QKeyEvent>
#include <QJsonDocument>
#include <QMessageBox>
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

void ControlPanel::format_JSON(QJsonObject input) //formates JSON Object
{
    QJsonDocument doc(input);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    qDebug() << strJson;
}

/*
 * Radio Button Page Switchers
 * */

void ControlPanel::on_radioButton_clicked() //set controls to regular
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->horizontalSlider->setValue(0); //set slider value to 0
    QJsonObject input;
    input["DT_M_R"] = 0;
    input["DT_M_L"] = 0;
    input["DT_M_FL"] = 0;
    input["DT_M_FR"] = 0;
    input["DT_M_ML"] = 0;
    input["DT_M_MR"] = 0;
    input["DT_M_BL"] = 0;
    input["DT_M_BR"] = 0;
    format_JSON(input);

}

void ControlPanel::on_radioButton_tank_clicked() //set controls to tank
{
    ui->stackedWidget->setCurrentIndex(1);
    QJsonObject input;
    input["DT_M_RD"] = 0;
    input["DT_M_LD"] = 0;
    input["DT_M_FL"] = 0;
    input["DT_M_FR"] = 0;
    input["DT_M_ML"] = 0;
    input["DT_M_MR"] = 0;
    input["DT_M_BL"] = 0;
    input["DT_M_BR"] = 0;
    format_JSON(input);

}

void ControlPanel::on_radioButton_custom_clicked() //set controls to custom
{
    ui->stackedWidget->setCurrentIndex(2);

    ui->front_left_servo_box->setText("0"); //set default values to 0
    ui->middle_left_servo_box->setText("0");
    ui->back_left_servo_box->setText("0");
    ui->front_right_servo_box->setText("0");
    ui->middle_right_servo_box->setText("0");
    ui->back_right_servo_box->setText("0");

    QJsonObject input;
    input["DT_M_R"] = 0;
    input["DT_M_L"] = 0;
    input["DT_M_FL"] = 0;
    input["DT_M_FR"] = 0;
    input["DT_M_ML"] = 0;
    input["DT_M_MR"] = 0;
    input["DT_M_BL"] = 0;
    input["DT_M_BR"] = 0;
    format_JSON(input);
}

/*
 * Regular Page
 * */

void ControlPanel::on_button_set_clicked() //slider button
{
    int slider_value = ui->lineEdit_input->text().toInt();
    ui->horizontalSlider->setValue(slider_value);

    QJsonObject input;
    input["DT_S_FR"] = slider_value;
    input["DT_S_FL"] = slider_value;
    format_JSON(input);
}

void ControlPanel::on_pushButton_up_pressed()
{
    QJsonObject input;
    input["DT_M_LD"] = 1;
    input["DT_M_RD"] = 1;
    format_JSON(input);
}

void ControlPanel::on_pushButton_up_released()
{
    QJsonObject input;
    input["DT_M_LD"] = 0;
    input["DT_M_RD"] = 0;
    format_JSON(input);
}

void ControlPanel::on_pushButton_down_pressed()
{
    QJsonObject input;
    input["DT_M_LD"] = -1;
    input["DT_M_RD"] = -1;
    format_JSON(input);
}

void ControlPanel::on_pushButton_down_released()
{
    QJsonObject input;
    input["DT_M_LD"] = 0;
    input["DT_M_RD"] = 0;
    format_JSON(input);
}


void ControlPanel::on_pushButton_right_clicked()
{
    int slider_value = ui->horizontalSlider->value() + 5;
    ui->horizontalSlider->setValue(slider_value );
    QJsonObject input;
    input["DT_S_FR"] = slider_value;
    input["DT_S_FL"] = slider_value;
    format_JSON(input);
}

void ControlPanel::on_pushButton_left_clicked()
{
    int slider_value = ui->horizontalSlider->value() - 5;
    ui->horizontalSlider->setValue(slider_value);
    QJsonObject input;
    input["DT_S_FR"] = slider_value;
    input["DT_S_FL"] = slider_value;
    format_JSON(input);
}

/*
 * Tank Page
 * */

void ControlPanel::on_radio0_clicked()
{
    QJsonObject input;
    input["DT_S_FL"] = 0;
    input["DT_S_FR"] = 0;
    input["DT_S_ML"] = 0;
    input["DT_S_MR"] = 0;
    input["DT_S_BL"] = 0;
    input["DT_S_BR"] = 0;
    format_JSON(input);
}
void ControlPanel::on_radio45_clicked()
{
    QJsonObject input;
    input["DT_S_FL"] = -45;
    input["DT_S_FR"] = 45;
    input["DT_S_ML"] = 0;
    input["DT_S_MR"] = 0;
    input["DT_S_BL"] = 45;
    input["DT_S_BR"] = -45;
    format_JSON(input);
}
void ControlPanel::on_radio90_clicked()
{
    QJsonObject input;
    input["DT_S_FL"] = 90;
    input["DT_S_FR"] = 90;
    input["DT_S_ML"] = 90;
    input["DT_S_MR"] = 90;
    input["DT_S_BL"] = 90;
    input["DT_S_BR"] = 90;
    format_JSON(input);
}


void ControlPanel::on_tank_up_pressed()
{
    QJsonObject input;
    input["DT_M_LD"] = 1;
    input["DT_M_RD"] = 1;
    format_JSON(input);
}

void ControlPanel::on_tank_up_released()
{
    QJsonObject input;
    input["DT_M_LD"] = 0;
    input["DT_M_RD"] = 0;
    format_JSON(input);
}

void ControlPanel::on_tank_down_pressed()
{
    QJsonObject input;
    input["DT_M_LD"] = -1;
    input["DT_M_RD"] = -1;
    format_JSON(input);
}

void ControlPanel::on_tank_down_released()
{
    QJsonObject input;
    input["DT_M_LD"] = 0;
    input["DT_M_RD"] = 0;
    format_JSON(input);
}

void ControlPanel::on_pushButton_submit_clicked()
{
     int value = ui->horizontalSlider_speed->value();
     QJsonObject input;
     input["DT_M_S"] = value;
     format_JSON(input);
}



/*
 * Key Handlers
 * */

void ControlPanel::keyPressEvent(QKeyEvent * event)
{
    if(event-> key() == Qt::Key_W){
        ControlPanel::on_pushButton_up_pressed();
    }
    else if(event-> key() == Qt::Key_S){
        ControlPanel::on_pushButton_down_pressed();
    }
    else if(event-> key() == Qt::Key_D && ui->stackedWidget->currentIndex() == 0){ //enables D and A key only on regular page
        ControlPanel::on_pushButton_right_clicked();
    }
    else if(event-> key() == Qt::Key_A && ui->stackedWidget->currentIndex() == 0){
        ControlPanel::on_pushButton_left_clicked();
    }

}
void ControlPanel::keyReleaseEvent(QKeyEvent * event)
{
    if (event->isAutoRepeat()) {
        ControlPanel::keyPressEvent(event);
    }
    else {
        if(event-> key() == Qt::Key_W){
            ControlPanel::on_pushButton_up_released();
        }
        else if(event-> key() == Qt::Key_S){
            ControlPanel::on_pushButton_down_released();
        }
        else if(event-> key() == Qt::Key_D && ui->stackedWidget->currentIndex() == 0){
            ControlPanel::on_pushButton_right_clicked();
        }
        else if(event-> key() == Qt::Key_A && ui->stackedWidget->currentIndex() == 0){
            ControlPanel::on_pushButton_left_clicked();
        }
    }

}

/*
 *
 * Custom Control Page
 *
 * */

void ControlPanel::on_button_submit_servo_clicked()
{
    /*
     * A button labeled “Submit Servo Positions”
 If: a value outside of the range [-90, 90] exists (in any of the textboxes) when
the user clicks (presses and releases) “Submit Servo Positions”, all textboxes should
return to their previous value and a message flashes to the user stating
“Values need to be within the range: [-90, 90]”. Nothing should be sent; abort.

 Else: when this button is clicked (pressed and released) and all the textboxes
 contain a value in the range [-90, 90], a JSON object containing the following
key-value pairs should be created and passed into the client:

 DT_S_FL: <value of textbox 1>
 DT_S_ML: <value of textbox 2>
 DT_S_BL: <value of textbox 3>
 DT_S_FR: <value of textbox 4>
 DT_S_MR: <value of textbox 5>
 DT_S_BR: <value of textbox 6>
*/
    int tb1 = ui->front_left_servo_box->toPlainText().toInt();
    int tb2 = ui->middle_left_servo_box->toPlainText().toInt();
    int tb3 = ui->back_left_servo_box->toPlainText().toInt();
    int tb4 = ui->front_right_servo_box->toPlainText().toInt();
    int tb5 = ui->middle_right_servo_box->toPlainText().toInt();
    int tb6 = ui->back_right_servo_box->toPlainText().toInt();

    if (tb1 > 90 || tb1 < -90 || tb2 > 90 || tb2 < -90 || tb3 > 90 || tb3 < -90 || tb4 > 90 || tb4 < -90 || tb5 > 90 || tb5 <- 90 || tb6 > 90 || tb6 < -90){
        qDebug() << "Values need to be within the range: [-90, 90]";
    }
    else{
        QJsonObject input;
        input["DT_S_FL"] = tb1;
        input["DT_S_ML"] = tb2;
        input["DT_S_BL"] = tb3;
        input["DT_S_FR"] = tb4;
        input["DT_S_MR"] = tb5;
        input["DT_S_BR"] = tb6;
        format_JSON(input);
    }
}

void ControlPanel::on_button_left_up_pressed() //button 1 press
{
    QJsonObject input;
    input["DT_M_L"] = 1;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_left_up_released() //button 1 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_left_up_down_pressed() //button 2 pressed
{
    QJsonObject input;
    input["DT_M_L"] = 1;
    input["DT_M_R"] = -1;
    format_JSON(input);
}

void ControlPanel::on_button_left_up_down_released() //button 2 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_left_down_pressed() //button 3 pressed
{
    QJsonObject input;
    input["DT_M_L"] = -1;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_left_down_released() //button 3 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_right_up_pressed() //button 4 pressed
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 1;
    format_JSON(input);
}

void ControlPanel::on_button_right_up_released() //button 4 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_right_down_up_pressed() //button 5 pressed
{
    QJsonObject input;
    input["DT_M_L"] = -1;
    input["DT_M_R"] = 1;
    format_JSON(input);
}

void ControlPanel::on_button_right_down_up_released() //button 5 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_right_down_pressed() //button 6 pressed
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = -1;
    format_JSON(input);
}

void ControlPanel::on_button_right_down_released() //button 6 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_middle_up_up_pressed() //button 7 pressed
{
    QJsonObject input;
    input["DT_M_L"] = 1;
    input["DT_M_R"] = 1;
    format_JSON(input);
}

void ControlPanel::on_button_middle_up_up_released() //button 7 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_button_middle_down_down_pressed() //button 8 pressed
{
    QJsonObject input;
    input["DT_M_L"] = -1;
    input["DT_M_R"] = 1;
    format_JSON(input);
}

void ControlPanel::on_button_middle_down_down_released() //button 8 released
{
    QJsonObject input;
    input["DT_M_L"] = 0;
    input["DT_M_R"] = 0;
    format_JSON(input);
}

void ControlPanel::on_horizontalSlider_speed_sliderPressed() //updates speed slider label
{
    int x = ui->horizontalSlider_speed->value();
    QString s = QString::number(x);
    ui->speed_label->setText(s);
}

void ControlPanel::on_horizontalSlider_speed_sliderReleased()
{
    int x = ui->horizontalSlider_speed->value();
    QString s = QString::number(x);
    ui->speed_label->setText(s);
}
