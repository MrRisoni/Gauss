#include "orm.h"
#include <exception>
#include <iostream>


using namespace std;


ORM::ORM()
{

}

ORM::~ORM()
{

}




int ORM::save(Schwierigkeit schw) {
    QSqlQuery q;


    try {
    qDebug() << "saving object schw";
    QString s="INSERT INTO `Schwierigkeit`  ( `Red`, `Green`, `Blue`) VALUES (:r,:g,:b)";
    q.prepare(s);
    q.bindValue(":r",schw.getRed());
    q.bindValue(":g",schw.getGreen());
    q.bindValue(":b",schw.getBlue());

    q.exec();






}
    catch (exception& ex) {
    QMessageBox msgBox;
    msgBox.setText(q.lastError().text()+ ex.what());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Warning);
    int ret = msgBox.exec();
}


    q.finish();

}
