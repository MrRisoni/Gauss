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



void ORM::save(Echelon E) {
    QSqlQuery q;
    try {
        q.prepare("INSERT INTO `Echelon`  (`Exp`) VALUES (:jahr)");
        q.bindValue(":jahr",E.getExpYears());
        q.exec();
         ShowSuccess();

    }
    catch (exception& ex) {
        qDebug() << "Error " << ex.what() ;

        ShowError(q);
    }
    q.finish();

}





void ORM::save(Courses C) {
    QSqlQuery q;
    try {
        qDebug() << "saving Course";
        //fetch department ID
        q.prepare("Select DepID From Departments Where DepName=:dpname");
        q.bindValue(":dpname",C.getD().getDepName());
        q.exec();
        int depid;
        while (q.next()) {
           depid=q.value(0).toInt();
        }

        qDebug() << "dep id" << depid << " schwer " << C.getSchwerID();

        q.prepare("INSERT INTO `Courses`   ( `DepID`, `CourseName`, `Schwer`, `Active`) VALUES (:dpid,:name,:schwid,'1')");
        q.bindValue(":dpid",depid);
        q.bindValue(":name",C.getName());
        q.bindValue(":schwid",C.getSchwerID());
         q.exec();

         ShowSuccess();
    }
    catch (exception& ex) {
        qDebug() << "Error " << ex.what() ;

        ShowError(q);
    }
    q.finish();

}



void ORM::save(Departments D) {

    QSqlQuery q;
    try {
        q.prepare("INSERT INTO `Departments`  (`DepName`) VALUES (:dep)");
        q.bindValue(":dep",D.getDepName());
        q.exec();
        q.finish();
        qDebug() << "saved department object" << D.getDepName();


    }
    catch (exception& ex) {
        qDebug() << "Error " << ex.what() ;

        ShowError(q);
    }
}



void ORM::ShowSuccess() {
    QMessageBox msgBox;
    msgBox.setText("OK");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Information);
    int ret = msgBox.exec();

}



void ORM::ShowError(QSqlQuery q) {
    QMessageBox msgBox;
    msgBox.setText(q.lastError().text());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Warning);
    int ret = msgBox.exec();
    q.finish();
}



QList<Schwierigkeit> ORM::getSchwer() {

    QList<Schwierigkeit> L;
    QSqlQuery q;
    q.exec("Select SchwerID,Red,Green,Blue From Schwierigkeit");
    while (q.next()) {
      Schwierigkeit s;
      s.setSchwerID(q.value(0).toInt());
      s.setRed(q.value(1).toInt());
      s.setGreen(q.value(2).toInt());
      s.setBlue(q.value(3).toInt());
      L.append(s);
    }

    q.finish();
    return L;
}

QList<Departments> ORM::getDeps() {

    QList<Departments> D;
    QSqlQuery q;
    q.exec("Select DepID,DepName From Departments");
    while (q.next()) {
        Departments dep=Departments();
        dep.setDepID(q.value(0).toInt());
        dep.setDepName(q.value(1).toString());
        D.append(dep);
    }

    q.finish();
    return D;
}







void ORM::save(BaseWages BW) {
    QSqlQuery q;
    try {
        //fetch echelon id
        q.prepare("Select EchelID From Echelon Where Exp=:xp");
        q.bindValue(":xp",BW.getE().getExpYears());
        q.exec();
        int EchID;
        while (q.next()) {
            EchID=q.value(0).toInt();
        }

        q.prepare("INSERT INTO `BaseWages`   ( `EchelID`, `Dat`, `Wages`) VALUES (:echelid,:dt,:wg)");
        q.bindValue(":echelid",EchID);
        q.bindValue(":dt",QDate::currentDate());
        q.bindValue(":wg",BW.getWage());
        q.exec();

            ShowSuccess();
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



void ORM::save(Schwierigkeit schw) {
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


QList<Echelon> ORM::getEchels() {
    QList<Echelon> Ech;

    QSqlQuery q;
    q.exec("Select Exp From Echelon");
    while (q.next()) {
        Echelon c=Echelon();
        c.setExpYears(q.value(0).toInt());
        Ech.append(c);
    }
    q.finish();
    return Ech;
}
