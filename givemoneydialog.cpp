#include "givemoneydialog.h"
#include "ui_givemoneydialog.h"

GiveMoneyDialog::GiveMoneyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GiveMoneyDialog)
{
    ui->setupUi(this);
}

GiveMoneyDialog::~GiveMoneyDialog()
{
    delete ui;
}
