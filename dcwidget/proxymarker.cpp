#include "proxymarker.h"
#include <QObject>
#include <QDebug>
#include <QSizePolicy>
#include <QHBoxLayout>

ProxyMarker::ProxyMarker(int p_id, QWidget *parent) : QWidget(parent)
{
    m_id = p_id;
    QHBoxLayout * h_layout = new QHBoxLayout();
    m_item = new MarkerItem();
    h_layout->addWidget(m_item);
    QSizePolicy pol = this->sizePolicy();
    pol.setHorizontalPolicy(QSizePolicy::Expanding);
    pol.setVerticalPolicy(QSizePolicy::MinimumExpanding);
    this->setMinimumSize(100,70);
    this->setBaseSize(100,70);
    this->setSizePolicy(pol);
#ifdef  QT_DEBUG
    QPalette pal = this->palette();
    pal.setColor(this->foregroundRole(),Qt::black);
    pal.setColor(this->backgroundRole(),QColor("#33ea17"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
#endif
    this->setContentsMargins(0,0,0,0);
    h_layout->setContentsMargins(0,0,0,0);
    setLayout(h_layout);

}

void ProxyMarker::setSource(QLegendMarker *p_marker)
{
    m_marker = p_marker;
    m_item->setBrush(m_marker->brush());
    m_item->setPen(m_marker->pen());
    m_item->setLabel(m_marker->label());
    QObject::disconnect(m_marker,&QLegendMarker::brushChanged,this,&ProxyMarker::brushChangedHandler);
    QObject::connect(m_marker,&QLegendMarker::brushChanged,this,&ProxyMarker::brushChangedHandler);
    QObject::disconnect(m_marker,&QLegendMarker::labelBrushChanged,this,&ProxyMarker::labelBrushChangedHandler);
    QObject::connect(m_marker,&QLegendMarker::labelBrushChanged,this,&ProxyMarker::labelBrushChangedHandler);
    QObject::disconnect(m_marker,&QLegendMarker::penChanged,this,&ProxyMarker::penChangedHandler);
    QObject::connect(m_marker,&QLegendMarker::penChanged,this,&ProxyMarker::penChangedHandler);
    QObject::disconnect(m_marker,&QLegendMarker::visibleChanged,this,&ProxyMarker::visibleChangedHandler);
    QObject::connect(m_marker,&QLegendMarker::visibleChanged,this,&ProxyMarker::visibleChangedHandler);
}

void ProxyMarker::render()
{
    m_item->render();
}

void ProxyMarker::brushChangedHandler()
{
    qDebug()<<"Brush changed not implemented yet!";
}

void ProxyMarker::labelChangedHandler()
{

    qDebug()<<"Label changed not implemented yet!";
}

void ProxyMarker::labelBrushChangedHandler()
{

    qDebug()<<"Label brush changed not implemented yet!";
}

void ProxyMarker::penChangedHandler()
{

    qDebug()<<"Pen brush changed not implemented yet!";
}

void ProxyMarker::visibleChangedHandler()
{

    qDebug()<<"Visible changed not implemented yet!";
}
