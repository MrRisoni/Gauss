TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += core

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()



unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lcppunit

INCLUDEPATH += $$PWD/../../../../usr/include/cppunit
DEPENDPATH += $$PWD/../../../../usr/include/cppunit
