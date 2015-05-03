#include "managesalariesdialog.h"
#include "ui_managesalariesdialog.h"

ManageSalariesDialog::ManageSalariesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageSalariesDialog)
{
    ui->setupUi(this);
}

ManageSalariesDialog::~ManageSalariesDialog()
{
    delete ui;
}
