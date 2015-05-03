#include "addsprachescheduledialog.h"
#include "ui_addsprachescheduledialog.h"

AddSpracheScheduleDialog::AddSpracheScheduleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSpracheScheduleDialog)
{
    ui->setupUi(this);
}

AddSpracheScheduleDialog::~AddSpracheScheduleDialog()
{
    delete ui;
}
