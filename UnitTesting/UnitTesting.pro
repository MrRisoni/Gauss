#-------------------------------------------------
#
# Project created by QtCreator 2015-05-27T21:43:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = UnitTesting
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    saludboost.cpp \
    haloboost.cpp \
    std_base_salary.cpp \
    qt_base_salary.cpp


LIBS+= -lboost_unit_test_framework

HEADERS += \
    salary_structs.h
