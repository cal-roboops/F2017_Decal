#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_button_set_clicked();

    void on_pushButton_up_pressed();

    void on_pushButton_up_released();

    void on_radioButton_clicked();

    void on_radioButton_tank_clicked();

    void on_radioButton_custom_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
