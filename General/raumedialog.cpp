#include "raumedialog.h"
#include "ui_raumedialog.h"


#include <QStandardItemModel>
#include <QInputDialog>
#include <QStandardItem>
#include "../mvc.h"
#include "../orm.h"


RaumeDialog::RaumeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaumeDialog)
{
    ui->setupUi(this);
    populateTable();
    populateRoomTable();


    //fetch Buildings
    QList<Buildings> Bs= ORM::getBuildings();
    for (Buildings b :Bs) {
        ui->comboBuilding->addItem(b.getName());
    }
}

RaumeDialog::~RaumeDialog()
{
    QAbstractItemModel *mod=ui->tableBuildings->model();
    delete mod;

    mod=ui->tableRooms->model();
    delete mod;
    delete ui;
}

void RaumeDialog::on_pushAdd_clicked()
{

    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);

    QString text =  inputDialog->getText(NULL ,"Gauss",
                                             "Enter address", QLineEdit::Normal);
    if (text.length()>0) {
        Buildings b = Buildings() ;
        b.setName(text);
        ORM::save(b);

    }

    populateTable();



}


void RaumeDialog::populateTable() {
    /*Show
     * BuildingID
     * Address
     * #Rooms
     */

    QStringList headers;
    headers.append("BuildID");
    headers.append("Address");
    headers.append("#Rooms");

    QStandardItemModel *mod = new QStandardItemModel();
    mod->setHorizontalHeaderLabels(headers);


    QList<Buildings> Bs = ORM::getBuildings();
    int r=0;
    for (Buildings b :Bs) {

        QStandardItem *itID=new QStandardItem();
        itID->setText(QString::number(b.getBuildingID()));
        mod->setItem(r,0,itID);

        QStandardItem *itAddress = new QStandardItem();
        itAddress->setText(b.getName());
        mod->setItem(r,1,itAddress);

        QStandardItem *itRooms = new QStandardItem();
        itRooms->setText(QString::number(b.getRoomsNum()));
        mod->setItem(r,2,itRooms);

        r++;
    }

    ui->tableBuildings->setModel(mod);
    ui->tableBuildings->resizeColumnsToContents();


}


void RaumeDialog::populateRoomTable() {



    ui->tableRooms->setModel(MVC::getGeneral_Rooms());
    ui->tableRooms->resizeColumnsToContents();

}

void RaumeDialog::on_pushAddRoom_clicked()
{

    Rooms R= Rooms();
    Buildings b=Buildings();
    b.setName(ui->comboBuilding->currentText());
    R.setB(b);
    R.setCapacity(ui->lineCapacity->text().toInt());
    R.setName(ui->lineName->text());

    ORM::save(R);
    populateRoomTable();
}
