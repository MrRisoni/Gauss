TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += core

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()



unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lboost_unit_test_framework

INCLUDEPATH += $$PWD/../../../../usr/include/boost/test

DEPENDPATH += $$PWD/../../../../usr/include/boost/test


CONFIG +=   c++11
