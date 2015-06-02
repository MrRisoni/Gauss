#include "showgroupsdialog.h"
#include "ui_showgroupsdialog.h"
#include  "../mvc.h"


ShowGroupsDialog::ShowGroupsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowGroupsDialog)
{
    ui->setupUi(this);

    ui->tableAllGroups->setModel(MVC::getGeneral_ShowGroup_Model());

}

ShowGroupsDialog::~ShowGroupsDialog()
{
    delete ui;
}
