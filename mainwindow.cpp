#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addnewschwerdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->actionSchwer_Levels,SIGNAL(triggered()),this,SLOT(addSchwer()));


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::addSchwer() {
   AddNewSchwerDialog *sch=new AddNewSchwerDialog();
   sch->setAttribute(Qt::WA_DeleteOnClose);
   sch->show();
}
