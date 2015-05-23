#include "addnewdiplomadialog.h"
#include "ui_addnewdiplomadialog.h"



#include "Entities/orm.h"

AddNewDiplomaDialog::AddNewDiplomaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDiplomaDialog)
{
    ui->setupUi(this);


    //fetch Shweriegkeit levels

    ORM O=ORM();
    int row=0;



    QList<Schwierigkeit> Stuffen = O.getSchwer();
    for (Schwierigkeit stuffe: Stuffen) {
        qDebug() << "new stuffe" << stuffe.getRed() << " " << stuffe.getGreen() << " " << stuffe.getBlue();
        ui->comboSchwer->addItem(QString::number(stuffe.getSchwerID()));
        QColor col;

        col.setRed(stuffe.getRed());
        col.setGreen(stuffe.getGreen());
        col.setBlue(stuffe.getBlue());

        ui->comboSchwer->setItemData(row,col,Qt::ForegroundRole);
        row++;




    }


    QSqlQuery q;

    q.exec("SELECT Name FROM  Instituts");
    while (q.next()) {
        ui->comboInstitut->addItem(q.value(0).toString());
    }

    q.exec("SELECT Name From Languages");
    while (q.next()) {
        ui->comboSprache->addItem(q.value(0).toString());
    }



}

AddNewDiplomaDialog::~AddNewDiplomaDialog()
{
    delete ui;
}

void AddNewDiplomaDialog::on_pushSave_clicked()
{
    if (ui->lineDiploma->text().length()>2) {
        ORM O=ORM();
        Diplomas D=Diplomas();
        D.setInstitutName(ui->comboInstitut->currentText());
        D.setLanguage(ui->comboSprache->currentText());
        D.setName(ui->lineDiploma->text());
        D.setSchwerID(ui->comboSchwer->currentText());
        O.save(D);
    }
}
