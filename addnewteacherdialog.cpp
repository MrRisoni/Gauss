#include "addnewteacherdialog.h"
#include "ui_addnewteacherdialog.h"


#include "Entities/orm.h"
#include <QListWidgetItem>

AddNewTeacherDialog::AddNewTeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewTeacherDialog)
{
    ui->setupUi(this);


    ORM cppHib = ORM();
    //fetch deps
    QList<Departments> Ds = cppHib.getDeps();
    for (Departments d : Ds) {
        ui->comboDeps->addItem(d.getDepName());
    }

    //fetch schem
     QList<BaseWages> bwL=cppHib.getBaseWages();

     QStandardItemModel *mod=new QStandardItemModel();
     QStringList headers;
     headers.append("EchelID");
     headers.append("XP");
     headers.append("Dat");
     headers.append("Wages");
     mod->setHorizontalHeaderLabels(headers);

     int r=0;
     for (BaseWages b : bwL) {
         QStandardItem *itEchelID=new QStandardItem();
          itEchelID->setText(QString::number(b.getE().getEchelID()));

         QStandardItem *itXP=new QStandardItem();
         itXP->setText(QString::number(b.getE().getExpYears()));

         QStandardItem *itDat=new QStandardItem();
         itDat->setText(b.getD().toString());

         QStandardItem *itWages=new QStandardItem();
         itWages->setText(QString::number(b.getWage()));

         mod->setItem(r,0,itEchelID);
         mod->setItem(r,1,itXP);
         mod->setItem(r,2,itDat);
         mod->setItem(r,3,itWages);

         r++;

     }
     ui->tableSalary->setModel(mod);
     ui->tableSalary->resizeColumnsToContents();




    //fetch langs


    coursesModel=new QStandardItemModel();
    QStringList labs;
    labs.append("Department");
    labs.append("Course");

    coursesModel->setHorizontalHeaderLabels(labs);

    //fetch hours and dates for the unavailable table


    QList<Days> Tage=cppHib.getDays();
    QList<Hours> Studen=cppHib.getHours();

    QStringList horLabels,verLabels;

    for (Days t : Tage) {
        horLabels.append(t.getName());
    }

    for (Hours s : Studen) {
        verLabels.append(s.getName());
    }

    QStandardItemModel *unavailModel=new QStandardItemModel();
    unavailModel->setHorizontalHeaderLabels(horLabels);
    unavailModel->setVerticalHeaderLabels(verLabels);
    ui->tableUnAvail->setModel(unavailModel);
    ui->tableUnAvail->resizeColumnsToContents();

    //fetch Kassen
    QList<Kassen> Tameia = cppHib.getKassen();
    for (Kassen K : Tameia) {
        ui->comboKassen->addItem(K.getName());
    }


}

AddNewTeacherDialog::~AddNewTeacherDialog()
{
    delete ui;
}

void AddNewTeacherDialog::on_comboDeps_currentTextChanged(const QString &arg1)
{
    //load the courses from the db
    ui->listAllCourses->clear();
    ORM o =ORM();
    QList<Courses> clist=o.getSpecialCourses(arg1);

    for (Courses c  : clist) {


        ui->listAllCourses->addItem(c.getName());
    }
}

void AddNewTeacherDialog::on_listAllCourses_itemDoubleClicked(QListWidgetItem *item)
{
    //copy paste that to can teach
    //create a model

    qDebug() << " double clicked on " << item->text();
    QStandardItem *itDepName=new QStandardItem();
    itDepName->setText(ui->comboDeps->currentText());

    coursesModel->setItem(row,0,itDepName);

    QStandardItem *itCourseName=new QStandardItem();

    coursesModel->setItem(row,1,itCourseName);
    itCourseName->setText(item->text());

    row++;

    ui->tableCanCourses->setModel(coursesModel);

    ui->tableCanCourses->resizeColumnsToContents();

}

