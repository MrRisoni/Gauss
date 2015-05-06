#include "managedepsdialog.h"
#include "ui_managedepsdialog.h"

ManageDepsDialog::ManageDepsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDepsDialog)
{
    ui->setupUi(this);

    populateTable();


}

ManageDepsDialog::~ManageDepsDialog()
{
    delete ui;
}



void ManageDepsDialog::populateTable() {
    /* Show the following
      Depname
      #Courses
      #Teachers
      #Students
      */

}

void ManageDepsDialog::on_pushSaveDep_clicked()
{
    ORM O=ORM();
    Departments d=Departments();
    d.setDepName(ui->lineDep->text());

    qDebug() << "prepared department object" ;

    O.save(d);
    populateTable();
}
