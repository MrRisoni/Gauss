#include "raumedialog.h"
#include "ui_raumedialog.h"


#include <QStandardItemModel>
#include <QInputDialog>
#include <QStandardItem>


RaumeDialog::RaumeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaumeDialog)
{
    ui->setupUi(this);
    populateTable();
    populateRoomTable();


    //fetch Buildings
    ORM o=ORM();
    QList<Buildings> Bs=o.getBuildings();
    for (Buildings b :Bs) {
        ui->comboBuilding->addItem(b.getName());
    }
}

RaumeDialog::~RaumeDialog()
{
    delete ui;
}

void RaumeDialog::on_pushAdd_clicked()
{

    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);

    QString text =  inputDialog->getText(NULL ,"Gauss",
                                             "Enter address", QLineEdit::Normal);
    if (text.length()>0) {
        ORM O=ORM();
        Buildings b=Buildings() ;
        b.setName(text);
        O.save(b);

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


    ORM o=ORM();
    QList<Buildings> Bs=o.getBuildings();
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
    /*Show
     * RoomID
     * Building
     * Name
     * Capacity
     */

    QStringList headers;
    headers.append("RoomID");
    headers.append("Building");
    headers.append("Name");
    headers.append("Capacity");

    QStandardItemModel *mod=new QStandardItemModel();
    mod->setHorizontalHeaderLabels(headers);


    ORM o=ORM();
    QList<Rooms> domatia=o.getRooms();
    int row=0;
    for (Rooms D : domatia) {
        QStandardItem *itRoomID=new QStandardItem();
        itRoomID->setText(QString::number(D.getRoomID()));

        mod->setItem(row,0,itRoomID);

        QStandardItem *itAddress=new QStandardItem();
        itAddress->setText(D.getB().getName());

        mod->setItem(row,1,itAddress);


        QStandardItem *itName=new QStandardItem();
        itName->setText(D.getName());

        mod->setItem(row,2,itName);


        QStandardItem *itCapacity=new QStandardItem();
        itCapacity->setText(QString::number(D.getCapacity()));

        mod->setItem(row,3,itCapacity);
        row++;

    }




    ui->tableRooms->setModel(mod);
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

    ORM o =ORM();
    o.save(R);
    populateRoomTable();
}
