#ifndef DCHARTINTERFACE_H
#define DCHARTINTERFACE_H
#include <QString>
#include <QList>

class DChartInterface{
 public:
    virtual int addPlot(QString name, QList<QPointF>) = 0;
    virtual bool removePlot(int p_id) = 0;
    virtual void setTitle(QString p_title) = 0;
    virtual void setXTitle(QString p_title) = 0;
    virtual void setYTitle(QString p_title) = 0;
};

#endif // DCHARTINTERFACE_H
