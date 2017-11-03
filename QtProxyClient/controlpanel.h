#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include <QMainWindow>

namespace Ui {
class ControlPanel;
}

class ControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = 0);
    ~ControlPanel();


private slots:

    void on_button_set_clicked();

    void on_pushButton_up_pressed();

    void on_pushButton_up_released();

    void on_radioButton_clicked();

    void on_radioButton_tank_clicked();

    void on_radioButton_custom_clicked();

    void on_radio0_clicked();
    void on_radio45_clicked();
    void on_radio90_clicked();

    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void on_tank_up_pressed();

    void on_tank_up_released();

    void on_tank_down_pressed();

    void on_tank_down_released();

private:
    Ui::ControlPanel *ui;
};

#endif // CONTROLPANEL_H
