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

    //fix memory leaks
    QAbstractItemModel *modelo = ui->tableAll->model();
    delete modelo;






    qDebug() << "populating Students table";
    RowAll=0;
    /*Show
     * StudentID
     * ADT
     * Name
     */
    QStringList headers;
    headers.append("StudID");
    headers.append("Name");

    QStandardItemModel *AllModel = new QStandardItemModel();


    AllModel->setHorizontalHeaderLabels(headers);

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

    //fix memory leaks

    QAbstractItemModel *modelo = ui->tableTeachers->model();
    delete modelo;



    QStandardItemModel *mod = new QStandardItemModel();


    ORM o =ORM();
    SchuleTeacherMVC profs= o.getCanTeachSchuleMVC(CourseName);

    mod->setHorizontalHeaderLabels(profs.SchuleTeacherViewHeaders);


    int r=0;
    for (SchuleTeacher p : profs.SchuleTeacherModel) {

        QStandardItem *itID=new QStandardItem();
        itID->setText(p.ProfID);
        mod->setItem(r,0,itID);

        QStandardItem *itName=new QStandardItem();
        itName->setText(p.Name);
        mod->setItem(r,1,itName);

        QStandardItem *itSalary=new QStandardItem();
        itSalary->setText(p.Monthy_Base_Salary);
        mod->setItem(r,2,itSalary);

        QStandardItem *itGroups=new QStandardItem();
        itGroups->setText(p.Groups);
        mod->setItem(r,3,itGroups);

        QStandardItem *itHours=new QStandardItem();
        itHours->setText(p.Hours_for_this_lesson);
        mod->setItem(r,4,itHours);

        QStandardItem *itCurGroups=new QStandardItem();
        itCurGroups->setText(p.Current_Groups);
        mod->setItem(r,5,itCurGroups);



        QStandardItem *itEOC=new QStandardItem();
        itEOC->setText(p.End_of_Contract);
        mod->setItem(r,6,itEOC);

        QStandardItem *itMobile=new QStandardItem();
        itMobile->setText(p.Mobile);
        mod->setItem(r,7,itMobile);




        r++;
    }

    ui->tableTeachers->setModel(mod);
    ui->tableTeachers->resizeColumnsToContents();

}

CreateSchuleGroupDialog::~CreateSchuleGroupDialog()
{
    //fix memory leaks

    QAbstractItemModel *mod = ui->tableTeachers->model();
    delete mod;

    mod=ui->tableAll->model();
    delete mod;




    delete ui;

    qDebug() << "deleted";

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



        QListWidgetItem *it=new QListWidgetItem();

        //get the ID
        QAbstractItemModel* model = ui->tableAll->model();
         QModelIndex idex =  model->index(inx.row(), 0);


         //check for duplicates
         QString new_studentID=ui->tableAll->model()->data(idex).toString();
         bool found=false;

         for (int q=0;q<ui->listGroup->count();q++) {
                 QListWidgetItem* itm = ui->listGroup->item(q);
                 if (itm->text()==new_studentID) {
                     found = true;
                 }
        }
        if (found==false) {
            ui->listGroup->addItem(new_studentID);
            }




   }









}

void CreateSchuleGroupDialog::on_pushRemoveFromGroup_clicked()
{



}

void CreateSchuleGroupDialog::on_pushClear_clicked()
{
   ui->listGroup->clear();



}
