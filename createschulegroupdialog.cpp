#include "createschulegroupdialog.h"
#include "ui_createschulegroupdialog.h"


#include <QStandardItemModel>
#include <QAbstractTableModel>

CreateSchuleGroupDialog::CreateSchuleGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateSchuleGroupDialog)
{
    ui->setupUi(this);


    ORM o = ORM();

    QList<Courses> Clist = o.getSchuleCourses();
    int r=0;
    for (Courses C : Clist) {
        ui->comboCourse->addItem(C.getName());
        //get color
        QColor col;
        col.setRed(C.getS().getRed());
        col.setGreen(C.getS().getGreen());

        col.setBlue(C.getS().getBlue());

        ui->comboCourse->setItemData(r,col,Qt::ForegroundRole);
        r++;
    }


    populateTable(ui->comboCourse->currentText());
    populateStudentsTable(ui->comboCourse->currentText());


}

void CreateSchuleGroupDialog::populateStudentsTable(QString CourseName) {
    //fetch the student who want CourseName

    ui->listAll->clear();

}


void CreateSchuleGroupDialog::populateTable(QString CourseName) {
    //fetch the teachers who can teach CourseName
    /* Show
     ProfID
     Name
     Current Montly
     #Total Groups
     #Total hours for this lesson
     #Current Groups
     #Latest End of contract
     */
    QStringList headers;
    headers.append("ProfID");
    headers.append("Name");
    headers.append("Monthy Salary");
    headers.append("#Groups");
    headers.append("#Hours for this lesson");
    headers.append("#Current Groups");
    headers.append("End of Contract");
    headers.append("Mobile");

    QStandardItemModel *mod = new QStandardItemModel();

    ORM o =ORM();
    QList<Teacher> profs= o.getCanTeachThis(CourseName);

    qDebug () << "fetched model from db " << profs.size();
    int r=0;
    for (Teacher p : profs) {
        QStandardItem *itID=new QStandardItem();
        itID->setText(QString::number(p.getTeacherID()));
        mod->setItem(r,0,itID);

        QStandardItem *itName=new QStandardItem();
        itName->setText(p.getName());
        mod->setItem(r,1,itName);

        QStandardItem *itSalary=new QStandardItem();
        itSalary->setText("0");
        mod->setItem(r,2,itSalary);

        QStandardItem *itGroups=new QStandardItem();
        itGroups->setText("0");
        mod->setItem(r,3,itGroups);

        QStandardItem *itHours=new QStandardItem();
        itHours->setText("0");
        mod->setItem(r,4,itHours);

        QStandardItem *itCurGroups=new QStandardItem();
        itCurGroups->setText("0");
        mod->setItem(r,5,itCurGroups);

        QStandardItem *itEOC=new QStandardItem();
        itEOC->setText(p.getEndOfContract().toString());
        mod->setItem(r,6,itEOC);

        r++;
    }

    mod->setHorizontalHeaderLabels(headers);
    ui->tableTeachers->setModel(mod);

}

CreateSchuleGroupDialog::~CreateSchuleGroupDialog()
{
    QAbstractItemModel *mod =ui->tableTeachers->model();
    delete mod;

    delete ui;
}


void CreateSchuleGroupDialog::on_comboCourse_currentTextChanged(const QString &arg1)
{
    populateTable(ui->comboCourse->currentText());
    populateStudentsTable(ui->comboCourse->currentText());
}
