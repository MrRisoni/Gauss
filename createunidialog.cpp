#include "createunidialog.h"
#include "ui_createunidialog.h"

CreateUniDialog::CreateUniDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUniDialog)
{
    ui->setupUi(this);
}

CreateUniDialog::~CreateUniDialog()
{
    delete ui;
}
