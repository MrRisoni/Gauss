#include "managediscountsdialog.h"
#include "ui_managediscountsdialog.h"

ManageDiscountsDialog::ManageDiscountsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDiscountsDialog)
{
    ui->setupUi(this);
}

ManageDiscountsDialog::~ManageDiscountsDialog()
{
    delete ui;
}

void ManageDiscountsDialog::on_tableDiscounts_doubleClicked(const QModelIndex &index)
{
    //values wrt time
}
