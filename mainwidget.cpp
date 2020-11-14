#include "mainwidget.h"
#include "dcwidget/dcwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Custom Chart");
    QVBoxLayout * vl = new QVBoxLayout();
    QHBoxLayout * hl = new QHBoxLayout();
    m_btn_add_1 = new QPushButton("Add Series 1");
    m_btn_add_2 = new QPushButton("Add Series 2");
    m_btn_remove = new QPushButton("Remove Randomly");
    hl->addWidget(m_btn_add_1);
    hl->addWidget(m_btn_add_2);
    hl->addWidget(m_btn_remove);
    hl->addStretch(1);
    makeConnections();
    m_dc = new DCWidget();
    m_dc->setTitle("Optional Title");
    m_dc->setXTitle("Optional X-axis title");
    m_dc->setYTitle("Optional Y-axis title");
    vl->addLayout(hl);
    vl->addWidget(m_dc);
    this->setLayout(vl);

    for(int i=0; i<10;i++)
    {
        if(rand() % 2 )
        {
            addSeries1();
        }else{
           addSeries2();
        }
    }


}

void MainWidget::makeConnections()
{
   QObject::connect(m_btn_add_1,&QPushButton::clicked,this,&MainWidget::addSeries1);
   QObject::connect(m_btn_add_2,&QPushButton::clicked,this,&MainWidget::addSeries2);
   QObject::connect(m_btn_remove,&QPushButton::clicked,this,&MainWidget::removeRandomly);
}

void MainWidget::addSeries1()
{

    QList<QPointF> data;
    int offset = offset_series_1;
    for (int i = 0; i < 360; i++) {
        qreal x = offset * 20 + i;
        data.append(QPointF(i, qSin(qDegreesToRadians(x))));
    }
    m_last_id = m_dc->addPlot(loremCreator(m_last_id+1),data);

    m_id_list.append(m_last_id);

    offset_series_1++;
}

void MainWidget::addSeries2()
{
    QList<QPointF> data;
    int offset = offset_series_2;
    for (int i = 0; i <= 70; i++) {
        qreal x = ((offset + 20 + i) % (offset + 95));
        qreal y = qPow(20,qSin(qDegreesToRadians(x)));
        data.append(QPointF(i,y));
    }

    m_last_id = m_dc->addPlot(loremCreator(m_last_id+1),data);
    m_id_list.append(m_last_id);
    offset_series_2++;

}

void MainWidget::saveImage()
{

}

void MainWidget::removeRandomly()
{
    if(m_id_list.count() == 0) return;
    int index = qrand() % m_id_list.count();
    int id = m_id_list.at(index);
    qDebug()<<"Removed id : "<<id<<endl;
    m_dc->removePlot(id);
    m_id_list.remove(index);

}

QString loremCreator(int p_id)
{
   static QStringList  str_lorem = QString("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris at enim risus. Mauris sit amet erat ornare, ultricies lorem sed, tincidunt diam. Nam vitae odio blandit, porttitor lectus nec, sagittis.").split(" ");

   int limit = qrand() % str_lorem.length();
   QString result = "";
   QStringList part;
   part<<QString("Line %1 :").arg(p_id);
   for(int i=0; i<limit; i++)
   {
       part<<str_lorem.at(i);
   }
   part.append(".");
   return part.join(" ");

}
