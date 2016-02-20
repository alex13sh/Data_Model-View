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
    Models/mymodel.cpp

HEADERS  += mainwindow.h \
    Models/mymodel.h

FORMS    += mainwindow.ui
