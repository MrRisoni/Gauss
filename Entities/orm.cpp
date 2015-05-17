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

void ORM::save(Kassen K) {
    QSqlQuery q;
    try {
        q.prepare("INSERT INTO `Kassen`  (`Name`) VALUES (:name)");
        q.bindValue(":name",K.getName());
        q.exec();

        ShowSuccess();
    }
    catch (exception& ex) {
        qDebug () << "error in saving Kassen " << ex.what();
        ShowError(q);
    }

    q.finish();
}


void ORM::saveTeacher(Teacher T) {
    QSqlQuery q;
    try {


        //query the db to get the base wages
        //INSERT INTO `Contract`(`ConID`, `TeacherID`, `End`) VALUES ([value-1],[value-2],[value-3]) 1 year



        //15 days off first record is StartDat==EndDat==day of creation
       //INSERT INTO `Erlaubnis`(`UlrID`, `TeacherID`, `StartDat`, `EndDat`, `DaysLeft`) VALUES ([value-1],[value-2],[value-3],[value-4],[value-5])

        //INSERT INTO `Faces`(`MembID`, `Pic`) VALUES ([value-1],[value-2])

       // INSERT INTO `Members`(`MembID`, `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`) VALUES ([value-1],[value-2],[value-3],[value-4],[value-5],[value-6],[value-7],[value-8],[value-9],[value-10],[value-11],[value-12],[value-13])


       // INSERT INTO `TeachOther`(`TTID`, `TeacherID`, `CourseID`) VALUES ([value-1],[value-2],[value-3])


       // INSERT INTO `Unavailable`(`UnavailID`, `TeacherID`, `DayID`, `HourID`, `Duration`) VALUES ([value-1],[value-2],[value-3],[value-4],[value-5])

        //INSERT INTO `PayKassen`(`SalID`, `TeacherID`, `Dat`, `Wages`) VALUES ([value-1],[value-2],[value-3],[value-4])
        //INSERT INTO `TeachEchelon`(`TeacherID`, `EchelonID`) VALUES ([value-1],[value-2])

       // INSERT INTO `Versicherung`(`SicherID`, `TeacherID`, `KasseID`) VALUES ([value-1],[value-2],[value-3])

        ShowSuccess();
    }
    catch (exception& ex) {
        qDebug () << "Error saving teacher " << ex.what();
        ShowError(q);
    }
    q.finish();
}

QList<Kassen> ORM::getKassen() {
    QSqlQuery q;
    QList<Kassen> Tameia;
    q.exec("Select Name From Kassen");
    while (q.next()) {
        Kassen K=Kassen();
        K.setName(q.value(0).toString());

        Tameia.append(K);
    }

    q.finish();
    return Tameia;
}



QList<BaseWages> ORM::getBaseWages() {
    QList<BaseWages> BW;

    //return the lastest schemes !!!
    QSqlQuery q;
    q.exec("Select E.EchelID, E.Exp ,B.Dat, B.Wages FROM Echelon E,BaseWages B Where B.EchelID=E.EchelID ORDER BY E.Exp DESC");
    qDebug () << "fetching base wages ...";
    while (q.next()) {


        Echelon e=Echelon();
        e.setEchelID(q.value(0).toInt());
        e.setExpYears(q.value(1).toInt());

        qDebug () << "Echelid " << q.value(0).toString() << " xp " << q.value(1).toString();
        BaseWages b=BaseWages();
        b.setD(q.value(2).toDate());
        b.setE(e);
        b.setWage(q.value(3).toFloat());

        BW.append(b);
    }

    q.finish();
    return BW;
}

QList<Days> ORM::getDays() {

    QSqlQuery q;
    QList<Days> meres;

    q.exec("SELECT DayName FROM Days");
    while (q.next()) {
        Days d=Days();
        d.setName(q.value(0).toString());

        meres.append(d);
    }

    q.finish();
    return meres;
}

QList<Hours> ORM::getHours() {
    QSqlQuery q;

    QList<Hours> Ores;
    q.exec("SELECT HourN FROM Hours");
    while (q.next()) {
        Hours h=Hours();
        h.setName(q.value(0).toString());
        Ores.append(h);
    }


    q.finish();
    return Ores;


}


QList<WagesSchule> ORM::getWagesSchule() {

    QList<WagesSchule> WgSchule;

    QSqlQuery q;
    q.exec("Select E.Exp,W.Dat,C.CourseName,W.Wage From Echelon E,WagesSchule W,Courses C WHERE E.EchelID=W.EchelID AND C.CourseID=W.CourseID");

    while (q.next()) {
        WagesSchule W=WagesSchule();

        Echelon E=Echelon();
        E.setExpYears(q.value(0).toInt());

        W.setEchel(E);

        W.setDat(q.value(1).toDate());

        Courses C=Courses();
        C.setName(q.value(2).toString());

        W.setC(C);

        W.setWage(q.value(3).toFloat());

        WgSchule.append(W);
        qDebug() << "XP " << q.value(0).toString() << " Date " << q.value(1).toDate().toString() << " Course " << q.value(2).toString() << " wages " << q.value(3).toString();
    }
    return  WgSchule;
}





QList<Courses> ORM::getSpecialCourses(QString DepName) {
    QList<Courses> CL;
    QSqlQuery q;

    q.prepare("Select C.CourseName ,S.Red,S.Green,S.Blue From Courses C,Schwierigkeit S,Departments D Where S.SchwerID=C.Schwer AND C.DepID=D.DepID And D.DepName=:dname ");
    q.bindValue(":dname",DepName);
    q.exec();

    while (q.next()) {
        Courses C=Courses();
        qDebug() << "Schule Course " << q.value(0).toString();
        C.setName(q.value(0).toString());
        Departments d=Departments();
        d.setDepName(DepName);
        C.setD(d);

        CL.append(C);
    }
    q.finish();
    qDebug() << "Schule Courses " << CL.size();
    return CL;
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

QList<Courses> ORM::getSchuleCourses() {
    QList<Courses> CL;
    QSqlQuery q;

    q.exec("Select C.CourseName ,S.Red,S.Green,S.Blue From Courses C,Schwierigkeit S Where S.SchwerID=C.Schwer AND C.DepID=1 ");
    while (q.next()) {
        Courses C=Courses();
        qDebug() << "Schule Course " << q.value(0).toString();
        C.setName(q.value(0).toString());
        CL.append(C);
    }
    q.finish();
    qDebug() << "Schule Courses " << CL.size();
    return CL;
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




void ORM::save(WagesSchule WGS) {
    QSqlQuery q;
    try{

        qDebug() << " saving WageSchule...";

        qDebug() << " xp years " << WGS.getEchel().getExpYears();
        q.prepare("Select EchelID From Echelon Where Exp=:xp");
        q.bindValue(":xp",WGS.getEchel().getExpYears());
        q.exec();
        while (q.next()) {
            WGS.getEchel().setEchelID(q.value(0).toInt());

             WGS.setEchelID(q.value(0).toInt());
             qDebug() << "EchelonID " << q.value(0).toString() << " years " << WGS.getEchel().getExpYears();

        }


         //get courseID
        qDebug() << "Course Name " << WGS.getC().getName();


        q.prepare("SELECT CourseID FROM Courses WHERE CourseName=:cname");
        q.bindValue(":cname",WGS.getC().getName());
        q.exec();

        while (q.next()) {
            WGS.getC().setCourseID(q.value(0).toInt());
            WGS.setCourseID(q.value(0).toInt());
        }

        qDebug() << "CourseID " << WGS.getCourseID();

        q.prepare("INSERT INTO `WagesSchule`  ( `EchelID`, `Dat`, `CourseID`, `Wage`) VALUES (:echid,:wann,:crsid,:wg)");
        q.bindValue(":echid",WGS.getEchelID());
        q.bindValue(":wann",WGS.getDat());
        q.bindValue(":crsid",WGS.getCourseID());
        q.bindValue(":wg",WGS.getWage());
        q.exec();




        ShowSuccess();
    }
    catch (exception& ex) {
        qDebug() << "Error " << ex.what() ;

        ShowError(q);
    }

    q.finish();
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

        qDebug() << "Error " << ex.what() ;

        ShowError(q);
    }


    q.finish();
}


void ORM::saveStudent(Members m) {
    QSqlQuery q;
    try {

        q.prepare("INSERT INTO `Members` ( `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`) VALUES (:name,:fname,:mname,:adres,:phone,:mobile,:email,'1',:rdate,:bdate,'0','0')");


        qDebug() << "name " << m.getName();
        q.bindValue(":name",m.getName());

        q.bindValue(":fname",m.getFName());
        q.bindValue(":mname",m.getMName());
        q.bindValue(":adres",m.getAddress());
        q.bindValue(":phone",m.getPhone());
        q.bindValue(":mobile",m.getMobile());
        q.bindValue(":email",m.getEmail());
        q.bindValue(":rdate",m.getRegDate());
        q.bindValue(":bdate",m.getBirthDate());

        q.exec();

        ShowSuccess();

    }
    catch (exception& ex) {


        qDebug() << "Error " << ex.what() ;

        ShowError(q);
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


        qDebug() << "Error " << ex.what() ;

        ShowError(q);
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
