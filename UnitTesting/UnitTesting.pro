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
    qt_base_salary.cpp \
    oldcode/haloboost.cpp \
    oldcode/saludboost.cpp \
    oldcode/std_base_salary.cpp \
    fee_Unicalculator.cpp \
  # // schulefee.cpp \
    addpermament.cpp


LIBS+= -lboost_unit_test_framework

HEADERS += \
    old_salary_structs.h \
    new_salary_structs.h \
    oldcode/old_salary_structs.h \
    feestructs.h
