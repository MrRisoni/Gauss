#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T16:13:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gauss
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addinstitutdialog.cpp \
    addlanguagedialog.cpp \
    addnewdiplomadialog.cpp \
    addnewrequestdialog.cpp \
    addnewschwerdialog.cpp \
    addnewstudentdialog.cpp \
    addnewteacherdialog.cpp \
    createschulegroupdialog.cpp \
    createsprachedialog.cpp \
    createunidialog.cpp \
    logindialog.cpp \
    managedepsdialog.cpp \
    managesalariesdialog.cpp \
    statisticsdialog.cpp \
    viewstudentdialog.cpp \
    viewteacherdialog.cpp \
    Entities/absent.cpp \
    Entities/basewages.cpp \
    Entities/buildings.cpp \
    Entities/canceled.cpp \
    Entities/contract.cpp \
    Entities/courses.cpp \
    Entities/days.cpp \
    Entities/departments.cpp \
    Entities/diplomas.cpp \
    Entities/echelon.cpp \
    Entities/edutypes.cpp \
    Entities/ensembles.cpp \
    Entities/erlaubnis.cpp \
    Entities/examschule.cpp \
    Entities/examsprache.cpp \
    Entities/faces.cpp \
    Entities/feeschule.cpp \
    Entities/feesprache.cpp \
    Entities/feeuni.cpp \
    Entities/funds.cpp \
    Entities/groups.cpp \
    Entities/history.cpp \
    Entities/hours.cpp \
    Entities/instituts.cpp \
    Entities/kassen.cpp \
    Entities/languages.cpp \
    Entities/members.cpp \
    Entities/membtypes.cpp \
    Entities/payments.cpp \
    Entities/permament.cpp \
    Entities/requestschule.cpp \
    Entities/requestsprache.cpp \
    Entities/requestuni.cpp \
    Entities/rooms.cpp \
    Entities/schedule.cpp \
    Entities/schwierigkeit.cpp \
    Entities/teachother.cpp \
    Entities/teachsprache.cpp \
    Entities/teachuni.cpp \
    Entities/times.cpp \
    Entities/unavailable.cpp \
    Entities/versicherung.cpp \
    Entities/wagesuni.cpp \
    Entities/wagessprache.cpp \
    Entities/wagesschule.cpp \
    Entities/orm.cpp \
    addsprachescheduledialog.cpp \
    managecoursesdialog.cpp \
    myCSP/cspsolver.cpp \
    myCSP/node.cpp \
    myCSP/point.cpp \
    myCSP/variable.cpp \
    Entities/teacher.cpp \
    kassendialog.cpp \
    absentbuchdialog.cpp \
    Entities/paykassen.cpp \
    raumedialog.cpp \
    managefeesdialog.cpp \
    Entities/student.cpp

HEADERS  += mainwindow.h \
    addinstitutdialog.h \
    addlanguagedialog.h \
    addnewdiplomadialog.h \
    addnewrequestdialog.h \
    addnewschwerdialog.h \
    addnewstudentdialog.h \
    addnewteacherdialog.h \
    createschulegroupdialog.h \
    createsprachedialog.h \
    createunidialog.h \
    logindialog.h \
    managedepsdialog.h \
    managesalariesdialog.h \
    statisticsdialog.h \
    viewstudentdialog.h \
    viewteacherdialog.h \
    Entities/absent.h \
    Entities/basewages.h \
    Entities/buildings.h \
    Entities/canceled.h \
    Entities/contract.h \
    Entities/courses.h \
    Entities/days.h \
    Entities/departments.h \
    Entities/diplomas.h \
    Entities/echelon.h \
    Entities/edutypes.h \
    Entities/ensembles.h \
    Entities/erlaubnis.h \
    Entities/examschule.h \
    Entities/examsprache.h \
    Entities/faces.h \
    Entities/feeschule.h \
    Entities/feesprache.h \
    Entities/feeuni.h \
    Entities/funds.h \
    Entities/groups.h \
    Entities/history.h \
    Entities/hours.h \
    Entities/instituts.h \
    Entities/kassen.h \
    Entities/languages.h \
    Entities/members.h \
    Entities/membtypes.h \
    Entities/payments.h \
    Entities/permament.h \
    Entities/requestschule.h \
    Entities/requestsprache.h \
    Entities/requestuni.h \
    Entities/rooms.h \
    Entities/schedule.h \
    Entities/schwierigkeit.h \
    Entities/teachother.h \
    Entities/teachsprache.h \
    Entities/teachuni.h \
    Entities/times.h \
    Entities/unavailable.h \
    Entities/versicherung.h \
    Entities/wagesuni.h \
    Entities/wagessprache.h \
    Entities/wagesschule.h \
    Entities/orm.h \
    addsprachescheduledialog.h \
    managecoursesdialog.h \
    myCSP/cspsolver.h \
    myCSP/node.h \
    myCSP/point.h \
    myCSP/variable.h \
    Entities/teacher.h \
    kassendialog.h \
    absentbuchdialog.h \
    Entities/paykassen.h \
    raumedialog.h \
    managefeesdialog.h \
    Entities/student.h \
    Entities/ontotites.h

FORMS    += mainwindow.ui \
    addinstitutdialog.ui \
    addlanguagedialog.ui \
    addnewdiplomadialog.ui \
    addnewrequestdialog.ui \
    addnewschwerdialog.ui \
    addnewstudentdialog.ui \
    addnewteacherdialog.ui \
    createschulegroupdialog.ui \
    createsprachedialog.ui \
    createunidialog.ui \
    logindialog.ui \
    managedepsdialog.ui \
    managesalariesdialog.ui \
    statisticsdialog.ui \
    viewstudentdialog.ui \
    viewteacherdialog.ui \
    addsprachescheduledialog.ui \
    managecoursesdialog.ui \
    kassendialog.ui \
    absentbuchdialog.ui \
    raumedialog.ui \
    managefeesdialog.ui

    
CONFIG +=   c++11

RESOURCES     = piges.qrc
