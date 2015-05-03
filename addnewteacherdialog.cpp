#include "addnewteacherdialog.h"
#include "ui_addnewteacherdialog.h"

AddNewTeacherDialog::AddNewTeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewTeacherDialog)
{
    ui->setupUi(this);
}

AddNewTeacherDialog::~AddNewTeacherDialog()
{
    delete ui;
}
