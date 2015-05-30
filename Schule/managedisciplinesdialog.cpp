#include "managedisciplinesdialog.h"
#include "ui_managedisciplinesdialog.h"

ManageDisciplinesDialog::ManageDisciplinesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDisciplinesDialog)
{
    ui->setupUi(this);
}

ManageDisciplinesDialog::~ManageDisciplinesDialog()
{
    delete ui;
}
