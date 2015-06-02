#include "managesalariesdialog.h"
#include "ui_managesalariesdialog.h"


#include "Entities/orm.h"
#include "Entities/basewages.h"
#include <QInputDialog>
#include "Entities/courses.h"
#include "Entities/wagesschule.h"
#include <QStandardItemModel>
#include "../mvc.h"

ManageSalariesDialog::ManageSalariesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageSalariesDialog)
{
    ui->setupUi(this);

    populateEchelTable();
    populateBaseTable();
    populateSchuleTable();



    //fill combo boxes
    ORM o=ORM();
    QList<Echelon> Ec=o.getEchels();
    for (Echelon c : Ec) {
        ui->comboBaseEchelon->addItem(QString::number(c.getExpYears()));

        ui->comboSchuleEchel->addItem(QString::number(c.getExpYears()));

        ui->comboSpracheEchel->addItem(QString::number(c.getExpYears()));

        ui->comboUniEchel->addItem(QString::number(c.getExpYears()));
    }


    //get schule courses
    QList<Courses> SchuleCourses=o.getSchuleCourses();
    for (Courses C : SchuleCourses) {
        ui->comboSchule->addItem(C.getName());
    }
}

ManageSalariesDialog::~ManageSalariesDialog()
{
    delete ui->tableBase->model();


    delete ui->tableEchelons->model();



    delete ui->tableSchule->model();


    delete ui->tableUni->model();

    delete ui;
}

void ManageSalariesDialog::on_pushNewEchel_clicked()
{



    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);

    QString text =  inputDialog->getText(NULL ,"Gauss",
                                             "Enter months", QLineEdit::Normal);
    if (text.length()>0) {
        ORM O=ORM();
        Echelon e=Echelon();
        e.setExpYears(text.toInt());
        O.save(e);
    }

    populateEchelTable();



}

void ManageSalariesDialog::populateBaseTable() {




    ui->tableBase->setModel(MVC::getReceiptBaseWages());
    ui->tableBase->resizeColumnsToContents();


}


void ManageSalariesDialog::populateEchelTable() {


    ui->tableEchelons->setModel(MVC::getReceiptEchelons());
    ui->tableEchelons->resizeColumnsToContents();


}

void ManageSalariesDialog::populateSchuleTable() {

    QStandardItemModel *schuleMod = new QStandardItemModel();
    QStringList headers;
    headers.append("XP");
    headers.append("Date");
    headers.append("Course");
    headers.append("Wage");

    schuleMod->setHorizontalHeaderLabels(headers);

    ORM cppHib = ORM();
    QList<WagesSchule> WSchule = cppHib.getWagesSchule();

    int row=0;
    for (WagesSchule W : WSchule) {


        QStandardItem *itXP = new QStandardItem();
        QStandardItem *itDate = new QStandardItem();
        QStandardItem *itCourse = new QStandardItem();
        QStandardItem *itWage = new QStandardItem();


        itXP->setText(QString::number(W.getEchel().getExpYears()));
        itDate->setText(W.getDat().toString());
        itCourse->setText(W.getC().getName());
        itWage->setText(QString::number(W.getWage()));

        schuleMod->setItem(row,0,itXP);
        schuleMod->setItem(row,1,itDate);
        schuleMod->setItem(row,2,itCourse);
        schuleMod->setItem(row,3,itWage);

        row++;
    }


    ui->tableSchule->setModel(schuleMod);
    ui->tableSchule->resizeColumnsToContents();
}

void ManageSalariesDialog::on_pushAddBaseScheme_clicked()
{

    BaseWages B=BaseWages();
    Echelon E=Echelon();
    E.setExpYears(ui->comboBaseEchelon->currentText().toInt());
    B.setWage(ui->lineBaseWages->text().toFloat());

    B.setE(E);

    ORM o=ORM();
    o.save(B);
    populateBaseTable();
}

void ManageSalariesDialog::on_pushAddSchuleScheme_clicked()
{
    WagesSchule WgSchule=WagesSchule();

    Courses C=Courses();
    C.setName(ui->comboSchule->currentText());

    WgSchule.setC(C);

    WgSchule.setDat(QDate::currentDate());

    Echelon E=Echelon();

    E.setExpYears(ui->comboSchuleEchel->currentText().toInt());

    WgSchule.setEchel(E);

    WgSchule.setWage(ui->lineSchuleWages->text().toFloat());

    ORM o=ORM();
    o.save(WgSchule);

    populateSchuleTable();


}
