#include "addtemporarylessondialog.h"
#include "ui_addtemporarylessondialog.h"

AddTemporaryLessonDialog::AddTemporaryLessonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTemporaryLessonDialog)
{
    ui->setupUi(this);
}

AddTemporaryLessonDialog::~AddTemporaryLessonDialog()
{
    delete ui;
}
