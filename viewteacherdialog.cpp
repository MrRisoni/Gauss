#include "viewteacherdialog.h"
#include "ui_viewteacherdialog.h"

ViewTeacherDialog::ViewTeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTeacherDialog)
{
    ui->setupUi(this);
}

ViewTeacherDialog::~ViewTeacherDialog()
{
    delete ui;
}
