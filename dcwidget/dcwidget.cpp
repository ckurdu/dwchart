#include "dcwidget.h"

DCWidget::DCWidget(QWidget *parent) : QWidget(parent)
{
    m_chart = new QChart();
    m_title_label = new QLabel(m_title);
    m_title_label->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    QFont font = m_title_label->font();
    font.setBold(true);
    font.setPixelSize(18);
    m_title_label->setFont(font);
    m_chartView = new QChartView(m_chart, this);
    m_chartView->setMinimumSize(400,300);
    m_mainLayout = new QGridLayout();
    m_dlegend = new DLegend();
    QPalette pal = m_dlegend->palette();
    pal.setColor(QPalette::Background,Qt::white);
    m_dlegend->setAutoFillBackground(true);
    QScrollArea *area = new QScrollArea();
    area->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    area->setFrameShape(QFrame::NoFrame);
    area->setWidget(m_dlegend);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    m_mainLayout->addWidget(m_title_label, 0, 0,1,4);
    m_mainLayout->addWidget(m_chartView, 1, 0,1,3);
    m_mainLayout->addWidget(area, 1, 3, 1, 1);
    setLayout(m_mainLayout);
    area->installEventFilter(&event_dist);
    setEventDistributor(&event_dist);
    QObject::connect(&event_dist,&EventDistributor::legendScrollResize,m_dlegend,&DLegend::parentResizeHandler);
    m_chart->legend()->hide();
    m_chart->legend()->setAlignment(Qt::AlignBottom);
    m_chart->setContentsMargins(0, -20, 0, -10);
    m_chart->setBackgroundRoundness(0);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    this->m_dlegend->setChart(m_chart);

}

int DCWidget::addPlot(QString p_name, QList<QPointF> p_series)
{
    QLineSeries *series = new QLineSeries();
    int new_id = createId();
    m_series.insert(new_id,series);
    series->append(p_series);
    series->setName(p_name);
    m_chart->addSeries(series);

    if (m_series.count() == 1 && !m_axes_created)
    {
        this->createAxes();
        m_axes_created = true;
    }

    m_dlegend->loadLegend(new_id);
    return new_id;
}

bool DCWidget::removePlot(int p_id)
{
    if (m_series.count() == 0 || !m_series.contains(p_id)) {
        return false;
    }

        QLineSeries *series = m_series[p_id];
        m_chart->removeSeries(series);
        m_series.remove(p_id);
        m_dlegend->removeLegendItem(p_id);
        delete series;
        return true;
}

void DCWidget::setTitle(QString p_title)
{
    m_title = p_title;
    m_title_label->setText(m_title);
}

void DCWidget::setXTitle(QString p_title)
{
    m_xaxis_title = p_title;
    if(m_axisX == nullptr) return;
    m_axisX->setTitleText(m_xaxis_title);
}

void DCWidget::setYTitle(QString p_title)
{
    m_yaxis_title = p_title;
    if(m_axisY == nullptr) return;
    m_axisY->setTitleText(m_yaxis_title);
}

void DCWidget::createAxes()
{
    m_axisX = new QValueAxis;
    m_axisX->setTickCount(10);
    m_axisX->setTitleText(m_xaxis_title);
    QFont font = m_axisX->titleFont();
    font.setPixelSize(15);
    font.setBold(false);
    m_axisX->setTitleFont(font);
    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_axisY = new QValueAxis;
    m_axisY->setTitleFont(font);
    m_axisY->setTitleText(m_yaxis_title);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    QLineSeries * last_ser = m_series.last();
    last_ser->attachAxis(m_axisX);
    last_ser->attachAxis(m_axisY);

}

int DCWidget::createId()
{
   return ++m_last_id;
}

