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



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void addSchwer();
    void manageDeps();
    void manageCourses();
    void manageSchemes();
    void addStudent();
    void addTeacher();
    void manageKassen();
};

#endif // MAINWINDOW_H
