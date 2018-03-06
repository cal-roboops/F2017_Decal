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

private:
    Ui::ArmControlPanel *ui;
};

#endif // ARMCONTROLPANEL_H
