#include "addnewstudentdialog.h"
#include "ui_addnewstudentdialog.h"
#include <QFile>
#include <algorithm>


#include "Entities/orm.h"

AddNewStudentDialog::AddNewStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStudentDialog)
{
    ui->setupUi(this);
    //load a random male and female name from resources

    QList<QString> onomata;
    QFile file(":names/male.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            onomata=QString::fromStdString(file.readAll().toStdString()).split("\n");

            ui->lineFName->setText(onomata.takeAt(qrand() % onomata.size()).toUpper());

    }

    file.close();
    file.setFileName(":names/female.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            onomata=QString::fromStdString(file.readAll().toStdString()).split("\n");

            ui->lineMName->setText(onomata.takeAt(qrand() % onomata.size()).toUpper());

    }
    file.close();


    //fetch disciplines
    ORM o = ORM();
    for (Discipline d : o.getDisciplines()) {
         ui->comboDiscipline->addItem(d.getName());
    }



    for (DiscountType dt : o.getDiscountTypes()) {
        ui->comboSpecialCats->addItem(dt.getDescription());
    }

}

AddNewStudentDialog::~AddNewStudentDialog()
{
    delete ui;
}

void AddNewStudentDialog::on_pushAddStudent_clicked()
{
    if (ui->lineName->text().length()>2) {
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
        m.setADT(ui->lineADT->text()); //set a random string and number


        ORM O=ORM();
        if (ui->checkSchule->checkState()==Qt::Checked) {
            O.saveSchuleStudent(m,ui->comboDiscipline->currentText(),ui->comboSpecialCats->currentText());

        }
        else {
            O.saveStudent(m);
        }
    }
}


void AddNewStudentDialog::on_checkSchule_clicked()
{

}
