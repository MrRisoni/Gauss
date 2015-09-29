#include "viewteacherdialog.h"
#include "ui_viewteacherdialog.h"

#include "../orm.h"


ViewTeacherDialog::ViewTeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTeacherDialog)
{
    ui->setupUi(this);

    //combo paytype

    for (Departments D : ORM::getDeps()) {
        ui->comboDeps->addItem(D.getDepName());
    }

    for (PayType p : ORM::getPayTypes()) {
        ui->comboPayType->addItem(p.getComment());
        ui->comboSelectPayType->addItem(p.getComment());
    }


}

ViewTeacherDialog::~ViewTeacherDialog()
{
    delete ui;
}

void ViewTeacherDialog::on_pushButton_clicked()
{

    Teacher L = ORM::searchteacherByname(ui->lineName->text());

    ui->labName->setText(L.getName());
    ui->labAddress->setText(L.getAddress());
    ui->labADT->setText(L.getADT());
    ui->labelAFM->setText(L.getAFM());
    ui->labEndMember->setText(L.getEndOfContract().toString());
    ui->labMobile->setText(L.getMobile());
    ui->labPhone->setText(L.getPhone());
    ui->labMemberSince->setText(L.getRegDate().toString());







   //get groupis
   ui->comboPayForGroup->clear();
   for (QString gid : ORM::getGroupIDs(ui->lineName->text())) {
       ui->comboPayForGroup->addItem(gid);
   }


}


void ViewTeacherDialog::on_pushAddAmount_clicked()
{
    Payments pay=Payments();
    pay.setDat(QDate::currentDate());
    pay.setMoney(ui->linePoso->text().toFloat());
    pay.setTeacherName(ui->labName->text());
    pay.setPayType(ui->comboSelectPayType->currentText());
    pay.setGroupID(ui->comboPayForGroup->currentText().toInt());

    ORM::save(pay);



}

void ViewTeacherDialog::on_comboDeps_currentIndexChanged(const QString &arg1)
{
    ui->comboAllCourses->clear();

    for (Courses c : ORM::getUniCourses(arg1)) {
        ui->comboAllCourses->addItem(c.getName());
     }


}

void ViewTeacherDialog::on_pushAddCourse_clicked()
{

}
