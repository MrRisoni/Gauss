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


QList<Members> ORM::getRequestsSchule(QString CourseName) {
    QList<Members>  Ms;
    QSqlQuery q;
    q.prepare("SELECT M.MembID,M.Name FROM RequestSchule R,Courses C,Members M WHERE R.Settled=0 AND M.MembID=R.StudentID AND C.CourseID=R.CourseID AND C.CourseName =:cn");
    q.bindValue(":cn",CourseName);
    q.exec();

    while (q.next()) {

        Members m=Members();
        m.setMembID(q.value(0).toInt());
        m.setName(q.value(1).toString());
        Ms.append(m);


        qDebug() << QString::number(m.getMembID()) << " " << m.getName();


    }

    q.finish();
    return Ms;
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

QString ORM::generateADT() {
    //generates a 8 digit ADT
    QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");


    QString randomString;
    for(int i=0; i<2; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    int High=9;
    int Low=0;
    for (int i=0;i<6;i++) {
        randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
    }
    return randomString;

}


QString ORM::generateAFM() {
    QString randomString;
    int High=9;
    int Low=0;
    for (int i=0;i<7;i++) {
        randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
    }
    return randomString;
}


QList<Teacher> ORM::getCanTeachThis(QString CourseName) {
    QList<Teacher> Lehren;
    QSqlQuery q;


    QString s="SELECT M.MembID,M.Name From Members M,Courses C,TeachOther T WHERE C.CourseID=T.CourseID AND M.MembID=T.TeacherID AND C.CourseName='"+ CourseName+"'";
    qDebug() << s;
    q.exec(s);

    while (q.next()) {
        Teacher daskalos;

        daskalos.setTeacherID(q.value(0).toInt());
        daskalos.setName(q.value(1).toString());
        daskalos.setSalary(0);
        daskalos.setCurrentGroups(0);
        daskalos.setTeachingHours(0);
        daskalos.setEndOfContract(QDate::currentDate());

        qDebug() << "fetched teacher " << QString::number(daskalos.getTeacherID()) << " " << daskalos.getName() << " " << daskalos.getEndOfContract().toString() << daskalos.getSalary() << daskalos.getTeachingHours() << daskalos.getCurrentGroups();


        Lehren.append(daskalos);

        qDebug() << "appended";


    }
    q.finish();

    qDebug() << "return model";
    return Lehren;
}


QString ORM::generatePhone() {
    QString randomString="210";
    int High=9;
    int Low=0;
    for (int i=0;i<7;i++) {
        randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
    }
    return randomString;
}

QString ORM::generateMobile() {
    QString randomString="69";
    int High=9;
    int Low=0;
    for (int i=0;i<8;i++) {
        randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
    }
    return randomString;
}



void ORM::saveTeacher(Teacher T) {
    QSqlQuery q;
    try {

        T.setAFM(generateAFM());
        T.setADT(generateADT());
        T.setPhone(generatePhone());
        T.setMobile(generateMobile());


        qDebug() << "random generations" ;
        qDebug() << "AFM " <<  T.getAFM();
        qDebug() << "ADT " << T.getADT();
        qDebug() << "Phone " << T.getPhone();
        qDebug() << "Mobile " << T.getMobile();

        qDebug() << "Trying to save teacher " ;
        //query the db to get CourseIDs

        QList<Courses> Didaskalia = T.getCanTeach();
        for (int y=0;y<Didaskalia.size();y++) {

            q.prepare("SELECT C.CourseID From Courses C,Departments D Where D.DepName=:dp AND C.CourseName=:cn AND C.DepID=D.DepID");

            q.bindValue(":dp",Didaskalia.at(y).getD().getDepName());
            q.bindValue(":cn",Didaskalia.at(y).getName());
            q.exec();
            while (q.next()) {
                Didaskalia[y].setCourseID(q.value(0).toInt());
                qDebug() << " Dep " << Didaskalia.at(y).getD().getDepName() <<  " Course name " << Didaskalia.at(y).getName() << " " << Didaskalia.at(y).getCourseID() << " " << q.value(0).toInt();

            }
        }

        //query the db to get KasseID
        QString wtf="SELECT KasseID FROM Kassen Where Name LIKE  '%"+T.getVersichern().getName() +"%'";
        qDebug() << wtf  ;
        q.exec(wtf);

        while (q.next()) {
            T.getVersichern().setKasseID(q.value(0).toInt());

            T.setKasseID(q.value(0).toInt());
        }



        qDebug() << "KasseID " << T.getKasseID() << " " << QString::number(T.getVersichern().getKasseID()) << " " << T.getVersichern().getName();


        db.transaction();
        //query the db to get the base wages

        q.prepare("INSERT INTO `Members` (`Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`,`ADT`) VALUES (:name,:fname,:mname,:adres,:phone,:mobile,:mail,'5',:regdat,:birthdat,'0','0',:adt)");
        q.bindValue(":name",T.getName());
        q.bindValue(":fname",T.getFName());
        q.bindValue(":mname",T.getMName());
        q.bindValue(":adres",T.getAddress());
        q.bindValue(":phone",T.getPhone());
        q.bindValue(":mobile",T.getMobile());
        q.bindValue(":mail",T.getEmail());
        q.bindValue(":regdat",T.getRegDate());
        q.bindValue(":birthdat",T.getBirthDate());
        q.bindValue(":adt",T.getADT());

        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 10;

        }

        T.setTeacherID(q.lastInsertId().toInt());

        //get the teacher id
        qDebug() << "TeacherID " << T.getTeacherID();

        q.prepare("INSERT INTO `Contract` (`TeacherID`, `End`) VALUES (:tid,:enddat)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":enddat",T.getEndOfContract());

        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 20;

        }



        //15 days off first record is StartDat==EndDat==day of creation
        q.prepare("INSERT INTO `Erlaubnis` (`TeacherID`, `StartDat`, `EndDat`, `DaysLeft`) VALUES (:tid,:sdat,:edat,:left)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":sdat",T.getRegDate());
        q.bindValue(":edat",T.getRegDate());
        q.bindValue(":left",15);




        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 30;

        }



        q.prepare("INSERT INTO `Faces`  (`MembID`, `Pic`) VALUES (:tid,:pic)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":pic",T.getPhoto());

        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 40;

        }



        q.prepare("INSERT INTO `PayKassen` (`TeacherID`, `Dat`, `Wages`) VALUES (:tid,:dat,:kasgeld)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":dat",QDate::currentDate());
        q.bindValue(":kasgeld",T.getPayKasse().getWages());


        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 50;

        }



        qDebug() << "TeacherID  " <<T.getTeacherID() << " echelon " << T.getEch().getEchelID();

        q.prepare("INSERT INTO `TeachEchelon` (`TeacherID`, `EchelonID`) VALUES (:tid,:echid)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":echid",T.getEch().getEchelID());


        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 60;

        }


        q.prepare("INSERT INTO `Versicherung`  (`TeacherID`, `KasseID`,`AFM`) VALUES (:tid,:kassid,:afm)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":kassid",T.getKasseID());
        q.bindValue(":afm",T.getAFM());

        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 70;

        }




        for (Courses C : Didaskalia) {

            //query for that first???

            q.prepare("INSERT INTO `TeachOther` (`TeacherID`, `CourseID`) VALUES (:tid,:cid)");
            q.bindValue(":tid",T.getTeacherID());
            qDebug() << "insert to teachother " << C.getCourseID();
            q.bindValue(":cid",C.getCourseID());

            if (!q.exec())  {
                qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
                throw 75;

            }
        }



        // INSERT INTO `Unavailable`(`UnavailID`, `TeacherID`, `DayID`, `HourID`, `Duration`) VALUES ([value-1],[value-2],[value-3],[value-4],[value-5])


        db.commit();
        ShowSuccess();
    }
    catch (int ex) {
        qDebug () << "Error saving teacher on step " << ex;
        ShowError(q);
        db.rollback();
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
QSqlDatabase ORM::getDb() const
{
    return db;
}

void ORM::setDb(const QSqlDatabase &value)
{
    db = value;
}



void ORM::save(FeeSchule fsh) {
    QSqlQuery q;
    try {
        int CourseID=0;
        q.prepare("SELECT CourseID FROM Courses Where CourseName=:cr");
        q.bindValue(":cr",fsh.getC().getName());
        q.exec();
        while (q.next()) {
            CourseID=q.value(0).toInt();
        }

        if (CourseID<=0) {
            throw 10;
        }

        q.prepare("INSERT INTO `FeeSchule`  (`Dat`, `CourseID`, `Fee`) VALUES (:dat,:courseid,:fee)");
        q.bindValue(":dat",fsh.getDat());
        q.bindValue(":courseid",CourseID);
        q.bindValue(":fee",fsh.getFee());

        q.exec();
        ShowSuccess();
    }
    catch (int ex) {
        ShowError(q);
    }
    q.finish();
}



void ORM::ShowError(QSqlQuery q) {
    QMessageBox msgBox;
    msgBox.setText(q.lastError().text());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Warning);
    int ret = msgBox.exec();
    q.finish();
}



Members ORM::searchStudentByName(QString name) {
    QSqlQuery q;
    Members m;
    q.exec("SELECT Name,ADT FROM Members WHERE Name LIKE '%" + name + "%'");
    while (q.next()) {

        m.setName(q.value(0).toString());
        m.setADT(q.value(1).toString());
    }
    q.finish();
    return m;
}



QList<Rooms> ORM::getRooms() {

    QList<Rooms> domatia;
    QSqlQuery q;
    q.exec("SELECT R.RoomID,B.Address,R.Name,R.Capacity FROM Rooms R,Buildings B WHERE B.BuildID=R.BuildID");
    while (q.next()) {
        Rooms r;
        Buildings bl=Buildings();
        bl.setName(q.value(1).toString());
        r.setB(bl);
        r.setRoomID(q.value(0).toInt());

        r.setCapacity(q.value(3).toInt());
        r.setName(q.value(2).toString());


        domatia.append(r);
    }
    q.finish();
    return domatia;
}

QList<Buildings> ORM::getBuildings() {
    QList<Buildings> Bs;
    QSqlQuery q;
    qDebug() << "Fetching buildings...";




    q.exec("SELECT B.BuildID,B.Address,Count(R.RoomID) FROM Buildings B,Rooms R WHERE B.BuildID=R.BuildID GROUP BY R.BuilDID");
    while (q.next()) {
        Buildings bls=Buildings();
        bls.setBuildingID(q.value(0).toInt());
        bls.setName(q.value(1).toString());
        bls.setRoomsNum(q.value(2).toInt());
        Bs.append(bls);
    }
    return Bs;
}

void ORM::save(Buildings B) {
    QSqlQuery q;

    try {

        q.prepare("INSERT INTO `Buildings` (`Address`) VALUES (:adr)");
        q.bindValue(":adr",B.getName());
        q.exec();
        ShowSuccess();
    }
    catch (int ex) {
        ShowError(q);
    }
    q.finish();

}


void ORM::save(Rooms R) {
    QSqlQuery q;
    try {
        //get buildingind
        int buildID;
        q.prepare("SELECT BuildID FROM Buildings WHERE Address=:add");
        q.bindValue(":add",R.getB().getName());
        q.exec();
        while (q.next()) {
            buildID=q.value(0).toInt();
        }

        if (buildID<=0) {
            throw 0;
        }
        q.prepare("INSERT INTO `Rooms`  (`BuildID`, `Name`, `Capacity`) VALUES (:bid,:name,:cap)");
        q.bindValue(":bid",buildID);
        q.bindValue(":name",R.getName());
        q.bindValue(":cap",R.getCapacity());

        q.exec();
        ShowSuccess();
    }
    catch (int ex) {

        ShowError(q);
    }
    q.finish();
}

void ORM::save(RequestSchule rec) {
    QSqlQuery q;
    try {

        int StudID=0,CourseID=0;
        q.prepare("SELECT CourseID FROM Courses WHERE CourseName=:cnm");
        q.bindValue(":cnm",rec.getC().getName());
        q.exec();
        while (q.next()) {
            CourseID = q.value(0).toInt();
        }




        q.prepare("SELECT MembID FROM Members WHERE Name=:nm");
        q.bindValue(":nm",rec.getStudent().getName());
        q.exec();
        while (q.next()) {
            StudID = q.value(0).toInt();
        }

        qDebug() << "CourseID  " << CourseID << " " << StudID ;

        if ((StudID<=0) || (CourseID<=0)) {
            throw 10;


        }


        q.prepare("INSERT INTO `RequestSchule`  ( `StudentID`, `CourseID`, `Settled`, `ReqDate`, `Comments`) VALUES (:stid,:cid,'0',:dat,:coms)");
        q.bindValue(":stid",StudID);
        q.bindValue(":cid",CourseID);
        q.bindValue(":dat",rec.getDat());
        q.bindValue(":coms",rec.getComments());

        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 10;

        }
        ShowSuccess();
    }
    catch (int ex) {
        ShowError(q);
    }

    q.finish();


}




QList<Courses> ORM::getSchuleCourses() {
    QList<Courses> CL;
    QSqlQuery q;

    q.exec("Select C.CourseName ,S.Red,S.Green,S.Blue From Courses C,Schwierigkeit S Where S.SchwerID=C.Schwer AND C.DepID=1 ");
    while (q.next()) {
        Courses C=Courses();
        qDebug() << "Schule Course " << q.value(0).toString();
        Schwierigkeit S=Schwierigkeit();
        S.setRed(q.value(1).toInt());
        S.setGreen(q.value(2).toInt());
        S.setBlue(q.value(3).toInt());
        C.setS(S);
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
