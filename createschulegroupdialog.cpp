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




   GroupModel= new  QStandardItemModel();


}

void CreateSchuleGroupDialog::populateStudentsTable(QString CourseName) {
    //fetch the student who want CourseName

    qDebug() << "populating Students table";
    RowAll=0;
    RowGroup=0;
    /*Show
     * StudentID
     * ADT
     * Name
     */
    QStringList headers;
    headers.append("StudID");
    headers.append("Name");

    QStandardItemModel *AllModel = new QStandardItemModel();
    QStandardItemModel *GroupModel=new QStandardItemModel();


    AllModel->setHorizontalHeaderLabels(headers);
    GroupModel->setHorizontalHeaderLabels(headers);

    ORM o=ORM();
    QList<Members> mathites = o.getRequestsSchule(ui->comboCourse->currentText());

    for (Members m : mathites) {
        QStandardItem *itID = new QStandardItem();
        itID->setText(QString::number(m.getMembID()));

        AllModel->setItem(RowAll,0,itID);

        QStandardItem *itName = new QStandardItem();
        itName->setText(m.getName());
        AllModel->setItem(RowAll,1,itName);

        RowAll++;


    }


    ui->tableAll->setModel(AllModel);
    ui->tableAll->resizeColumnsToContents();

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
    ui->tableTeachers->resizeColumnsToContents();

}

CreateSchuleGroupDialog::~CreateSchuleGroupDialog()
{


    delete ui;
}


void CreateSchuleGroupDialog::on_comboCourse_currentTextChanged(const QString &arg1)
{
    populateTable(ui->comboCourse->currentText());
    populateStudentsTable(ui->comboCourse->currentText());
}

void CreateSchuleGroupDialog::on_pushAddToGroup_clicked()
{
    //fetch selection from other tabel



    QModelIndexList indexList =  ui->tableAll->selectionModel()->selectedRows();
    for (QModelIndex inx : indexList) {



        RowGroup++;
        QStandardItem *itID= new QStandardItem();

        //get the ID
        QAbstractItemModel* model = ui->tableAll->model();
         QModelIndex idex =  model->index(inx.row(), 0);


        itID->setText(ui->tableAll->model()->data(idex).toString());
        GroupModel->setItem(RowGroup,0,itID);

        //get the Name
        idex =  model->index(inx.row(), 1);


        QStandardItem *itName= new QStandardItem();
        itName->setText(ui->tableAll->model()->data(idex).toString());
        GroupModel->setItem(RowGroup,1,itName);


   }





    ui->tableGroup->setModel(GroupModel);

    ui->tableGroup->resizeColumnsToContents();

    //remove selected items from tableAll:)



}

void CreateSchuleGroupDialog::on_pushRemoveFromGroup_clicked()
{



}

void CreateSchuleGroupDialog::on_pushClear_clicked()
{

}
