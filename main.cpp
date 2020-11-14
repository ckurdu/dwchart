#include <QApplication>
#include "dcwidget/dcwidget.h"
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.showMaximized();
    return a.exec();
}
