#include "managesprachetestsdialog.h"
#include "ui_managesprachetestsdialog.h"

ManageSpracheTestsDialog::ManageSpracheTestsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageSpracheTestsDialog)
{
    ui->setupUi(this);
}

ManageSpracheTestsDialog::~ManageSpracheTestsDialog()
{
    delete ui;
}
