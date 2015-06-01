#include "showgroupsdialog.h"
#include "ui_showgroupsdialog.h"
#include "../backend.cpp"


ShowGroupsDialog::ShowGroupsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowGroupsDialog)
{
    ui->setupUi(this);


    ui->tableAllGroups->setModel(MVC::getGeneral_ShowGroup_View());

}

ShowGroupsDialog::~ShowGroupsDialog()
{
    delete ui;
}
