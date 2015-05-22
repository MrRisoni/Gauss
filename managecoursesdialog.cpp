#include "managecoursesdialog.h"
#include "ui_managecoursesdialog.h"


#include <QStandardItemModel>


ManageCoursesDialog::ManageCoursesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageCoursesDialog)
{
    ui->setupUi(this);


    //fetch Shweriegkeit levels

    ORM O=ORM();
    int row=0;

    Stuffen=O.getSchwer();
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

    //fetch departments
    QList<Departments> Deps=O.getDeps();
    for (Departments d : Deps) {
        ui->comboDepName->addItem(d.getDepName());
    }


    populateTable();



}

ManageCoursesDialog::~ManageCoursesDialog()
{
    QAbstractItemModel *mod= ui->tableCourses->model();
    delete mod;

    delete ui;
}

void ManageCoursesDialog::on_pushSaveCourses_clicked()
{

    if (ui->lineCourse->text().length()>3) {
        Courses C=Courses();

        Departments D=Departments();
        D.setDepName(ui->comboDepName->currentText());
        C.setD(D);


        C.setName(ui->lineCourse->text());
        C.setSchwerID(ui->comboSchwer->currentText().toInt());

        ORM O=ORM();

        O.save(C);
    }

    populateTable();
}


void ManageCoursesDialog::populateTable() {
    /* Show
      CourseID
      Course Name
      Dep Name
      Schwer
      #Teachers
      #Students
      #Groups
      #Open Requests
      PaySchemes?
      Fee Update
      */

    QStandardItemModel *mod=new QStandardItemModel();
    QStringList headerLabs;
    headerLabs.append("CourseID");
    headerLabs.append("Course Name");
    headerLabs.append("Dep Name");
    headerLabs.append("#Teachers");
    headerLabs.append("#Students");
    headerLabs.append("#Groups");
    headerLabs.append("# Open Requests");
    headerLabs.append("PaySchemes");
    headerLabs.append("Fee Update");

    mod->setHorizontalHeaderLabels(headerLabs);

    ORM o=ORM();

    QList<ManageCourseTable>  tblk = o.getManageCourseTable();

    int row=0;
    for (ManageCourseTable cour : tblk) {

        QStandardItem *itCID= new QStandardItem();
        itCID->setText(QString::number(cour.CourseID));
        mod->setItem(row,0,itCID);

        QStandardItem *itName= new QStandardItem();
        itName->setText(cour.CourseName);
        mod->setItem(row,1,itName);
        //set color
        QColor col;
        col.setRed(cour.Schwer.getRed());
        col.setBlue(cour.Schwer.getBlue());
        col.setGreen(cour.Schwer.getGreen());
        QBrush br;
        br.setColor(col);
        itName->setBackground(col);

        QStandardItem *itDepName= new QStandardItem();
        itDepName->setText(cour.DepName);
        mod->setItem(row,2,itDepName);


        QStandardItem *itTeachers= new QStandardItem();
        itTeachers->setText(QString::number(cour.NumTeachers));
        mod->setItem(row,3,itTeachers);


        QStandardItem *itStudents= new QStandardItem();
        itStudents->setText(QString::number(cour.NumStudents));
        mod->setItem(row,4,itStudents);


        QStandardItem *itGroups= new QStandardItem();
        itGroups->setText(QString::number(cour.NumGroups));
        mod->setItem(row,5,itGroups);


        QStandardItem *itRequests= new QStandardItem();
        itRequests->setText(QString::number(cour.NumOpenRequests));
        mod->setItem(row,6,itRequests);


        QStandardItem *itPayScheme= new QStandardItem();
        itPayScheme->setText(cour.PaySchemes);
        mod->setItem(row,7,itPayScheme);
        if (cour.PaySchemes!="OK") {
            //if equals to NEVER set to red
            col.setRed(255);
            col.setBlue(0);
            col.setGreen(0);
            br.setColor(col);
            itPayScheme->setBackground(col);
        }


        QStandardItem *itFeeDate= new QStandardItem();
        itFeeDate->setText(cour.FeeUpdate);
        mod->setItem(row,8,itFeeDate);


        if (cour.FeeUpdate=="NEVER") {
            //if equals to NEVER set to red
            col.setRed(255);
            col.setBlue(0);
            col.setGreen(0);
            br.setColor(col);
            itFeeDate->setBackground(col);
        }


        row++;
    }



    ui->tableCourses->setModel(mod);
    ui->tableCourses->resizeColumnsToContents();
}
