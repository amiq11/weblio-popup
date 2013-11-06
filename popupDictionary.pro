#-------------------------------------------------
#
# Project created by QtCreator 2013-11-06T10:06:24
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = popupDictionary
TEMPLATE = app


SOURCES += main.cpp\
        popupwidget.cpp

HEADERS  += popupwidget.h

FORMS    += popupwidget.ui

CONFIG += qxt

unix {
    QXT += gui core
    INCLUDEPATH += /usr/include/qxt/QxtGui
    INCLUDEPATH += /usr/include/qxt/QxtCore
#    LIBS += -lQxtGui -lQxtCore
}

RESOURCES += \
    resources.qrc
