#include "receivemoneydialog.h"
#include "ui_receivemoneydialog.h"

ReceiveMoneyDialog::ReceiveMoneyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiveMoneyDialog)
{
    ui->setupUi(this);
}

ReceiveMoneyDialog::~ReceiveMoneyDialog()
{
    delete ui;
}
