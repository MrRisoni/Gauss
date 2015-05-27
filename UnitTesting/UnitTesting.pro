TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.cpp \
    holaBoost.cpp \
    salutBoost.cpp




unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lboost_unit_test_framework

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include
