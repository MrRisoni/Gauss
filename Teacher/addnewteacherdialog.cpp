#include "addnewteacherdialog.h"
#include "ui_addnewteacherdialog.h"


#include <QFileDialog>
#include "../mvc.h"

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


     ui->tableSalary->setModel(MVC::getReceiptBaseWages());
     ui->tableSalary->resizeColumnsToContents();




    //fetch langs
    QList<Languages> langs = cppHib.getSprachen();
    for (Languages L : langs) {
        ui->comboSprachen->addItem(L.getName());
    }






    coursesModel=new QStandardItemModel();
    QStringList labs;
    labs.append("CourseID");
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


void AddNewTeacherDialog::on_pushSaveTeacher_clicked()
{
    Teacher t=Teacher();

    t.setAddress(ui->lineAddress->text());


    t.setBirthDate(ui->calendarBirth->selectedDate());

    //get all the table data
    QList<Courses> kann_Lehren;

     qDebug () << "fetching courses he can teach";
    QAbstractItemModel* model = ui->tableCanCourses->model();

    qDebug() << "can teach " << model->rowCount();

    for (int r=0;r<model->rowCount();r++) {
        qDebug() << "-----------------";
        QModelIndex idx = model->index(r, 0);

        Courses C=Courses();
        Departments D=Departments();
        D.setDepName(model->data(idx).toString());
        qDebug () << "dep name " << model->data(idx).toString();
        C.setD(D);


        idx = model->index(r, 1);

        C.setName(model->data(idx).toString());

        qDebug () << "course name " << model->data(idx).toString();

        kann_Lehren.append(C);
    }


    t.setCanTeach(kann_Lehren);

    t.setEmail(ui->lineEmail->text());

    t.setEndOfContract(QDate::currentDate().addDays(370));

    t.setFName(ui->lineFName->text());
    t.setMName(ui->lineMName->text());
    t.setMobile(ui->lineMobile->text());
    t.setName(ui->lineName->text());
    t.setPhone(ui->linePhone->text());



    QByteArray Arr;

    QBuffer buffer( &Arr );
    buffer.open( QIODevice::WriteOnly );

    t.setPhoto(Arr);
    t.setRegDate(QDate::currentDate());


    //get the selected cells from ui table unavail
    QList<Unavailable> Kann_Nicht_Sein;

    QModelIndexList indexList = ui->tableUnAvail->selectionModel()->selectedIndexes();
    foreach (QModelIndex index, indexList) {


        //add one because SQL primary keys start from one
        Unavailable U=Unavailable();
        Hours H=Hours();
        H.setHourID(index.column()+1);
        U.setStartStude(H);

        Days tg=Days();
        tg.setDayID(index.row()+1);

        U.setTag(tg);
        Kann_Nicht_Sein.append(U);


   }




    t.setUnAvailability(Kann_Nicht_Sein);

    Kassen Ks=Kassen();
    Ks.setName(ui->comboKassen->currentText());

    t.setVersichern(Ks);

    //get text
    int selected_Echel = ui->tableSalary->selectionModel()->currentIndex().row();

    Echelon e=Echelon();
    e.setEchelID(ui->tableSalary->model()->index(selected_Echel , 0).data().toInt());
    t.setEch(e);

    PayKassen pk=PayKassen();
    pk.setDat(QDate::currentDate());
    pk.setWages(ui->lineKasse->text().toFloat());
    t.setPayKasse(pk);

    ORM o=ORM();
    o.setDb(getDb());
    o.saveTeacher(t);


}
QSqlDatabase AddNewTeacherDialog::getDb() const
{
    return db;
}

void AddNewTeacherDialog::setDb(const QSqlDatabase &value)
{
    db = value;
}


void AddNewTeacherDialog::on_pushLoadPic_clicked()
{




}

void AddNewTeacherDialog::on_pushESymvasis_clicked()
{

}

void AddNewTeacherDialog::on_pushLoadPic_2_clicked()
{


}

void AddNewTeacherDialog::on_comboSprachen_activated(const QString &arg1)
{
    ui->listAllDiplomas->clear();
    ORM o =  ORM();
    for (QString s : o.getDiplomaForThatLanguage(arg1)) {
        ui->listAllDiplomas->addItem(s);
    }
}

void AddNewTeacherDialog::on_listAllDiplomas_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listCanDiplomas->addItem(item->text());
}
