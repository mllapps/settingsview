#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T08:51:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = settingsview
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
    borderlayout.cpp \
    sidebaritem.cpp \
    settingsview.cpp

HEADERS  += \
    borderlayout.h \
    sidebaritem.h \
    settingsview.h

FORMS    += mainwindow.ui

RESOURCES += \
    default.qrc

target.files = settingsview
target.path = /usr/bin

INSTALLS += target
