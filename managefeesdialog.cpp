#include "managefeesdialog.h"
#include "ui_managefeesdialog.h"

ManageFeesDialog::ManageFeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageFeesDialog)
{
    ui->setupUi(this);
}

ManageFeesDialog::~ManageFeesDialog()
{
    delete ui;
}
