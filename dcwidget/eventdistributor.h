#ifndef EVENTDISTRIBUTOR_H
#define EVENTDISTRIBUTOR_H

#include <QObject>


class EventDistributor : public QObject
{
    Q_OBJECT
public:
    explicit EventDistributor(QObject *parent = nullptr);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void legendScrollResize(int width, int height);

};

void setEventDistributor(EventDistributor * p_dis);
EventDistributor *  getEventDistiributor();

#endif // EVENTDISTRIBUTOR_H
