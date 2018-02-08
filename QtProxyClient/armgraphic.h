#ifndef ARMGRAPHIC_H
#define ARMGRAPHIC_H

#include <QMainWindow>

namespace Ui {
class ArmGraphic;
}

class ArmGraphic : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArmGraphic(QWidget *parent = 0);
    ~ArmGraphic();

private:
    Ui::ArmGraphic *ui;
};

#endif // ARMGRAPHIC_H
