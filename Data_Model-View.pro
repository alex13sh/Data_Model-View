#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T23:18:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Data_Model-View
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Models/mymodel.cpp \
    Views/mlistview.cpp \
    Views/mlistviewd.cpp

HEADERS  += mainwindow.h \
    Models/mymodel.h \
    Views/mlistview.h \
    Views/mlistviewd.h \
    Interfaces/mitree.h

FORMS    += mainwindow.ui \
    Views/mlistviewd.ui
