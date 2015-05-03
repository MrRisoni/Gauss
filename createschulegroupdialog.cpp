#include "createschulegroupdialog.h"
#include "ui_createschulegroupdialog.h"

CreateSchuleGroupDialog::CreateSchuleGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateSchuleGroupDialog)
{
    ui->setupUi(this);
}

CreateSchuleGroupDialog::~CreateSchuleGroupDialog()
{
    delete ui;
}
