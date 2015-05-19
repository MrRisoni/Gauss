#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



#include "addnewschwerdialog.h"
#include "managedepsdialog.h"
#include "managecoursesdialog.h"
#include "managesalariesdialog.h"
#include "addnewstudentdialog.h"
#include "addnewteacherdialog.h"
#include "kassendialog.h"
#include "raumedialog.h"
#include "addnewrequestdialog.h"
#include "createschulegroupdialog.h"
#include "createsprachedialog.h"
#include "createunidialog.h"


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
};

#endif // MAINWINDOW_H
