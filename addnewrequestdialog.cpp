#include "addnewrequestdialog.h"
#include "ui_addnewrequestdialog.h"

AddNewRequestDialog::AddNewRequestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewRequestDialog)
{
    ui->setupUi(this);
}

AddNewRequestDialog::~AddNewRequestDialog()
{
    delete ui;
}
