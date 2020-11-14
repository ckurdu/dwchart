#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <dcwidget/dcwidget.h>
#include <QPushButton>

QString loremCreator(int);
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
private:
    void makeConnections();
signals:
public slots:
    void addSeries1();
    void addSeries2();
    void saveImage();
    void removeRandomly();
private:
    QVector<int> m_id_list;
    int m_last_id = 0;
    DCWidget * m_dc = nullptr;
    int offset_series_1 = 0;
    int offset_series_2 = 0;
    QPushButton * m_btn_add_1 = nullptr;
    QPushButton * m_btn_add_2 = nullptr;
    QPushButton * m_btn_save_img = nullptr;
    QPushButton * m_btn_remove = nullptr;
};

#endif // MAINWIDGET_H
