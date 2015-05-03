#include "addnewschwerdialog.h"
#include "ui_addnewschwerdialog.h"

AddNewSchwerDialog::AddNewSchwerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewSchwerDialog)
{
    ui->setupUi(this);
}

AddNewSchwerDialog::~AddNewSchwerDialog()
{
    delete ui;
}
