QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT +=charts

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dcwidget/colormarker.cpp \
    dcwidget/dcwidget.cpp \
    dcwidget/dlegend.cpp \
    dcwidget/eventdistributor.cpp \
    dcwidget/markeritem.cpp \
    dcwidget/proxymarker.cpp \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    dcwidget/DChartInterface.h \
    dcwidget/colormarker.h \
    dcwidget/dcwidget.h \
    dcwidget/dlegend.h \
    dcwidget/eventdistributor.h \
    dcwidget/markeritem.h \
    dcwidget/proxymarker.h \
    mainwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=
