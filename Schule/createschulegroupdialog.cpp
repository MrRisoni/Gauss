#include "createschulegroupdialog.h"
#include "ui_createschulegroupdialog.h"

/* Fetches requests for Schule
 * Fetches teacher that can teach those courses
 * Creates a schedule for the permament
 */


#include <QStandardItemModel>
#include <QAbstractTableModel>
#include "General/roomitemdelegate.h"
#include <tuple>
#include <vector>


//use a tuple :) Column,Duration,Room , only duration changes


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


    //SCHULE TABLE MODEL

    GroupModel= new  QStandardItemModel();



    //populate the hours and days
    ScheduleModel = new QStandardItemModel();
    TimeTableHeaders HEADS= o .getTimeTableHeaders();
    ScheduleModel->setHorizontalHeaderLabels(HEADS.horHeaders);
    ScheduleModel->setVerticalHeaderLabels(HEADS.verHeaders);





    // try to add a delegate for rooms
    RoomItemDelegate *obj = new RoomItemDelegate();
    ui->tableSchedule->setItemDelegate(obj);

    ui->tableSchedule->setModel(ScheduleModel);

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


    delete ScheduleModel;

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
    //fetch selection from other tabe of students



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

void CreateSchuleGroupDialog::on_pushOK_clicked()
{
    Groups G=Groups();
    G.setActive(1);
    G.setCourseName(ui->comboCourse->currentText());
    QList<QString> meliid;

    for (int q=0;q<ui->listGroup->count();q++) {
        QListWidgetItem* itm = ui->listGroup->item(q);
        meliid.append(itm->text());
        qDebug() << "studentID " << itm->text();
    }

    G.setMeliID(meliid);
    G.setStartDate(QDate::currentDate());
    //get selection from Qtable View


    QModelIndexList indexList =  ui->tableTeachers->selectionModel()->selectedRows();
    for (QModelIndex inx : indexList) {


        //get the ID
        QAbstractItemModel* model = ui->tableTeachers->model();
        QModelIndex idex =  model->index(inx.row(), 0);
        QString teacherID=ui->tableTeachers->model()->data(idex).toString();
        G.setTeacherID(teacherID);
        qDebug() << "teacherID " << teacherID;
    }




    // Show the created schedule
    qDebug() << "CLICKED SCHEDULE INDICES";
    // http://stackoverflow.com/questions/5927499/how-to-get-selected-rows-in-qtableview





    QModelIndexList scheduleIndexList = ui->tableSchedule->selectionModel()->selectedIndexes();


     //ADD A DAY ONLY ONCE!!!!!!!!!!!!!!!
     //THE NUMBER OF SELECTED ROWS PER COL IS THE DURATION
    //parallel vectors = length is equal to selected cols
      QList<int> ColIDs;
      QList<float> Dur;
      QList<QString> RoomName;
      QList<int> StartHour;// first row of that column


    int colpos;

    //each time append 0.5 since the unit measure in 30 minutes
    for (QModelIndex inx :  scheduleIndexList) {
        qDebug() << "selected  schedule indices " << inx.row() << " " << inx.column() << " room " << ui->tableSchedule->model()->data(inx).toString();

        //PRIMARY KEYS START FROM 1 these ids from ZERO so add one to col and row
        //search for ColID
         colpos= ColIDs.indexOf(inx.column()+1);

         qDebug() << " col pos for element " << inx.column() << " " << colpos;
        if (colpos==-1) {
            qDebug() << "day " << inx.column()+1 << " is inserted for the first time ";
            //col does not exist add it to the list
            ColIDs.append(inx.column()+1);
            StartHour.append(inx.row()+1);
            //append duration
            Dur.append(0.5f);
            RoomName.append(ui->tableSchedule->model()->data(inx).toString());
        }
        else {
            qDebug() << " updated duration for day  " << inx.column() +1 ;
            //update duration value
            Dur[colpos] += 0.5f;

        }
    }


    //create a permatimes array
    QList<Permatimes> Programma;


    //iterate lists
    for (int r=0;r<ColIDs.size();r++) {

        Permatimes pr= Permatimes();
        pr.setDayID(ColIDs.at(r));
        pr.setRoom(RoomName.at(r));
        pr.setDiarkeia(Dur.at(r));
        pr.setStartHourID(StartHour.at(r));
        Programma.append(pr);
    }

    //create permament
    Permament p =Permament();
    p.setStarts(QDate::currentDate());
    p.setEnds(QDate::currentDate().addDays(ui->lineDuration->text().toInt()));
    qDebug() << "end date " << QDate::currentDate().addDays(ui->lineDuration->text().toInt());


    ORM o= ORM();
    o.saveSchule(G,p,Programma);

}

void CreateSchuleGroupDialog::on_pushAddExisting_clicked()
{
    //insert to a random active group for that course
    //set request to settled
}
