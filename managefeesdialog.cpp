#include "managefeesdialog.h"
#include "ui_managefeesdialog.h"


#include <QStandardItemModel>
#include "Entities/orm.h"

ManageFeesDialog::ManageFeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageFeesDialog)
{
    ui->setupUi(this);

    populateTable();
    ORM o=ORM();
    QList<Courses> cs=o.getSchuleCourses();
    for (Courses c : cs) {
        ui->comboCourses->addItem(c.getName());
    }
}

ManageFeesDialog::~ManageFeesDialog()
{
    delete ui;
}


void ManageFeesDialog::populateTable() {
    /*Show
     * CourseID
     * Name
     * Latest update date
     * fee
     * #Number of times changes
     * db click on row shows progression :)
     */
    QStringList headers;
    headers.append("CourseID");
    headers.append("Name");
    headers.append("Latest update");
    headers.append("Fee");
    headers.append("#Changes");

    QStandardItemModel *mod= new QStandardItemModel();
    mod->setHorizontalHeaderLabels(headers);


    ORM o=ORM();
    int r=0;
    QList<Courses> cs=o.getSchuleCourses();
    for (Courses c : cs) {
       QStandardItem *it=new QStandardItem();
       it->setText(c.getName());
       mod->setItem(r,1,it);

       r++;
    }



    ui->tableCourses->setModel(mod);
}

void ManageFeesDialog::on_pushSaveSchuleFee_clicked()
{
    FeeSchule fsch=FeeSchule();
    Courses cr=Courses();
    cr.setName(ui->comboCourses->currentText());
    fsch.setC(cr);
    fsch.setDat(QDate::currentDate());
    fsch.setFee(ui->lineSchuleFee->text().toFloat());

    ORM o = ORM();
    o.save(fsch);
}
