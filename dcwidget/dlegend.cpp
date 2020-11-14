#include "dlegend.h"
#include <QSizePolicy>
#include <QDebug>

DLegend::DLegend(QWidget *parent) : QWidget(parent)
{

    this->setBaseSize(100,100);
    this->setMinimumWidth(250);
    m_vlayout = new QVBoxLayout();
    QPalette pal = palette();
#ifdef QT_DEBUG
    pal.setColor(QPalette::Background,Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
#endif
    this->setLayout(m_vlayout);

}

void DLegend::setChart(QChart *p_managed)
{
    this->m_managed_chart = p_managed;

}

bool DLegend::loadLegend(int p_id)
{
    Q_ASSERT(m_managed_chart!=nullptr);
    const auto markers = m_managed_chart->legend()->markers();
    if(markers.count() == 0) return false;
    ProxyMarker * item = new ProxyMarker(p_id);
    item->setSource(markers.last());
    this->m_vlayout->addWidget(item);
    item->render();
    QRect rect = this->geometry();
    rect.setHeight(rect.height() + m_item_height);
    this->setGeometry(rect);
    this->m_item_list.insert(p_id,item);

    return true;
}

bool DLegend::removeLegendItem(int p_id)
{
   if(!m_item_list.contains(p_id)) return false;
   m_item_list.value(p_id)->deleteLater();
   m_item_list.remove(p_id);
    QRect rect = this->geometry();
    rect.setHeight(rect.height() - m_item_height);
    this->setGeometry(rect);
   return true;
}

void DLegend::parentResizeHandler(int width, int height)
{
    this->setGeometry(0,0,width,this->height());
}
