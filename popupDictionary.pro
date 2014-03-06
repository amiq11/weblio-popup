#-------------------------------------------------
#
# Project created by QtCreator 2013-11-06T10:06:24
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = weblio-popup
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

# install settings
unix {
    # Desktop
    desktop.path  = /usr/share/applications
    desktop.files = ./weblio-popup.desktop
    # Icon
    icon.path     = /usr/local/share/weblio-popup
    icon.files    = ./img/icon.svg
    # Exec file
    target.path = /usr/local/bin
    # Add to a installation list
    INSTALLS += desktop
    INSTALLS += icon
    INSTALLS += target
}
