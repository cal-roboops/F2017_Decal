#ifndef ARMCONTROLPANEL_H
#define ARMCONTROLPANEL_H

#include <QMainWindow>

namespace Ui {
class ArmControlPanel;
}

class ArmControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArmControlPanel(QWidget *parent = 0);
    ~ArmControlPanel();

public slots:
    void showArmControl(bool en);

private slots:
    void on_setBaseAngleBtn_clicked();
    void on_setBiformAngleBtn_clicked();
    void on_setElbowAngleBtn_clicked();

private:
    Ui::ArmControlPanel *ui;
};

#endif // ARMCONTROLPANEL_H
