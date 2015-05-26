#include "manageschuletestsdialog.h"
#include "ui_manageschuletestsdialog.h"

ManageSchuleTestsDialog::ManageSchuleTestsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageSchuleTestsDialog)
{
    ui->setupUi(this);
}

ManageSchuleTestsDialog::~ManageSchuleTestsDialog()
{
    delete ui;
}
