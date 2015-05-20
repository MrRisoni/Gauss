#include "addnewrequestdialog.h"
#include "ui_addnewrequestdialog.h"


#include "Entities/orm.h"


AddNewRequestDialog::AddNewRequestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewRequestDialog)
{
    ui->setupUi(this);

    //fetch schule courses

    ORM o = ORM();

    QList<Courses> Clist = o.getSchuleCourses();
    int r=0;
    for (Courses C : Clist) {
        ui->comboSchuleCourses->addItem(C.getName());
        //get color
        QColor col;
        col.setRed(C.getS().getRed());
        col.setGreen(C.getS().getGreen());

        col.setBlue(C.getS().getBlue());

        ui->comboSchuleCourses->setItemData(r,col,Qt::ForegroundRole);
        r++;
    }


}

AddNewRequestDialog::~AddNewRequestDialog()
{
    delete ui;
}

void AddNewRequestDialog::on_pushSearch_clicked()
{

    ORM o = ORM();

    Members m = o.searchStudentByName(ui->lineSearchQuery->text());
    qDebug() << m;
    //serialization m to string
}
