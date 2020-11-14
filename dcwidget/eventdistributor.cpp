#include "eventdistributor.h"
#include <QEvent>
#include <QResizeEvent>
#include <QDebug>

EventDistributor * ed = nullptr;

//@todo: this is wrong access. We must hide the details.
QObject * getEventDistributor()
{
   return ed;
}

void setEventDistributor(EventDistributor * p_ed)
{
    ed = p_ed;
}

EventDistributor::EventDistributor(QObject *parent) : QObject(parent)
{

}


bool EventDistributor::eventFilter(QObject *watched, QEvent *event)
{
    qDebug()<<watched->objectName()<<endl;
    if(event->type() == QEvent::Resize)
    {
        qDebug()<<"Resized"<<endl;
        QResizeEvent * rs_event = static_cast<QResizeEvent *>(event);
        int width = rs_event->size().width();
        int height = rs_event->size().height();
        emit legendScrollResize(width,height) ;

    }

    return false;
}
