#include "addnewdiplomadialog.h"
#include "ui_addnewdiplomadialog.h"



#include "../orm.h"
#include "../mvc.h"

AddNewDiplomaDialog::AddNewDiplomaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDiplomaDialog)
{
    ui->setupUi(this);


    //fetch Shweriegkeit levels

    int row=0;



    QList<Schwierigkeit> Stuffen = ORM::getSchwer();
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



    //populate table
    ui->tableDiplomas->setModel(MVC::getSpracheDiplomas());
    ui->tableDiplomas->resizeColumnsToContents();

}

AddNewDiplomaDialog::~AddNewDiplomaDialog()
{
    delete ui;
}

void AddNewDiplomaDialog::on_pushSave_clicked()
{
    if (ui->lineDiploma->text().length()>2) {

        Diplomas D=Diplomas();
        D.setInstitutName(ui->comboInstitut->currentText());
        D.setLanguage(ui->comboSprache->currentText());
        D.setName(ui->lineDiploma->text());
        D.setSchwerID(ui->comboSchwer->currentText());
        ORM::save(D);
    }
}

void AddNewDiplomaDialog::on_tableDiplomas_doubleClicked(const QModelIndex &index)
{
    //show a plot of  the success rate and failure rate for that diploma

}
