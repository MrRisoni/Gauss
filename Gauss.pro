#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T16:13:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Gauss
TEMPLATE = app


SOURCES += main.cpp\
  Entities/absent.cpp  \
  Entities/basewages.cpp  \
  Entities/buildings.cpp \
  Entities/contract.cpp \
  Entities/courses.cpp \
  Entities/days.cpp \
  Entities/departments.cpp \
  Entities/diplomas.cpp \
  Entities/echelon.cpp \
  Entities/ensembles.cpp \
  Entities/erlaubnis.cpp \
  Entities/examschule.cpp \
  Entities/examsprache.cpp \
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
  orm.cpp \
  Entities/paykassen.cpp  \
  Entities/payments.cpp  \
    Entities/paytype.cpp  \
    Entities/permament.cpp  \
    Entities/rooms.cpp \
    Entities/schedule.cpp \
    Entities/schwierigkeit.cpp \
    Entities/student.cpp \
    Entities/teacher.cpp \
    Entities/teachother.cpp \
    Entities/teachsprache.cpp \
    Entities/teachuni.cpp \
    Entities/times.cpp \
    Entities/unavailable.cpp \
    Entities/versicherung.cpp \
    Entities/wagesschule.cpp \
    Entities/wagessprache.cpp \
    Entities/wagesuni.cpp \
    Sprache/addinstitutdialog.cpp \
    Schule/createschulegroupdialog.cpp \
    Sprache/addlanguagedialog.cpp \
    Sprache/addsprachescheduledialog.cpp \
    Sprache/addnewdiplomadialog.cpp \
    Student/addnewstudentdialog.cpp \
    Student/showstudentsdialog.cpp \
    Teacher/addnewteacherdialog.cpp \
    Teacher/showteachersdialog.cpp \
    Teacher/viewteacherdialog.cpp \
    Sprache/createsprachedialog.cpp \
    E_Receipts/kassendialog.cpp \
    E_Receipts/managefeesdialog.cpp \
    E_Receipts/managesalariesdialog.cpp \
    General/absentbuchdialog.cpp \
    General/addnewrequestdialog.cpp \
    General/addnewschwerdialog.cpp \
    General/logindialog.cpp \
    General/mainwindow.cpp \
    General/managecoursesdialog.cpp \
    General/managedepsdialog.cpp \
    General/objektdelegate.cpp \
    General/raumedialog.cpp \
    General/showgroupsdialog.cpp \
    Student/viewstudentdialog.cpp \
    Uni/createunidialog.cpp \
    Schule/manageschuletestsdialog.cpp \
    Sprache/managesprachetestsdialog.cpp \
    Entities/teachechel.cpp \
    General/geldrechen.cpp \
    E_Receipts/managediscountsdialog.cpp \
    Entities/discount.cpp \
    Entities/discounttype.cpp \
    Entities/schulediscipline.cpp \
    Schule/managedisciplinesdialog.cpp \
    General/zeitwandel.cpp \
    Entities/permatimes.cpp \
    General/roomitemdelegate.cpp \
    mvc.cpp \
    Entities/discipline.cpp \
    Entities/wages.cpp \
    Entities/fee.cpp \
    Entities/requests.cpp \
    Entities/querybuilder.cpp



HEADERS  += Entities/absent.h  \
    Entities/basewages.h \
    Entities/buildings.h \
    Entities/contract.h \
    Entities/courses.h \
    Entities/days.h \
    Entities/departments.h \
    Entities/diplomas.h \
    Entities/echelon.h \
    Entities/ensembles.h \
    Entities/erlaubnis.h \
    Entities/examschule.h \
    Entities/examsprache.h \
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
    orm.h \
    Entities/paykassen.h \
    Entities/payments.h \
    Entities/paytype.h \
    Entities/permament.h \
    Entities/receipt.h \
    Entities/rooms.h \
    Entities/schedule.h \
    Entities/schwierigkeit.h \
    Entities/student.h \
    Entities/tablestructs.h \
    Entities/teacher.h \
    Entities/teachother.h \
    Entities/teachsprache.h \
    Entities/teachuni.h \
    Entities/times.h \
    Entities/unavailable.h \
    Entities/versicherung.h \
    Entities/wagesschule.h \
    Entities/wagessprache.h \
    Entities/wagesuni.h \
    E_Receipts/kassendialog.h \
    E_Receipts/managefeesdialog.h \
    E_Receipts/managesalariesdialog.h \
    General/absentbuchdialog.h \
    General/addnewrequestdialog.h \
    General/addnewschwerdialog.h \
    General/logindialog.h \
    General/mainwindow.h \
    General/managecoursesdialog.h \
    General/managedepsdialog.h \
    General/objektdelegate.h \
    General/raumedialog.h \
    General/showgroupsdialog.h \
    Schule/createschulegroupdialog.h \
    Sprache/addinstitutdialog.h \
    Sprache/addlanguagedialog.h \
    Sprache/addnewdiplomadialog.h \
    Sprache/addsprachescheduledialog.h \
    Sprache/createsprachedialog.h \
    Student/addnewstudentdialog.h \
    Student/showstudentsdialog.h \
    Student/viewstudentdialog.h \
    Teacher/addnewteacherdialog.h \
    Teacher/showteachersdialog.h \
    Teacher/viewteacherdialog.h \
    Uni/createunidialog.h \
    E_Receipts/createnewreceiptdialog.h \
    Schule/manageschuletestsdialog.h \
    Sprache/managesprachetestsdialog.h \
    Entities/teachechel.h \
    General/geldrechen.h \
    E_Receipts/managediscountsdialog.h \
    Entities/discount.h \
    Entities/discounttype.h \
    Entities/schulediscipline.h \
    Schule/managedisciplinesdialog.h \
    General/zeitwandel.h \
    Entities/permatimes.h \
    General/roomitemdelegate.h \
    mvc.h \
    Entities/discipline.h \
    Entities/wages.h \
    Entities/fee.h \
    Entities/requests.h \
    Entities/querybuilder.h





FORMS    +=   E_Receipts/kassendialog.ui \
    E_Receipts/managefeesdialog.ui \
    E_Receipts/managesalariesdialog.ui \
    General/absentbuchdialog.ui \
    General/addnewrequestdialog.ui \
    General/addnewschwerdialog.ui \
    General/logindialog.ui \
    General/mainwindow.ui \
    General/managecoursesdialog.ui \
    General/managedepsdialog.ui \
    General/raumedialog.ui \
    General/showgroupsdialog.ui \
    Schule/createschulegroupdialog.ui \
    Sprache/addinstitutdialog.ui \
    Sprache/addlanguagedialog.ui \
    Sprache/addnewdiplomadialog.ui \
    Sprache/addsprachescheduledialog.ui \
    Sprache/createsprachedialog.ui \
    Uni/createunidialog.ui \
    Teacher/viewteacherdialog.ui \
    Teacher/showteachersdialog.ui \
    Teacher/addnewteacherdialog.ui \
    Student/showstudentsdialog.ui \
    Student/viewstudentdialog.ui \
    Student/addnewstudentdialog.ui \
    Schule/manageschuletestsdialog.ui \
    Sprache/managesprachetestsdialog.ui \
    E_Receipts/managediscountsdialog.ui \
    Schule/managedisciplinesdialog.ui

    



CONFIG +=   c++11

RESOURCES     = piges.qrc



