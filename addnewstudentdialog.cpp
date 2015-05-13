#include "addnewstudentdialog.h"
#include "ui_addnewstudentdialog.h"

#include "Entities/orm.h"

AddNewStudentDialog::AddNewStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStudentDialog)
{
    ui->setupUi(this);
}

AddNewStudentDialog::~AddNewStudentDialog()
{
    delete ui;
}

void AddNewStudentDialog::on_pushAddStudent_clicked()
{
    Members m=Members();

    m.setAddress(ui->lineAddress->text());
    m.setBirthDate(ui->calendarBirth->selectedDate());
    m.setEmail(ui->lineEmail->text());
    m.setFName(ui->lineFName->text());
    m.setMName(ui->lineMName->text());
    m.setMobile(ui->lineMobile->text());
    m.setName(ui->lineName->text());
    m.setPhone(ui->linePhone->text());
    m.setRegDate(QDate::currentDate());

    ORM O=ORM();
    O.saveStudent(m);
}

