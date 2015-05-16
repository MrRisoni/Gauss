#include "absentbuchdialog.h"
#include "ui_absentbuchdialog.h"

AbsentBuchDialog::AbsentBuchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AbsentBuchDialog)
{
    ui->setupUi(this);
}

AbsentBuchDialog::~AbsentBuchDialog()
{
    delete ui;
}
