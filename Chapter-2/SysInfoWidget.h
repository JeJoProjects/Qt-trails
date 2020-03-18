#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

// Qt headers
#include <QtWidgets>
#include <QTimer>
#include <QtCharts/QChartView>

// C++ headers

// forward declarations



class SysInfoWidget : public QWidget
{
    Q_OBJECT
private:
    QTimer mRefreshTimer;
    QtCharts::QChartView mChartView;

protected slots:
    virtual void updateSeries() noexcept = 0;

protected:
    QtCharts::QChartView& chartView() noexcept;

public:
#if 0
    explicit SysInfoWidget(
            QWidget *parent = nullptr,int startDelayMs = 500, int updateSeriesDelayMs = 500);
#endif
};

#endif // SYSINFOWIDGET_H
