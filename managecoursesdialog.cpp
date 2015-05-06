#include "managecoursesdialog.h"
#include "ui_managecoursesdialog.h"


#include <QStandardItemModel>


ManageCoursesDialog::ManageCoursesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageCoursesDialog)
{
    ui->setupUi(this);

    populateTable();

    //fetch Shweriegkeit levels

    ORM O=ORM();
    int row=0;

     Stuffen=O.getSchwer();
    for (Schwierigkeit stuffe: Stuffen) {
        qDebug() << "new stuffe" << stuffe.getRed() << " " << stuffe.getGreen() << " " << stuffe.getBlue();
        ui->comboSchwer->addItem("Pick a level");
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

}

ManageCoursesDialog::~ManageCoursesDialog()
{
    delete ui;
}

void ManageCoursesDialog::on_pushSaveCourses_clicked()
{

}


void ManageCoursesDialog::populateTable() {
    /* Show
      Course Name
      Dep Name
      Schwer
      #Teachers
      #Students
      #Groups
      #Open Requests
      */

    QStandardItemModel *mod=new QStandardItemModel();
    QStringList headerLabs;

    headerLabs.append("Course Name");
    headerLabs.append("Dep Name");
    headerLabs.append("Schwer");
    headerLabs.append("#Teachers");
    headerLabs.append("#Students");
    headerLabs.append("#Groups");
    headerLabs.append("# Open Requests");

    mod->setHorizontalHeaderLabels(headerLabs);
    ui->tableCourses->setModel(mod);
}
