#include "viewteacherdialog.h"
#include "ui_viewteacherdialog.h"

#include "Entities/orm.h"
#include <QBuffer>
#include "E_Receipts/givemoneydialog.h"

ViewTeacherDialog::ViewTeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTeacherDialog)
{
    ui->setupUi(this);

    //combo paytype

    ORM o=ORM();
    for (Departments D : o.getDeps()) {
        ui->comboDeps->addItem(D.getDepName());
    }

    for (PayType p : o.getPayTypes()) {
        ui->comboPayType->addItem(p.getComment());
    }
}

ViewTeacherDialog::~ViewTeacherDialog()
{
    delete ui;
}

void ViewTeacherDialog::on_pushButton_clicked()
{
    ORM o=ORM();

    Teacher L = o.searchteacherByname(ui->lineName->text());

    ui->labName->setText(L.getName());

    qDebug() << "setting image..." << L.getPhoto().size();



    int w = ui->labProfile->width();
    int h = ui->labProfile->height();


   ui->labProfile->setPixmap(L.getPixie().scaled(w,h,Qt::KeepAspectRatio));

}


void ViewTeacherDialog::on_pushAddAmount_clicked()
{
    Payments pay=Payments();
    pay.setDat(QDate::currentDate());
    pay.setMoney(ui->linePoso->text().toFloat());
    pay.setTeacherName(ui->labName->text());
    pay.setPayType(ui->comboSelectPayType->currentText());

    ORM O=ORM();
    O.save(pay);


    GiveMoneyDialog *gief= new GiveMoneyDialog();
    gief->setAttribute(Qt::WA_DeleteOnClose);
    gief->show();
    //fill in the blanks

}

void ViewTeacherDialog::on_comboDeps_currentIndexChanged(const QString &arg1)
{
    ui->comboAllCourses->clear();
    ORM o=ORM();

    for (Courses c : o.getUniCourses(arg1)) {
        ui->comboAllCourses->addItem(c.getName());
     }


}

void ViewTeacherDialog::on_pushAddCourse_clicked()
{

}
