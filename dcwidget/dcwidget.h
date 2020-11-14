#ifndef DCWIDGET_H
#define DCWIDGET_H

#include <QWidget>
#include "DChartInterface.h"
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QLabel>
#include "eventdistributor.h"
#include "dlegend.h"

QT_CHARTS_USE_NAMESPACE

class DCWidget : public QWidget,public DChartInterface
{
    Q_OBJECT
public:
    explicit DCWidget(QWidget *parent = nullptr);
    int addPlot(QString p_name,QList<QPointF> p_series);
    bool removePlot(int p_id);
    void setTitle(QString p_title);
    void setXTitle(QString p_title);
    void setYTitle(QString p_title);
private:
    void createAxes();
    int createId();
signals:
private:
    EventDistributor event_dist;
    bool m_axes_created = false;
    QChart *m_chart;
    QValueAxis *m_axisX = nullptr;
    QValueAxis *m_axisY = nullptr;
    QMap<int,QLineSeries *> m_series;
    int m_last_id = 0;

    QChartView *m_chartView;
    QGridLayout *m_mainLayout;
    QGridLayout *m_fontLayout;
    DLegend * m_dlegend;
    QLabel * m_title_label;

    QString m_yaxis_title;
    QString m_xaxis_title;
    QString m_title;

};

#endif // DCWIDGET_H
