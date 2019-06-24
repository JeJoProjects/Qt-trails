#pragma once

// Qt headers
#include <QtWidgets>
#include <QTimer>
#include <QtCharts/QChartView>

class SysInfoWidget : public QWidget
{
    Q_OBJECT
private:
    QTimer _RefreshTimer;
    QtCharts::QChartView _ChartView;

protected slots:
    virtual void updateSeries() = 0;

protected:
    QtCharts::QChartView& chartView();

public:
    explicit SysInfoWidget(
            QWidget *parent = nullptr, int startDelayMs = 500, int updateSeriesDelayMs = 500);
};

