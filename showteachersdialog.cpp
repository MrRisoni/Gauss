#include "showteachersdialog.h"
#include "ui_showteachersdialog.h"

ShowTeachersDialog::ShowTeachersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTeachersDialog)
{
    ui->setupUi(this);
}

ShowTeachersDialog::~ShowTeachersDialog()
{
    delete ui;
}
