#include "viewteacherdialog.h"
#include "ui_viewteacherdialog.h"

#include "Entities/orm.h"
#include <QBuffer>

ViewTeacherDialog::ViewTeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTeacherDialog)
{
    ui->setupUi(this);

    //combo paytype

    ui->comboSelectPayType->addItem("ΑΣΦΑΛΙΣΗ");
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

    QPixmap p;
    p.loadFromData(L.getPhoto());

    int w = ui->labProfile->width();
    int h = ui->labProfile->height();


   ui->labProfile->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));

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
}
