#include "addnewstudentdialog.h"
#include "ui_addnewstudentdialog.h"

AddNewStudentDialog::AddNewStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStudentDialog)
{
    ui->setupUi(this);
}

AddNewStudentDialog::~AddNewStudentDialog()
{
    delete ui;
}
