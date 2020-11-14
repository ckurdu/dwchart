#ifndef PROXYMARKER_H
#define PROXYMARKER_H

#include <QWidget>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QLineSeries>
#include <QtCharts/QXYLegendMarker>
#include <QtCharts/QLegendMarker>
#include "markeritem.h"

QT_CHARTS_USE_NAMESPACE

class ProxyMarker : public QWidget
{
    Q_OBJECT
    QLegendMarker * m_marker = nullptr;
    MarkerItem * m_item = nullptr;
    int m_id = -1;
public:
    explicit ProxyMarker(int p_id,QWidget *parent = nullptr);
    void setSource(QLegendMarker * p_marker);
    void render();
public slots:
    void brushChangedHandler();
    void labelChangedHandler();
    void labelBrushChangedHandler();
    void penChangedHandler();
    void visibleChangedHandler();

signals:

};

#endif // PROXYMARKER_H
