#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QSqlDatabase>
#include "addnewschwerdialog.h"
#include "managedepsdialog.h"
#include "managecoursesdialog.h"
#include "E_Receipts/managesalariesdialog.h"
#include "Student/addnewstudentdialog.h"
#include "Teacher/addnewteacherdialog.h"
#include "E_Receipts/kassendialog.h"
#include "raumedialog.h"
#include "addnewrequestdialog.h"
#include "Schule/createschulegroupdialog.h"
#include "Sprache/createsprachedialog.h"
#include "Uni/createunidialog.h"
#include "E_Receipts/managefeesdialog.h"
#include "Teacher/viewteacherdialog.h"
#include "Sprache/addinstitutdialog.h"
#include "Sprache/addlanguagedialog.h"
#include "Sprache/addnewdiplomadialog.h"
#include "showgroupsdialog.h"
#include "Student/showstudentsdialog.h"
#include "Student/viewstudentdialog.h"
#include "Schule/manageschuletestsdialog.h"
#include "Sprache/managesprachetestsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSqlDatabase getDb() const;
    void setDb(const QSqlDatabase &value);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

private slots:
    void addSchwer();
    void manageDeps();
    void manageCourses();
    void manageSchemes();
    void addStudent();
    void addTeacher();
    void manageKassen();
    void manageBuildings();
    void addrequest();
    void createuni();
    void createpsprache();
    void createschule();
    void manageFees();
    void showTeacher();
    void showStudent();
    void showAllStudents();
    void showTestPlot();
    void MachLearn();
    void manageInstituts();
    void manageLanguages();
    void manageDiplomas();
    void giveMoneyReceipt();
    void takeMoneyReceipt();
    void showAllGroups();
    void warum();

    void SchuleTests();
    void SpracheTests();


};


#endif // MAINWINDOW_H
