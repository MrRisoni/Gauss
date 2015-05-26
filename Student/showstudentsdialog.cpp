#include "showstudentsdialog.h"
#include "ui_showstudentsdialog.h"

ShowStudentsDialog::ShowStudentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowStudentsDialog)
{
    ui->setupUi(this);
}

ShowStudentsDialog::~ShowStudentsDialog()
{
    delete ui;
}
