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

void  ORM::save(Diplomas d) {
    QSqlQuery q;
    try {

        qDebug() << "saving diploma...";
        int lid=0,pid=0;


        q.prepare("SELECT LangID From Languages Where Name=:nm");
        q.bindValue(":nm",d.getLanguage());
        q.exec();

        while (q.next()) {
            lid = q.value(0).toInt();
        }

        qDebug() << "languageID " << lid << " " << d.getLanguage();

        if (lid<=0) {
            throw 10;
        }

        qDebug() << "languageID " << lid << " " << d.getLanguage();

        q.prepare("SELECT InstID FROM Instituts Where Name=:nm");
        q.bindValue(":nm",d.getInstitutName());
        q.exec();

        while (q.next()) {
            pid = q.value(0).toInt();
        }

        qDebug() << "providerIDD " << pid << " " << d.getInstitutName();


        q.prepare("INSERT INTO `Diplomas` (`LangID`, `ProvID`, `Name`, `Schwer`) VALUES (:lid,:pid,:name,:schwid)");
        q.bindValue(":lid",lid);
        q.bindValue(":pid",pid);
        q.bindValue(":name",d.getName());
        q.bindValue(":schwid",d.getSchwerID());

        if (!q.exec()) {
            throw 10;
        }


        ShowSuccess();
    }

    catch (int ex) {
        ShowError(q);

    }
    q.finish();
}



AddInstitutDialogMVC  ORM::getAddInstitutMVC() {
    AddInstitutDialogMVC mvc;
    QSqlQuery q;

    mvc.headers.append("InstitutID");
    mvc.headers.append("name");
    mvc.headers.append("# Diplomas");
    mvc.headers.append("# Teachers");
    mvc.headers.append("# Students");
    mvc.headers.append("# Groups");

    QList<InstitutModel> InsList;


    q.exec("SELECT * FROM Instituts ");
    while (q.next()) {
        InstitutModel mod;

        mod.InstitID=q.value(0).toString();
        mod.InsName=q.value(1).toString();

        mod.NumGroups="0";
        mod.NumStudents="0";
        mod.NumTeachers="0";

        QString diplos="";

        //fetch available diplomas from db;
        QSqlQuery q2;
        QString s= "SELECT Name FROM Diplomas Where ProvID='"+ mod.InstitID+"'";
        qDebug() << s;
        q2.exec(s);
        int c=0;
        while (q2.next()) {
            diplos+= q2.value(0).toString() + " \n";
            q2.value(0).toString();
            c++;
        }
        mod.DiplomaTitles=diplos;
        mod.NumDiplomas=QString::number(c);

        qDebug() << diplos;
        InsList.append(mod);
    }


    mvc.InstitutView=InsList;

    q.finish();
    return mvc;
}



Teacher ORM::searchteacherByname(QString name) {
    Teacher L;
    QSqlQuery q;




    QString s = "SELECT MembID,Name FROM Members WHERE  Name LIKE '%" + name + "%'";
    qDebug() << s;

    q.exec(s);

    int mid;
    while (q.next()) {
        mid=q.value(0).toInt();
        L.setMembID(q.value(0).toInt());
        L.setName(q.value(1).toString());
    }

    qDebug() << mid << " " << L.getName() << " " << L.getMembID();

    q.prepare("SELECT Pic FROM Faces Where MembID=:mid");
    q.bindValue(":mid",mid);
    q.exec();
    while (q.next()) {
        L.setPhoto(q.value(0).toByteArray());
    }

    q.finish();
    return L;
}



QList<Members> ORM::getRequestsSchule(QString CourseName) {
    QList<Members>  Ms;

    qDebug() << "fetching requests for " << CourseName;
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



QList<ManageCourseTable>  ORM::getManageCourseTable() {
    QList<ManageCourseTable> mngTable;

    QSqlQuery q;
    QSqlQuery q2;


    try {



        //gets CourseID,CourseName,DepName Select C.CourseID,C.CourseName, D.DepName,S.Red,S.Green,S.Blue From Courses C,Departments D ,Schwierigkeit S Where D.DepID=C.DepID AND S.SchwerID=C.Schwer ORDER BY C.CourseName



        //gets Count : Select CourseID,Count(TeacherID) FROM TeachOther GROUP BY CourseID

        //takes into account  lessons that are not taught by anyone
        //IT is not taken into account if someone leavers the school
        //



        //gets open requests
        //zero requests!!!



        //repeat for uni requests
        QString s="SELECT ALPHA.CourseID,ALPHA.CourseName,ALPHA.DepName,BRAVO.CNT,ALPHA.Red,ALPHA.Green,ALPHA.Blue FROM ";
        s+= " (Select C.CourseID,C.CourseName, D.DepName ,S.Red,S.Green,S.Blue From Courses C,Departments D,Schwierigkeit S Where D.DepID=C.DepID AND ";
        s+=" S.SchwerID=C.Schwer ORDER BY C.CourseName ) as ALPHA INNER JOIN ( Select CourseID,Count(TeacherID) as CNT FROM TeachOther " ;
        s+=" GROUP BY CourseID UNION Select CourseID,0 AS CNT From Courses WHERE CourseID NOT IN (Select CourseID From TeachOther) ) AS BRAVO ";
        s+="ON ALPHA.CourseID=BRAVO.CourseID  ORDER BY ALPHA.CourseName ASC";

        qDebug() << s;

        if (!q.exec(s)) {
            throw 10;
        }

        while (q.next()) {

            qDebug() << "-----------------------";
            ManageCourseTable c;

            c.CourseID=q.value(0).toInt();
            c.CourseName=q.value(1).toString();
            c.DepName=q.value(2).toString();

            //query the db to get the # groups
            //JOIN WITH THE ABOVE QUERY
            s="SELECT COUNT(GroupID) FROM Groups WHERE CourseID='"+ QString::number(c.CourseID)+"'";

            qDebug() << s;
            q2.exec(s);
            while (q2.next()) {
                c.NumGroups=q2.value(0).toInt();

            }

            //query the db to get the open requests
            //JOIN WITH THE ABOVE QUERY
            s="SELECT COUNT(RequestID) FROM RequestSchule WHERE Settled=0 AND CourseID='"+ QString::number(c.CourseID)+"'";
            qDebug() << s;
            q2.exec(s);

            while (q2.next()) {
                c.NumOpenRequests=q2.value(0).toInt();

            }

            //query to see if there are as many payschemes as active echelons...

            //count the echel ids that do not exist in the wages
            QString s="Select Count(EchelID) From Echelon Where Active=1 AND EchelID NOT IN (SELECT DISTINCT(EchelID) FROM `WagesSchule` WHERE CourseID='"+ QString::number(c.CourseID)+"')";
            qDebug() << s;

            q2.exec(s);
            while (q2.next()) {
                qDebug() << "echel wage count " << q2.value(0).toInt();
                if (q2.value(0).toInt()>0) {
                    c.PaySchemes="NOT SET";
                }
                else {
                    c.PaySchemes="OK";
                }
            }


            //find the latest update of the fee
            s= "SELECT MAX(Dat) FROM `FeeSchule` WHERE CourseID='"+ QString::number(c.CourseID)+"'";

            qDebug() << s;
            q2.exec(s);


            while (q2.next()) {
                c.FeeUpdate=q2.value(0).toString();
                //if empty set to NEVER
                if (c.FeeUpdate.length()==0) {
                    c.FeeUpdate="NEVER";
                }
            }

            c.NumStudents=0;
            c.NumTeachers=q.value(3).toInt();
            Schwierigkeit schw;
            schw.setRed(q.value(4).toInt());
            schw.setGreen(q.value(5).toInt());
            schw.setBlue(q.value(6).toInt());
            c.Schwer=schw;

            mngTable.append(c);


        }




    }
    catch (int ex) {
        ShowError(q);
    }

    q.finish();

    q2.finish();
    return mngTable;
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


QDate ORM::calcEOC(QString tid) {
    //fetch end of contract
    QSqlQuery q;
    q.prepare("SELECT MAX(End) FROM `Contract` WHERE TeacherID=:tid");
    q.bindValue(":tid",tid);
    q.exec();
    QDate telos;
    while (q.next()) {
        telos=q.value(0).toDate();
    }
    q.finish();
    return telos;
}


SchuleTeacherMVC ORM::getCanTeachSchuleMVC(QString CourseName) {

    SchuleTeacherMVC mvc;
    QStringList headers;
    headers.append("ProfID");
    headers.append("Name");
    headers.append("Monthy Salary");
    headers.append("#Groups");
    headers.append("#Hours for this lesson");
    headers.append("#Current Groups");
    headers.append("End of Contract");
    headers.append("Mobile");


    mvc.SchuleTeacherViewHeaders=headers;

    QSqlQuery q,q2;
    QString s="SELECT M.MembID,M.Name,M.Mobile,E.EchelonID From Members M,Courses C,TeachOther T,TeachEchelon E WHERE C.CourseID=T.CourseID AND M.MembID=T.TeacherID AND M.MembID=E.TeacherID AND C.CourseName='"+ CourseName+"'";
    qDebug() << s;
    q.exec(s);

    QList<SchuleTeacher> Lehren;

    while (q.next()) {
        SchuleTeacher daskalos;

        daskalos.ProfID=q.value(0).toString();
        daskalos.Name=q.value(1).toString();

        QString echelid=q.value(3).toString();

        daskalos.Current_Groups="0";
        daskalos.Hours_for_this_lesson="0";
        daskalos.Groups="0";
        daskalos.End_of_Contract=calcEOC(q.value(0).toString()).toString();
        daskalos.Mobile=q.value(2).toString();

        //needs a fix

        q2.prepare("Select Wages From BaseWages Where EchelID=:echelid AND Dat in (Select MAx(Dat) From BaseWages Where EchelID=:echelid)");
        q2.bindValue(":echelid",echelid);
        q2.exec();
        while (q2.next()) {
            daskalos.Monthy_Base_Salary=q2.value(0).toString();
        }



        Lehren.append(daskalos);

        qDebug() << "appended";


    }
    q.finish();

    q2.finish();
    mvc.SchuleTeacherModel=Lehren;

    return mvc;
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
        daskalos.setEndOfContract(daskalos.calcEOC());

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
    msgBox.setIcon( QMessageBox::Critical);

    int ret = msgBox.exec();
    q.finish();
}



Members ORM::searchStudentByName(QString name) {
    QSqlQuery q;
    Members m;

    QString s="SELECT Name,ADT FROM Members WHERE Name LIKE '%" + name + "%'";
    qDebug() << s;

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


FeeSchuleMVC  ORM::getManageFeeSchuleMVC() {

    FeeSchuleMVC mvc;


    QStringList headers;
    headers.append("CourseID");
    headers.append("Name");
    headers.append("Latest update");
    headers.append("Fee");
    headers.append("#Changes");
    headers.append("Debt");
    headers.append("Profit");

    QSqlQuery q;

    QString s;

    /*SQL QUERY EXPLANTION
     -get CID,Name : Select CourseID,CourseName From Courses Where DepID=1 ORDER BY CourseName ASC



      -get changes,latest :

        SELECT CourseID,Count(Dat) As Fores ,MAX(Dat) as Latest FROM `FeeSchule`Group By CourseID



     -these courses don't have a fee yet : Select CourseID,0 as Plithos,0 as Latest FROM Courses Where DepID=1 AND CourseID NOT IN (SELECT CourseID FROM FeeSchule)


    /* UNION Courses have have a fee and courses that dont
    Select CourseID,0 as Plithos,0 as Latest FROM Courses Where DepID=1 AND CourseID NOT IN (SELECT CourseID FROM FeeSchule) UNION

    SELECT CourseID,Count(Dat) As Fores ,MAX(Dat) as Latest FROM `FeeSchule`Group By CourseID

    FINAL QUERY

    */


    s=" Select Alpha.CourseID ,Alpha.CourseName,Charlie.Plithos,Charlie.Latest FROM (Select CourseID,CourseName From Courses Where DepID=1 ORDER BY CourseName ASC) as Alpha INNER JOIN (Select CourseID,0 as Plithos,0 as Latest FROM Courses Where DepID=1 AND CourseID NOT IN (SELECT CourseID FROM FeeSchule) UNION SELECT CourseID,Count(Dat) As Fores ,MAX(Dat) as Latest FROM `FeeSchule`Group By CourseID) AS Charlie WHERE Charlie.CourseID=Alpha.CourseID ";
    qDebug() << s;

    q.exec(s);

    QList<FeeSchuleTable> fee_model;

    while (q.next()) {
        FeeSchuleTable fst;

        fst.CourseID=q.value(0).toString();
        fst.Name=q.value(1).toString();
        fst.Changes=q.value(2).toString();
        fst.LastUpdate=q.value(3).toString();
        fst.Fee="0";
        fst.Debt="0";
        fst.Profit="0";


        fee_model.append(fst);
    }
    mvc.FeeViewHeaders=headers;
    mvc.FeeModel=fee_model;

    q.finish();
    return mvc;
}




QList<Courses> ORM::getSchuleCourses() {
    QList<Courses> CL;
    QSqlQuery q;

    q.exec("Select C.CourseName ,S.Red,S.Green,S.Blue From Courses C,Schwierigkeit S Where S.SchwerID=C.Schwer AND C.DepID=1 ORDER BY C.CourseName  ASC");
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


void ORM::saveSchule(Groups g) {
    QSqlQuery q;

    try {

        qDebug() << "attempting to save schule group";
        int CID=-1;
        //query for courseID
        q.prepare("SELECT CourseID FROM Courses WHERE CourseName=:name AND DepID=1");
        q.bindValue(":name",g.getCourseName());
        q.exec();
        while (q.next()) {
            CID=q.value(0).toInt();
        }

        if (CID<=0) {
            throw 10;
        }


        q.prepare("INSERT INTO `Groups`  (`TeacherID`, `CourseID`, `StartDate`) VALUES (:tid,:cid,:sdat)");
        q.bindValue(":tid",g.getTeacherID());
        q.bindValue(":cid",CID);
        q.bindValue(":sdat",g.getStartDate());

        if (!q.exec()) {
            throw 10;
        }

        int GroupID;
        q.exec("SELECT MAX(GroupID) FROM Groups");
        while (q.next()) {
            GroupID=q.value(0).toInt();
        }


        if (GroupID<=0) {
            throw 10;
        }

        for (QString SID : g.getMeliID()) {
            q.prepare("INSERT INTO `Ensembles` ( `GroupID`, `StudID`) VALUES (:gid,:sid)");
            q.bindValue(":gid",GroupID);
            q.bindValue(":sid",SID);

            if (!q.exec()) {
                throw 10;
            }
            //set Request Setted= 1

            qDebug() << "deleting request for " << SID;
            QString s="UPDATE `RequestSchule` SET `Settled`=1  WHERE CourseID='"+ QString::number(CID)+"' AND StudentID='"+ SID+"' ";
            qDebug() << s;
            q.exec(s);


            if (!q.exec()) {
                throw 10;
            }
        }


        ShowSuccess();
    }
    catch (int ex) {
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


void ORM::saveSchuleStudent(Members m) {
    QSqlQuery q;
    try {

        q.prepare("INSERT INTO `Members` ( `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`,`ADT`) VALUES (:name,:fname,:mname,:adres,:phone,:mobile,:email,'2',:rdate,:bdate,'0','0',:adt)");






        qDebug() << "name " << m.getName();
        q.bindValue(":name",m.getName());

        q.bindValue(":fname",m.getFName());
        q.bindValue(":mname",m.getMName());
        q.bindValue(":adres",m.getAddress());
        q.bindValue(":phone",generatePhone());
        q.bindValue(":mobile",generateMobile());
        q.bindValue(":email",m.getEmail());
        q.bindValue(":rdate",m.getRegDate());
        q.bindValue(":bdate",m.getBirthDate());
        q.bindValue(":adt",generateADT());
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

        q.prepare("INSERT INTO `Members` ( `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`,`ADT`) VALUES (:name,:fname,:mname,:adres,:phone,:mobile,:email,'1',:rdate,:bdate,'0','0',:adt)");






        qDebug() << "name " << m.getName();
        q.bindValue(":name",m.getName());

        q.bindValue(":fname",m.getFName());
        q.bindValue(":mname",m.getMName());
        q.bindValue(":adres",m.getAddress());
        q.bindValue(":phone",generatePhone());
        q.bindValue(":mobile",generateMobile());
        q.bindValue(":email",m.getEmail());
        q.bindValue(":rdate",m.getRegDate());
        q.bindValue(":bdate",m.getBirthDate());
        q.bindValue(":adt",generateADT());
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
    q.exec("Select Exp From Echelon Where Active=1");
    while (q.next()) {
        Echelon c=Echelon();
        c.setExpYears(q.value(0).toInt());
        Ech.append(c);
    }
    q.finish();
    return Ech;
}
