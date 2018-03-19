#include "datavisualizer.h"
#include "ui_datavisualizer.h"
#include <QDebug>
#include <QCloseEvent>
#include <QtCharts>


DataVisualizer::DataVisualizer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataVisualizer)
{
    ui->setupUi(this);
    QStringList encoders = (QStringList()<<"Encoder A"<<"Encoder B"<<"Encoder C");
    ui->encodersSpinner->addItems(encoders);

    // DEFAULT FOR NOW
    ui->numPreviousDataPntsLineEdit->setText("120");
    //

    setupGraph();
}

DataVisualizer::~DataVisualizer()
{
    delete ui;
}

void DataVisualizer::closeEvent(QCloseEvent *event)
{
    emit closed();
    event->accept();
}

void DataVisualizer::showDataVisualizer(bool en)
{
    if (en)
    {
        this->show();
    } else {
        this->hide();
    }
}

void DataVisualizer::setupGraph() {

    series = new QSplineSeries();
//    *series << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
//    for (int i = 0; i < 10; i++) {
//        int y = (qrand() % 361);
//        *series <<  QPointF(i, y);
//    }
    for (int i = 0; i < 120; i++) {
        dataPoints.append(QPointF(i, qrand() % 361));
    }
    series->append(dataPoints);
    chart = new QChart();
    chart->legend()->hide();
    //chart->addSeries(series);

    // Customize series
   QPen pen(QRgb(0xfdb157));
   pen.setWidth(5);
   series->setPen(pen);

   // Customize chart title
   QFont font;
   font.setPixelSize(18);
   chart->setTitleFont(font);
   chart->setTitleBrush(QBrush(Qt::white));
   chart->setTitle("Rover Data");

   // Customize chart background
   QLinearGradient backgroundGradient;
   backgroundGradient.setStart(QPointF(0, 0));
   backgroundGradient.setFinalStop(QPointF(0, 1));
   backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
   backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
   backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
   chart->setBackgroundBrush(backgroundGradient);

   // Customize plot area background
   QLinearGradient plotAreaGradient;
   plotAreaGradient.setStart(QPointF(0, 1));
   plotAreaGradient.setFinalStop(QPointF(1, 0));
   plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
   plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
   plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
   chart->setPlotAreaBackgroundBrush(plotAreaGradient);
   chart->setPlotAreaBackgroundVisible(true);

   // Customize axis label font
//   QFont labelsFont;
//   labelsFont.setPixelSize(12);
//   axisX->setLabelsFont(labelsFont);
//   axisY->setLabelsFont(labelsFont);

   // Customize axis colors
//   QPen axisPen(QRgb(0xd18952));
//   axisPen.setWidth(2);
//   axisX->setLinePen(axisPen);
//   axisY->setLinePen(axisPen);

   // Customize axis label colors
//   QBrush axisBrush(Qt::white);
//   axisX->setLabelsBrush(axisBrush);
//   axisY->setLabelsBrush(axisBrush);

   // Customize grid lines and shades
//   axisX->setGridLineVisible(false);
//   axisY->setGridLineVisible(false);
//   axisY->setShadesPen(Qt::NoPen);
//   axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
//   axisY->setShadesVisible(true);

//   axisX->setRange(0, ui->numPreviousDataPntsLineEdit->text().toInt());
   axisX = new QValueAxis;
   axisY = new QValueAxis;

   axisX->setRange(0, 120);
   axisX->setTickCount(10);
   axisX->setLabelFormat("%.2f");

   axisY->setRange(0, 360);
   axisY->setTickCount(36);
   axisY->setLabelFormat("%.2f");

   chart->addSeries(series);
   series->attachAxis(axisX);
   series->attachAxis(axisY);

//   axisX->append("low", 10);
//   axisX->append("optimal", 20);
//   axisX->append("high", 30);
//   axisX->setRange(0, 30);

//   axisY->append("slow", 10);
//   axisY->append("med", 20);
//   axisY->append("fast", 30);
//   axisY->setRange(0, 30);

//   chart->setAxisX(axisX, series);
//   chart->setAxisY(axisY, series);

   chart->addAxis(axisX, Qt::AlignBottom);
   chart->addAxis(axisY, Qt::AlignLeft);

   chartView = new QChartView(chart);
   chartView->setRenderHint(QPainter::Antialiasing);
   chartView->setMinimumSize(400, 400);

   ui->dataVisualizerLayout->addWidget(chartView, 0, 0);

}

void DataVisualizer::on_addDataPointsBtn_clicked()
{
    QString addedEncoder = ui->encodersSpinner->itemText(ui->encodersSpinner->currentIndex());
    ui->activeEncodersSpinner->addItem(addedEncoder);
    sortActiveEncoderSpinner();
    ui->activeEncodersSpinner->setCurrentIndex(ui->activeEncodersSpinner->findText(addedEncoder));
    ui->encodersSpinner->removeItem(ui->encodersSpinner->findText(addedEncoder));

}

void DataVisualizer::on_removeActiveEncoderBtn_clicked()
{
    QString removedEncoder = ui->activeEncodersSpinner->itemText(ui->activeEncodersSpinner->currentIndex());
    ui->encodersSpinner->addItem(removedEncoder);
    sortEncodersSpinner();
    ui->encodersSpinner->setCurrentIndex(ui->encodersSpinner->findText(removedEncoder));
    ui->activeEncodersSpinner->removeItem(ui->activeEncodersSpinner->currentIndex());

}

void DataVisualizer::on_removeAllEncodersBtn_clicked()
{
    ui->activeEncodersSpinner->clear();
}

void DataVisualizer::sortEncodersSpinner()
{
    QSortFilterProxyModel* proxy = new QSortFilterProxyModel(ui->encodersSpinner);
    proxy->setSourceModel(ui->encodersSpinner->model());
    ui->encodersSpinner->model()->setParent(proxy);
    ui->encodersSpinner->setModel(proxy);
    ui->encodersSpinner->model()->sort(0);
}

void DataVisualizer::sortActiveEncoderSpinner()
{
    QSortFilterProxyModel* proxy = new QSortFilterProxyModel(ui->activeEncodersSpinner);
    proxy->setSourceModel(ui->activeEncodersSpinner->model());
    ui->activeEncodersSpinner->model()->setParent(proxy);
    ui->activeEncodersSpinner->setModel(proxy);
    ui->activeEncodersSpinner->model()->sort(0);
}

void DataVisualizer::on_setNumPreviousDataPntsBtn_clicked()
{
    chart->removeSeries(series);
    series->clear();

    int numPoints = ui->numPreviousDataPntsLineEdit->text().toInt();
    axisX->setRange(0, numPoints);
    axisX->setTickCount(5);
    series->append(dataPoints.mid(dataPoints.length()-numPoints, numPoints));

    chart->addSeries(series);
    chartView->update();
}

