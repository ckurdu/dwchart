#include "markeritem.h"
#include <QSizePolicy>
#include <QDebug>

MarkerItem::MarkerItem(QWidget *parent) : QWidget(parent)
{
    m_layout = new QHBoxLayout();
    this->setContentsMargins(0,0,0,0);
    m_layout->setContentsMargins(0,0,0,0);
    m_crect = new ColorMarker();
    m_label = new QLabel();
    QFont font = m_label->font();
    font.setPixelSize(14);
    m_label->setFont(font);
    m_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_label->setWordWrap(true);
    m_label->setContentsMargins(0,0,0,0);

#ifdef QT_DEBUG
    QPalette pal = m_label->palette();
    pal.setColor(m_label->foregroundRole(),Qt::black);
    pal.setColor(m_label->backgroundRole(),QColor("#fcfcfc"));
    m_label->setAutoFillBackground(true);
    m_label->setPalette(pal);
#endif

    m_layout->addWidget(m_crect);
    m_layout->addWidget(m_label);
    this->setLayout(m_layout);

}

void MarkerItem::setBrush(const QBrush &p_brush)
{
    m_brush = p_brush;
}

void MarkerItem::setLabel(const QString &p_label)
{
    m_text = p_label;
}

void MarkerItem::setPen(const QPen &p_pen)
{
    m_pen = p_pen ;
}

void MarkerItem::render()
{
    m_crect->setBrush(m_brush);
    m_crect->setPen(m_pen);
    setElidedText(m_label,QString(m_text));
    m_crect->repaint();
    this->show();
}

void MarkerItem::resizeEvent(QResizeEvent *event)
{
   setElidedText(m_label,QString(m_text));
   QWidget::resizeEvent(event);
}

void setElidedText(QLabel* label, const QString &text){
    QFontMetrics metrix(label->font());
    int width =  2 * (label->width() - 4);
    QString clippedText = metrix.elidedText(text, Qt::ElideRight, width);
    label->setText(clippedText);
}
