#include "addnewschwerdialog.h"
#include "ui_addnewschwerdialog.h"


#include <QColorDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QSqlQuery>

AddNewSchwerDialog::AddNewSchwerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewSchwerDialog)
{
    ui->setupUi(this);

    LoadColors();

}

void AddNewSchwerDialog::LoadColors() {
    /*
     Show color and number of courses :)
     SElect Count(CourseID) From Courses Group by SchwerID 
     
     */


    QStandardItemModel *mod=new QStandardItemModel();

    mod->setColumnCount(2);

    mod->setHorizontalHeaderItem(0,new QStandardItem("Schwer ID"));
    mod->setHorizontalHeaderItem(1,new QStandardItem("#Courses"));

    QSqlQuery q;

    q.exec("Select * From Schwierigkeit");
    int row=0;
    while (q.next()) {
        QStandardItem *it=new QStandardItem();
        it->setText(q.value(0).toString());
        int red=q.value(1).toInt();
        int green=q.value(2).toInt();
        int blue=q.value(3).toInt();
        QBrush br;
        QColor col;

        col.setRed(red);
        col.setBlue(blue);
        col.setGreen(green);

        br.setColor(col);
        br.setStyle(Qt::SolidPattern);
        it->setBackground(br);
        mod->setItem(row,0,it);
        row++;
    }




    ui->tableSchwer->setModel(mod);
    q.finish();

    ui->tableSchwer->resizeColumnsToContents();


}




AddNewSchwerDialog::~AddNewSchwerDialog()
{
    qDebug() << "deleting memory??";

    QAbstractItemModel *mod=ui->tableSchwer->model();

    delete mod;

    delete ui;



}



void AddNewSchwerDialog::on_pushPickColor_clicked()
{
    //QColorDialog *col=new QColorDialog();
    //col->show();

    QColor color = QColorDialog::getColor();


    QPalette palette = ui->labelTest->palette();
    palette.setColor(ui->label->foregroundRole(), color);
    ui->labelTest->setPalette(palette);

    red=color.red();
    green=color.green();
    blue=color.blue();


}

void AddNewSchwerDialog::on_pushSave_clicked()
{
    ORM myorm= ORM();
    Schwierigkeit schw=Schwierigkeit();
    schw.setBlue(blue);
    schw.setRed(red);
    schw.setGreen(green);
    qDebug() << "red " << QString::number(schw.getRed()) << " " << QString::number(schw.getGreen()) << " " << QString::number(schw.getBlue());
    myorm.save(schw);

    LoadColors();


}
