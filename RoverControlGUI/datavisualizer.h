#ifndef DATAVISUALIZER_H
#define DATAVISUALIZER_H

#include <QMainWindow>
#include <QGridLayout>
#include <QtCharts>
#include <QList>


namespace Ui {
class DataVisualizer;
}

class DataVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataVisualizer(QWidget *parent = 0);
    ~DataVisualizer();
    virtual void closeEvent(QCloseEvent *event);

signals:
    void closed();

public slots:
    void showDataVisualizer(bool en);
    void on_addDataPointsBtn_clicked();
    void on_removeActiveEncoderBtn_clicked();
    void on_removeAllEncodersBtn_clicked();
    void on_setNumPreviousDataPntsBtn_clicked();

private:
    Ui::DataVisualizer *ui;

    // Graph data/functions
    void setupGraph();
    QChartView *chartView;
    QChart *chart;
    QList<QPointF> dataPoints;
    QSplineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;
    int sampleDataSize=1000;

    // Spinner functions
    void sortEncodersSpinner();
    void sortActiveEncoderSpinner();

};

#endif // DATAVISUALIZER_H
