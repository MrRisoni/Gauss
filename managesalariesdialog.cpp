#include "managesalariesdialog.h"
#include "ui_managesalariesdialog.h"


#include "Entities/orm.h"
#include "Entities/basewages.h"
#include <QInputDialog>

ManageSalariesDialog::ManageSalariesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageSalariesDialog)
{
    ui->setupUi(this);

    populateEchelTable();
    populateBaseTable();



    //fill combo boxes
    ORM o=ORM();
    QList<Echelon> Ec=o.getEchels();
    for (Echelon c : Ec) {
        ui->comboBaseEchelon->addItem(QString::number(c.getExpYears()));

        ui->comboSchuleEchel->addItem(QString::number(c.getExpYears()));

        ui->comboSpracheEchel->addItem(QString::number(c.getExpYears()));

        ui->comboUniEchel->addItem(QString::number(c.getExpYears()));
    }

}

ManageSalariesDialog::~ManageSalariesDialog()
{
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
    /*
     Show
     EchelID
     EchelYears
     #Teachers
     Dat
     Wages
     */
}


void ManageSalariesDialog::populateEchelTable() {
    /* Showe
        EchelID
        Years
        #Teachers
    */
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
