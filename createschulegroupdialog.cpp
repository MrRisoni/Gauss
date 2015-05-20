#include "createschulegroupdialog.h"
#include "ui_createschulegroupdialog.h"


#include <QStandardItemModel>


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


    populateTable();


}


void CreateSchuleGroupDialog::populateTable() {
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

    QStandardItemModel *mod = new QStandardItemModel();

    mod->setHorizontalHeaderLabels(headers);

    ui->tableTeachers->setModel(mod);

}

CreateSchuleGroupDialog::~CreateSchuleGroupDialog()
{
    delete ui;
}
