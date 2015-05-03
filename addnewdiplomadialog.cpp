#include "addnewdiplomadialog.h"
#include "ui_addnewdiplomadialog.h"

AddNewDiplomaDialog::AddNewDiplomaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDiplomaDialog)
{
    ui->setupUi(this);
}

AddNewDiplomaDialog::~AddNewDiplomaDialog()
{
    delete ui;
}
