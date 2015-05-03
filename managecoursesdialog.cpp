#include "managecoursesdialog.h"
#include "ui_managecoursesdialog.h"

ManageCoursesDialog::ManageCoursesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageCoursesDialog)
{
    ui->setupUi(this);
}

ManageCoursesDialog::~ManageCoursesDialog()
{
    delete ui;
}
