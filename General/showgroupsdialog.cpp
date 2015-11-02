#include "showgroupsdialog.h"
#include "ui_showgroupsdialog.h"
#include <QMessageBox>
#include  "../mvc.h"
#include "../orm.h"


ShowGroupsDialog::ShowGroupsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowGroupsDialog)
{
    ui->setupUi(this);

    ui->tableAllGroups->setModel(MVC::getGeneral_ShowGroup_Model());

    ui->tableAllGroups->resizeColumnsToContents();






    for (Hours h : ORM::getHours()) {
        ui->comboStart->addItem(h.getName());
    }
}

ShowGroupsDialog::~ShowGroupsDialog()
{
    delete ui->tableAllGroups->model();
    delete ui->tablePastLessons->model();
    delete ui;
}

void ShowGroupsDialog::on_pushCancel_clicked()
{

    QList<QString> dats;
    for (QListWidgetItem* it : ui->listFutureDates->selectedItems()) {
        dats.append(it->text());
    }


    ORM::CancelLesson( group_id,dats) ;

    qDebug () << "example for empty form validation";
}

void ShowGroupsDialog::on_tableAllGroups_doubleClicked(const QModelIndex &index)
{
    //get group id , teacher name , course name
    QAbstractItemModel* model =  ui->tableAllGroups->model();

    QModelIndex group_index =  model->index(index.row(), 0);
    QModelIndex teacher_index = model->index(index.row(), 1);
    QModelIndex course_index =  model->index(index.row(), 4);

    qDebug() << "clicked on " << index.row() << " " << index.column();


    qDebug() << " groupid " << ui->tableAllGroups->model()->data(group_index).toString();
    qDebug() << " Course Name " << ui->tableAllGroups->model()->data(teacher_index).toString();
    qDebug() << " Teacher Name " << ui->tableAllGroups->model()->data(course_index).toString();

    QString tmp=ui->tableAllGroups->model()->data(group_index).toString();
    tmp+= " " + ui->tableAllGroups->model()->data(teacher_index).toString();
    tmp+= " " + ui->tableAllGroups->model()->data(course_index).toString();



    group_id= ui->tableAllGroups->model()->data(group_index).toString();
    ui->labelSelectedDetails->setText(tmp);


    ui->tablePastLessons->setModel(MVC::getGeneral_ShowPastHistory(group_id));
    ui->tablePastLessons->resizeColumnsToContents();



    ui->listFutureDates->clear();
    for (QListWidgetItem *it : MVC::getGeneral_ShowFutureHistoryDates(group_id) ) {
            ui->listFutureDates->addItem(it);

    }



    ui->tableGroupSchulden->setModel(MVC::getGroupPays(group_id));
    ui->tableGroupSchulden->resizeColumnsToContents();
}

void ShowGroupsDialog::on_pushAddTempo_clicked()
{


    qDebug() << "go on ";

    ORM::AddTempLesson(group_id,ui->calendarTempo->selectedDate(),ui->comboStart->currentText(),ui->lineDuration->text().toFloat());

}

