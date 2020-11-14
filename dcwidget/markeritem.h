#ifndef MARKERITEM_H
#define MARKERITEM_H

#include <QWidget>
#include "colormarker.h"
#include <QLabel>
#include <QHBoxLayout>

void setElidedText(QLabel* label, const QString &text);;
class MarkerItem : public QWidget
{
    Q_OBJECT
    ColorMarker * m_crect = nullptr;
    QString m_text ="";
    QLabel * m_label = nullptr;
    QBrush m_brush;
    QPen m_pen;
    QHBoxLayout * m_layout = nullptr;
public:
    explicit MarkerItem(QWidget *parent = nullptr);
    void setBrush(const QBrush &p_brush);
    void setLabel(const QString &p_label);
    void setPen(const QPen & pen);
    void render();
    void resizeEvent(QResizeEvent * event);

signals:

};

#endif // MARKERITEM_H
