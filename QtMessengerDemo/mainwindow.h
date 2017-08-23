#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

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
    void on_button1_clicked();
    void on_submitData_clicked();

private:
    Ui::MainWindow *ui;
    QTextEdit *data;
};

#endif // MAINWINDOW_H
