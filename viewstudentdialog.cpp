#include "viewstudentdialog.h"
#include "ui_viewstudentdialog.h"

ViewStudentDialog::ViewStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewStudentDialog)
{
    ui->setupUi(this);
}

ViewStudentDialog::~ViewStudentDialog()
{
    delete ui;
}
