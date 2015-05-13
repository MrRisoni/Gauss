#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addnewschwerdialog.h"
#include "managedepsdialog.h"
#include "managecoursesdialog.h"
#include "managesalariesdialog.h"
#include "addnewstudentdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->actionSchwer_Levels,SIGNAL(triggered()),this,SLOT(addSchwer()));
    connect(ui->actionManage_Departments,SIGNAL(triggered()),this,SLOT(manageDeps()));
    connect(ui->actionManage_Courses,SIGNAL(triggered()),this,SLOT(manageCourses()));
    connect(ui->actionManage_Pay_Schemes,SIGNAL(triggered()),this,SLOT(manageSchemes()));
    connect(ui->actionAdd_Student,SIGNAL(triggered()),this,SLOT(addStudent()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addStudent() {
    AddNewStudentDialog *newstud=new AddNewStudentDialog();
    newstud->setAttribute(Qt::WA_DeleteOnClose);
    newstud->show();

}

void MainWindow::manageSchemes() {
    ManageSalariesDialog *sals=new ManageSalariesDialog();
    sals->setAttribute(Qt::WA_DeleteOnClose);
    sals->show();
}

void MainWindow::manageCourses() {
    ManageCoursesDialog *crs=new ManageCoursesDialog();
    crs->setAttribute(Qt::WA_DeleteOnClose);
    crs->show();
}



void MainWindow::manageDeps() {
    ManageDepsDialog *deps=new ManageDepsDialog();
    deps->setAttribute(Qt::WA_DeleteOnClose);
    deps->show();
}


void MainWindow::addSchwer() {
   AddNewSchwerDialog *sch=new AddNewSchwerDialog();
   sch->setAttribute(Qt::WA_DeleteOnClose);
   sch->show();
}
