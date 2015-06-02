#include "addnewschwerdialog.h"
#include "ui_addnewschwerdialog.h"


#include <QColorDialog>
#include <QAbstractItemModel>
#include  "../mvc.h"


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


    //QStandardItemModel *mod=new QStandardItemModel();


//    ORM O=ORM();

//    AddSchwerDialogMVC mvc=O.getSchwerMVC();

//    mod->setHorizontalHeaderLabels(mvc.headers);


//    int row=0;

//    for (SchwerModel m : mvc.SchwerView) {
//        QStandardItem *itID=new QStandardItem();
//        itID->setText(m.SchwerID);



//        QBrush br;
//        QColor col;

//        col.setRed(m.red.toInt());
//        col.setBlue(m.blue.toInt());
//        col.setGreen(m.green.toInt());

//        br.setColor(col);
//        br.setStyle(Qt::SolidPattern);
//        itID->setBackground(br);
//        mod->setItem(row,0,itID);




//        QStandardItem *itNumCourses=new QStandardItem();
//        itNumCourses->setText(m.NumCourses);
//        mod->setItem(row,1,itNumCourses);

//        row++;
//    }




    ui->tableSchwer->setModel(MVC::getGeneral_SchwierigModel());


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
