#ifndef COLORMARKER_H
#define COLORMARKER_H

#include <QWidget>
#include <QBrush>
#include <QPen>

class ColorMarker : public QWidget
{
    Q_OBJECT
    bool m_antialiased = true;
    QBrush m_brush;
    QPen m_pen;
public:
    explicit ColorMarker(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * evt_patint) override;

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
public slots:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);

signals:

};

#endif // COLORMARKER_H
