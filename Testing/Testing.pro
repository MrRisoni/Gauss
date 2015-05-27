#-------------------------------------------------
#
# Project created by QtCreator 2015-05-27T21:28:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Testing
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    holaboost.cpp \
    salutboost.cpp

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lboost_unit_test_framework

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include
