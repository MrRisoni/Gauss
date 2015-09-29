#include "managefeesdialog.h"
#include "ui_managefeesdialog.h"


#include <QStandardItemModel>
#include "../orm.h"
#include "../mvc.h"

ManageFeesDialog::ManageFeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageFeesDialog)
{
    ui->setupUi(this);

    populateTable();
    QList<Courses> cs = ORM::getSchuleCourses();
    for (Courses c : cs) {
        ui->comboCourses->addItem(c.getName());
    }
}

ManageFeesDialog::~ManageFeesDialog()
{
    delete ui;
}


void ManageFeesDialog::populateTable() {




    ui->tableCourses->setModel(MVC::getGeneralManageFees());
    ui->tableCourses->resizeColumnsToContents();
}

void ManageFeesDialog::on_pushSaveSchuleFee_clicked()
{
    FeeSchule fsch=FeeSchule();
    Courses cr=Courses();
    cr.setName(ui->comboCourses->currentText());
    fsch.setC(cr);
    fsch.setDat(QDate::currentDate());
    fsch.setFee(ui->lineSchuleFee->text().toFloat());

    ORM::save(fsch);
}

void ManageFeesDialog::on_tableCourses_doubleClicked(const QModelIndex &index)
{
    //values wrt time

}

void ManageFeesDialog::on_tableUniCourses_doubleClicked(const QModelIndex &index)
{
    //values wrt time

}

void ManageFeesDialog::on_tableSpracheCourses_doubleClicked(const QModelIndex &index)
{
    //values wrt time

}
