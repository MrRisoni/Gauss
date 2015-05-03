#include "addinstitutdialog.h"
#include "ui_addinstitutdialog.h"

AddInstitutDialog::AddInstitutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInstitutDialog)
{
    ui->setupUi(this);
}

AddInstitutDialog::~AddInstitutDialog()
{
    delete ui;
}




/* TODO
 Show Instutut Name , #Diplomas
 * /
