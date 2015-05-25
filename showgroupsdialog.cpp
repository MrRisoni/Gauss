#include "showgroupsdialog.h"
#include "ui_showgroupsdialog.h"

ShowGroupsDialog::ShowGroupsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowGroupsDialog)
{
    ui->setupUi(this);
}

ShowGroupsDialog::~ShowGroupsDialog()
{
    delete ui;
}
