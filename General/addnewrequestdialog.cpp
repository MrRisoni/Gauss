#include "addnewrequestdialog.h"
#include "ui_addnewrequestdialog.h"


#include "../orm.h"


AddNewRequestDialog::AddNewRequestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewRequestDialog)
{
    ui->setupUi(this);

    //fetch schule courses


    QList<Courses> Clist = ORM::getSchuleCourses();
    int r=0;
    for (Courses C : Clist) {
        ui->comboSchuleCourses->addItem(C.getName());
        //get color
        QColor col;
        col.setRed(C.getS().getRed());
        col.setGreen(C.getS().getGreen());

        col.setBlue(C.getS().getBlue());

        ui->comboSchuleCourses->setItemData(r,col,Qt::ForegroundRole);
        r++;
    }


    //fetch departments
    for (Departments D : ORM::getDeps()){
        ui->comboDep->addItem(D.getDepName());
    }

}

AddNewRequestDialog::~AddNewRequestDialog()
{
    delete ui;
}

void AddNewRequestDialog::on_pushSearch_clicked()
{


    Student m = ORM::searchStudentByADT(ui->lineSearchQuery->text());
    ui->labelStudentData->setText(m.getName() + " " + m.getADT());
    //qDebug() << m;
    ui->lineSearchQuery->setText(m.getADT());
}

void AddNewRequestDialog::on_pushAddSchule_clicked()
{
    Requests rec= Requests();
    Courses c= Courses();
    c.setName(ui->comboSchuleCourses->currentText());

    rec.setC(c);

    rec.setComments(ui->textScuhleComments->toPlainText());
    rec.setDat(QDate::currentDate());
    Members st=Members();
    st.setADT(ui->lineSearchQuery->text());
    rec.setStudent(st);

    ORM::save(rec);
}

void AddNewRequestDialog::on_pushAddUni_clicked()
{
 //save uni requiest
    Requests rec= Requests();
    Courses c= Courses();
    c.setName(ui->comboSchuleCourses->currentText());

    rec.setC(c);

    rec.setComments(ui->textScuhleComments->toPlainText());
    rec.setDat(QDate::currentDate());
    Members st=Members();
    st.setADT(ui->lineSearchQuery->text());
    rec.setStudent(st);

    ORM::save(rec);
}

void AddNewRequestDialog::on_pushButton_3_clicked()
{

}

void AddNewRequestDialog::on_comboDep_activated(const QString &arg1)
{
    //get courses by that dep
    ui->comboCourses->clear();

    for (Courses c : ORM::getUniCourses(arg1)) {
        ui->comboCourses->addItem(c.getName());
    }

}

void AddNewRequestDialog::on_comboCourses_activated(const QString &arg1)
{

}
