#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void closeEvent(QCloseEvent *event);

signals:
    void server_start();
    void server_terminate();

public slots:
    void update_client_count(int val);
    void rover_connected(bool en);

private slots:
    void on_serverOn_clicked();
    void on_serverOff_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
