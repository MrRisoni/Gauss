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
    srand ( time(NULL) );


    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            onomata=QString::fromStdString(file.readAll().toStdString()).split("\n");

            ui->lineFName->setText(onomata.takeAt(qrand() % onomata.size()).toUpper());

    }

    file.close();

    srand ( time(NULL) );



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

void AddNewStudentDialog::on_pushBulkInsert_clicked()
{
    // read name from file:///home/linguine/names
    //lower case all names
    //pick a random number for disciplines
    //insert only schulern
    //upper case all

    //pick a random number for discipline 1 to 6

    QList<QString> Richtung;
    Richtung.append("ΑΝΘΡΩΠΙΣΤΙΚΕΣ");
    Richtung.append("ΘΕΤΙΚΕΣ");
    Richtung.append("ΠΛΗΡΟΦΟΡΙΚΗ");
    Richtung.append("ΥΓΕΙΑ");
    Richtung.append("ΟΙΚΟΝΟΜΙΚΑ");



    QList<QString> ekptosi;
    ekptosi.append("ΚΑΜΙΑ");
    ekptosi.append("ΠΟΛΥΤΕΚΝΟΙ");
    ekptosi.append("ΟΡΦΑΝΑ");
    ekptosi.append("ΤΡΙΤΕΚΝΟΙ");



     QList<QString> onomata;

    long von=2450450;
    long bis=2451180;

    qDebug() << "start";
    QFile NAMES("/home/linguine/names");

    QTextStream in(&NAMES);
    if(!NAMES.open(QIODevice::ReadOnly)) {
        qDebug() << "ERRRO";
    }
    srand ( time(NULL) );


    while(!in.atEnd()) {


        QString line = in.readLine();

        qDebug () << line;

        Members m = Members();
        m.setBirthDate(QDate::fromJulianDay( von + (rand() % (long)(bis - von + 1))));
        m.setName(line.toUpper());
        m.setRegDate(QDate::currentDate());




        QFile file(":names/male.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            onomata=QString::fromStdString(file.readAll().toStdString()).split("\n");


            m.setFName(onomata.takeAt(qrand() % onomata.size()).toUpper());
        }

        file.close();
        file.setFileName(":names/female.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            onomata=QString::fromStdString(file.readAll().toStdString()).split("\n");

            m.setMName(onomata.takeAt(qrand() % onomata.size()).toUpper());

        }
        file.close();

        m.setAddress("");
        qDebug() << "birthdate " << m.getBirthDate();

        int kattuxaio=  qrand() % Richtung.size();
        int orttuxaio = qrand() % ekptosi.size();
        qDebug() << "random " << kattuxaio << " mikos " << Richtung.size();

        QString richter = Richtung.at(kattuxaio);
        QString orphana = ekptosi.at(orttuxaio);

        qDebug() << "richtung " << richter << " " << orphana;

        ORM HIB = ORM();
        qDebug() << "saving.............................................";
        HIB.saveSchuleStudent(m,richter,orphana);
    }

    qDebug() << "end";
}
