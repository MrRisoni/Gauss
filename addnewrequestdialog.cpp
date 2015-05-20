#include "addnewrequestdialog.h"
#include "ui_addnewrequestdialog.h"


#include "Entities/orm.h"


AddNewRequestDialog::AddNewRequestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewRequestDialog)
{
    ui->setupUi(this);

    //fetch schule courses

    ORM o = ORM();

    QList<Courses> Clist = o.getSchuleCourses();
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


}

AddNewRequestDialog::~AddNewRequestDialog()
{
    delete ui;
}

void AddNewRequestDialog::on_pushSearch_clicked()
{

    ORM o = ORM();

    Members m = o.searchStudentByName(ui->lineSearchQuery->text());
    ui->labelStudentData->setText(m.getName() + " " + m.getADT());
    //qDebug() << m;
    //serialization m to string
    ui->lineSearchQuery->setText(m.getName());
}

void AddNewRequestDialog::on_pushAddSchule_clicked()
{
    RequestSchule rec= RequestSchule();
    Courses c= Courses();
    c.setName(ui->comboSchuleCourses->currentText());

    rec.setC(c);

    rec.setComments(ui->textScuhleComments->toPlainText());
    rec.setDat(QDate::currentDate());
    Members st=Members();
    st.setName(ui->lineSearchQuery->text());
    rec.setStudent(st);

    ORM o =ORM();
    o.save(rec);
}
