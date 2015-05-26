#include "createsprachedialog.h"
#include "ui_createsprachedialog.h"

CreateSpracheDialog::CreateSpracheDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateSpracheDialog)
{
    ui->setupUi(this);
}

CreateSpracheDialog::~CreateSpracheDialog()
{
    delete ui;
}
