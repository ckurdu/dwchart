#ifndef DLEGEND_H
#define DLEGEND_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtCore/QDebug>
#include <QtCharts/QLegend>
#include <QtWidgets/QFormLayout>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QLineSeries>
#include <QtCharts/QXYLegendMarker>
#include <QtCore/QtMath>
#include <QVBoxLayout>
#include "proxymarker.h"

QT_CHARTS_USE_NAMESPACE

class DLegend : public QWidget
{
    Q_OBJECT
    QChart * m_managed_chart = nullptr;
    QVBoxLayout * m_vlayout = nullptr;
    QMap<int,ProxyMarker *> m_item_list;
public:
    explicit DLegend(QWidget *parent = nullptr);
    void setChart(QChart * p_managed);
    bool loadLegend(int p_id);
    bool removeLegendItem(int p_id);

signals:
public slots:
    void parentResizeHandler(int width, int height);
private :
    int m_item_height = 70;


};

#endif // DLEGEND_H
