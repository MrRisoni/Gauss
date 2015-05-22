#include "managefeesdialog.h"
#include "ui_managefeesdialog.h"


#include <QStandardItemModel>
#include "Entities/orm.h"

ManageFeesDialog::ManageFeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageFeesDialog)
{
    ui->setupUi(this);

    populateTable();
    ORM o=ORM();
    QList<Courses> cs=o.getSchuleCourses();
    for (Courses c : cs) {
        ui->comboCourses->addItem(c.getName());
    }
}

ManageFeesDialog::~ManageFeesDialog()
{
    delete ui;
}


void ManageFeesDialog::populateTable() {


    QStandardItemModel *mod= new QStandardItemModel();


    ORM o=ORM();
    int r=0;



    FeeSchuleMVC feemvc=o.getManageFeeSchuleMVC();
      mod->setHorizontalHeaderLabels(feemvc.FeeViewHeaders);

    for (FeeSchuleTable fee : feemvc.FeeModel) {
       QStandardItem *it=new QStandardItem();
       it->setText(fee.Name);
       mod->setItem(r,1,it);


       QStandardItem *itID=new QStandardItem();
       itID->setText(fee.CourseID);
       mod->setItem(r,0,itID);

       r++;
    }



    ui->tableCourses->setModel(mod);
}

void ManageFeesDialog::on_pushSaveSchuleFee_clicked()
{
    FeeSchule fsch=FeeSchule();
    Courses cr=Courses();
    cr.setName(ui->comboCourses->currentText());
    fsch.setC(cr);
    fsch.setDat(QDate::currentDate());
    fsch.setFee(ui->lineSchuleFee->text().toFloat());

    ORM o = ORM();
    o.save(fsch);
}
