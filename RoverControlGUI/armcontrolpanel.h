#ifndef ARMCONTROLPANEL_H
#define ARMCONTROLPANEL_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QQuickView>

namespace Ui {
class ArmControlPanel;
}

class ArmControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArmControlPanel(QWidget *parent = 0);
    ~ArmControlPanel();
    virtual void closeEvent(QCloseEvent *event);

signals:
    void closed();
    void send_data(std::list<uint8_t> data);

public slots:
    void enableArmControl(bool en);
    void showArmControl(bool en);

private slots:
    void on_setArm_button_clicked();

private:
    Ui::ArmControlPanel *ui;
    QQuickView *arm_qml;
    QObject *arm_ritem;

    bool isEnabled;

    void transmit_command(std::list<uint8_t> kv);
};

#endif // ARMCONTROLPANEL_H
