#include "createnewreceiptdialog.h"
#include "ui_createnewreceiptdialog.h"

CreateNewReceiptDialog::CreateNewReceiptDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewReceiptDialog)
{
    ui->setupUi(this);
}

CreateNewReceiptDialog::~CreateNewReceiptDialog()
{
    delete ui;
}
