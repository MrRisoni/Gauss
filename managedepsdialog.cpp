#include "managedepsdialog.h"
#include "ui_managedepsdialog.h"

ManageDepsDialog::ManageDepsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDepsDialog)
{
    ui->setupUi(this);
}

ManageDepsDialog::~ManageDepsDialog()
{
    delete ui;
}
