#include "colormarker.h"
#include <QPainter>

ColorMarker::ColorMarker(QWidget *parent) : QWidget(parent)
{
}

void ColorMarker::paintEvent(QPaintEvent *evt_patint)
{

    int t_width = this->width()/2;
    int t_height = this->height()/2;

    int side_length = t_width < t_height ? t_width : t_height;
    int t_x =  (this->width() - side_length) /2;
    int t_y =  (this->height() - side_length) /2;

    QRect rect(t_x, t_y, side_length, side_length);
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.setBrush(m_brush);
    if (m_antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    painter.drawRect(rect);
}

QSize ColorMarker::minimumSizeHint() const
{

    return QSize(50, 50);
}

QSize ColorMarker::sizeHint() const
{

    return QSize(50, 50);
}

void ColorMarker::setPen(const QPen &pen)
{
   m_pen = pen;
}

void ColorMarker::setBrush(const QBrush &brush)
{
   m_brush = brush;
}

void ColorMarker::setAntialiased(bool antialiased)
{
    m_antialiased = antialiased;
}
