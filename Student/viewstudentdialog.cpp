#include "viewstudentdialog.h"
#include "ui_viewstudentdialog.h"
#include "Entities/orm.h"

ViewStudentDialog::ViewStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewStudentDialog)
{
    ui->setupUi(this);
}

ViewStudentDialog::~ViewStudentDialog()
{
    delete ui;
}

void ViewStudentDialog::on_pushSearch_clicked()
{
    ORM o = ORM();
    Student st = o.searchStudentByADT(ui->lineSearch->text());

    ui->labName->setText(st.getName());

    ui->comboAttends->clear();

    for (QString groupid : st.getGroupIDs()) {
        ui->comboAttends->addItem(groupid);
    }
}

void ViewStudentDialog::on_pushAddPoso_clicked()
{
    Funds F = Funds();
    F.setADT(ui->lineSearch->text());
    F.setAmount(ui->linePoso->text().toFloat());
    F.setGroupID(ui->comboAttends->currentText());
    ORM o = ORM();
    o.save(F);
}
