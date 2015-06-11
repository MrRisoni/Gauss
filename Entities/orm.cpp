#include "orm.h"
#include <exception>
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

using namespace std;

extern QSqlDatabase vasi;


ORM::ORM()
{


}

ORM::~ORM()
{

}

TimeTableHeaders ORM::getTimeTableHeaders() {

    TimeTableHeaders headers;
    QSqlQuery q;
    q.exec("SELECT DayName From Days");
    while (q.next()) {
        headers.horHeaders.append(q.value(0).toString());
    }

    QStringList tmp; //show the hours like 0900-0930 it is human friendly
    q.exec("SELECT HourN From Hours");
    while (q.next()) {
        tmp.append(q.value(0).toString());
    }
    for (int i=0 ; i <tmp.size()-1;i++) {
        headers.verHeaders.append(tmp.at(i)+ "-" + tmp.at(i+1));
    }

    q.finish();
    return headers;
}


KassenMVC ORM::getKassenMVC() {


    KassenMVC mvc;

    QSqlQuery q,q2;


    try {
        mvc.headers.append("ID");
        mvc.headers.append("Name");
        mvc.headers.append("#Teachers");
        mvc.headers.append("Pays");
        mvc.headers.append("Debt");


        //create temporary tables
        // GET HOW MUCH MONEY HAVE WE PAYED FOR EACH Kas
        QString s="CREATE TEMPORARY TABLE SicherGeld ";

        s+=" Select V.KasseID,SUM(P.Amount) As Kost FROM Payments P,Versicherung V Where V.TeacherID=P.TeacherID Group BY V.KasseID";


        qDebug() << s;


        if (!q.exec(s)){
            throw 10;
        }



        qDebug() << "-------------------";

        s="CREATE TEMPORARY TABLE KassenCount ";
        s+=" SELECT Alpha.KasseID , Tango.Name,Alpha.Plithos FROM (SELECT KasseID,Count(KasseID) AS Plithos FROM ";
        s+=" Versicherung Group By KasseID) As Alpha INNER JOIN (SELECT K.KasseID,K.Name From Kassen K) AS ";
        s+=" Tango ON Alpha.KasseID=Tango.KasseID ";


        qDebug() << s;
        if (!q.exec(s)){
            throw 10;
        }

        //join now
        s="SELECT S.KasseID,K.Name,K.Plithos,S.Kost FROM  SicherGeld S,KassenCount K  WHERE S.KasseID=K.KasseID";
        qDebug() << s;
        if (!q.exec(s)){
            throw 10;
        }


        while (q.next()) {
            KasseModel k=KasseModel();

            k.ID=q.value(0).toString();
            k.Name=q.value(1).toString();
            k.NumTeachers=q.value(2).toString();
            k.Pays=q.value(3).toString();
            k.Debt="0";

            mvc.KasseView.append(k);

        }
    }

    catch (int ex) {
        ShowError(q);
    }
    q.finish();
    return mvc;
}


void ORM::save(Payments p) {
    QSqlQuery q;

    try {
        vasi.transaction();

        qDebug() << "trying to save payment";
        int ptype=0,tid=0;
        q.prepare("SELECT MembID FROM Members Where Name=:nm");
        q.bindValue(":nm",p.getTeacherName());
        q.exec();
        while (q.next()) {
            tid=q.value(0).toInt();
        }

        //get pay type id
        qDebug() << p.getTeacherName() << " " << tid;

        q.prepare("SELECT PayTypeID FROM PayType Where Comment=:com");
        q.bindValue(":com",p.getPayType());
        q.exec();
        while (q.next()) {
            ptype=q.value(0).toInt();
        }

        qDebug() << p.getPayType() << " " << ptype;
        if ((tid<=0) || (ptype<=0)) {
            throw 10;
        }

        q.prepare("INSERT INTO `Payments`  (`TeacherID`, `Dat`, `Amount`,  `PayTypeID`) VALUES (:tid,:dat,:euro,:ptid)");
        q.bindValue(":tid",tid);
        q.bindValue(":dat",p.getDat());
        q.bindValue(":euro",p.getMoney());
        q.bindValue(":ptid",ptype);

        if (!q.exec()) {
            throw 10;
        }




        vasi.commit();

        ShowSuccess();
    }
    catch (int ex) {
        vasi.rollback();

        ShowError(q);
    }

    q.finish();
}

void  ORM::save(Diplomas d) {
    QSqlQuery q;
    try {

        vasi.transaction();

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


        vasi.commit();

        ShowSuccess();
    }

    catch (int ex) {

        vasi.rollback();

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




    QString s = "SELECT MembID,Name,Address,Phone,Mobile,Email,RegDate,BirthDate,ADT FROM Members WHERE  Name LIKE '%" + name + "%'";
    qDebug() << s;

    q.exec(s);

    int mid;
    while (q.next()) {
        mid=q.value(0).toInt();
        L.setMembID(q.value(0).toInt());
        L.setName(q.value(1).toString());
        L.setAddress(q.value(2).toString());
        L.setPhone(q.value(3).toString());
        L.setMobile(q.value(4).toString());
        L.setEmail(q.value(5).toString());
        L.setRegDate(q.value(6).toDate());
        L.setBirthDate(q.value(7).toDate());
        L.setADT(q.value(8).toString());
    }

    qDebug() << mid << " " << L.getName() << " " << L.getMembID();

    QString FilePath = getSetFacesPath();

    qDebug() << "loading image " << FilePath + QString::number(mid) + ".jpg";
    QPixmap p;

    p.load(FilePath + QString::number(mid) + ".jpg");
    L.setPixie(p);


    //get signature

    //check first if the signature exists
    QFile Fout("/tmp/sign" + QString::number(mid) + ".png");


    if(!Fout.exists())
    {
        L.setSignaturePixie(getSignaturePic(QString::number(mid)));
    }
    else {
        QPixmap p;
        p.load("/tmp/sign" + QString::number(mid) + ".png");
        qDebug() << "signature already exists";
        L.setSignaturePixie(p);

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





QString ORM::generateAMKA() {

    QSqlQuery q;

    QList<QString> ExistingAMKAs;
    q.exec("SELECT AMKA FROM Versicherung");
    while (q.next()) {
        ExistingAMKAs.append(q.value(0).toString());
    }

    bool exists= true;




    QString randomString;


    while (exists==true) {

        randomString="";


        int High=9;
        int Low=0;
        for (int i=0;i<12;i++) {
            randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
        }

        //if random string exists in the db regenerate


        exists=ExistingAMKAs.contains(randomString);


    }

    q.finish();
    return randomString;
}


QString ORM::generateADT() {
    //get all the ADTs from the db
    //adt must be uniquq
    QSqlQuery q;

    QList<QString> ExistingADTS;
    q.exec("SELECT ADT FROM Members UNION SELECT ADT FROM Users ORDER BY `ADT` ASC ");
    while (q.next()) {
        ExistingADTS.append(q.value(0).toString());
    }

    bool exists= true;


    //generates a 8 digit ADT
    QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");


    QString randomString;

    srand ( time(NULL) );

    while (exists==true) {

        randomString="";
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

        //if random string exists in the db regenerate

        qDebug() << "new ADT" << randomString;
        exists=ExistingADTS.contains(randomString);


    }

    q.finish();
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


    QSqlQuery q;
    QList<QString> ExistingAFMs;
    q.exec("SELECT AFM FROM Versicherung");
    while (q.next()) {
        ExistingAFMs.append(q.value(0).toString());
    }

    bool exists= true;
    QString randomString;

    while (exists==true) {

        randomString="";

        int High=9;
        int Low=0;
        for (int i=0;i<7;i++) {
            randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
        }

        exists=ExistingAFMs.contains(randomString);

    }
    q.finish();

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
    QList<QString> ExistingPhones;
    QSqlQuery q;

    // i want the app to be realistic
    //generate a unique mobile
    //however allow for a few collisions


    int Tries =0;
    q.exec("SELECT Phone FROM Members");
    while (q.next()) {
        ExistingPhones.append(q.value(0).toString());
    }

    QString randomString;
    int High=9;
    int Low=0;

    srand ( time(NULL) );

    do {

        randomString="210";
        for (int i=0;i<7;i++) {
            randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
        }
        qDebug() << "new phone " << randomString;


    } while (ExistingPhones.contains(randomString)==false && (Tries>300));
    return randomString;
}

QString ORM::generateMobile() {

    QList<QString> ExistingMobiles;
    QSqlQuery q;

    // i want the app to be realistic
    //generate a unique mobile
    //however allow for a few collisions

    int Tries =0;

    q.exec("SELECT FatherMobile FROM Schuler UNION SELECT MotherMobile FROM Schuler UNION SELECT Mobile FROM Members");
    while (q.next()) {
        ExistingMobiles.append(q.value(0).toString());
    }
    q.finish();

    int High=9;
    int Low=0;

    srand ( time(NULL) );


    QString randomString;

    do {
        randomString="69";
        for (int i=0;i<8;i++) {
            randomString.append(QString::number(qrand() % ((High + 1) - Low) + Low));
        }
        Tries++;

        qDebug() << "new mobile " << randomString;
    } while (ExistingMobiles.contains(randomString)==false && (Tries>300));
    return randomString;
}


QPixmap ORM::getSignaturePic(QString TeacherID) {

    std::string filename = "python2  /home/linguine/Gauss/E_Receipts/py_scripts/RetrieveAndShow.py " + TeacherID.toStdString();

    system(filename.c_str());

    QPixmap p;
    p.load("/tmp/sign" + TeacherID + ".png");
    return p;

}



QString ORM::getSetFacesPath() {
    //save to Faces Folder
    //open settings file http://stackoverflow.com/questions/15893040/how-to-create-read-write-json-files-in-qt5

    QString val;
    QFile file;
    file.setFileName(":sets/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument dok = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject setFilePath = dok.object();
    QString FilePath = setFilePath.value(QString("Faces")).toString() + "/";

    qDebug() << "faces path " << FilePath;

    return FilePath;
}


void ORM::saveTeacher(Teacher T) {
    QSqlQuery q;
    try {

        vasi.transaction();


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


        //query the db to get the base wages

        q.prepare("INSERT INTO `Members` (`Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `ADT`) VALUES (:name,:fname,:mname,:adres,:phone,:mobile,:mail,'5',:regdat,:birthdat,:adt)");
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




        q.prepare("INSERT INTO `PayKassen` (`TeacherID`, `Dat`, `Wages`) VALUES (:tid,:dat,:kasgeld)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":dat",QDate::currentDate());
        q.bindValue(":kasgeld",T.getPayKasse().getWages());


        if (!q.exec())  {
            qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
            throw 50;

        }



        qDebug() << "TeacherID  " <<T.getTeacherID() << " echelon " << T.getEch().getEchelID();

        q.prepare("INSERT INTO `TeachEchelon` (`TeacherID`, `EchelonID`,`Dat`) VALUES (:tid,:echid,:dat)");
        q.bindValue(":tid",T.getTeacherID());
        q.bindValue(":echid",T.getEch().getEchelID());
        q.bindValue(":dat",QDate::currentDate());


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


        vasi.commit();

        ShowSuccess();
    }
    catch (int ex) {
        vasi.rollback();

        qDebug () << "Error saving teacher on step " << ex;
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
    q.exec("Select E.Exp,W.Dat,C.CourseName,W.Wage From Echelon E,WagesSchule W,Courses C WHERE E.EchelID=W.EchelID AND C.CourseID=W.CourseID ORDER BY C.CourseName ASC");

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

void ORM::save(Funds f) {
    QSqlQuery q;
    try {

        int sid=0;

        q.prepare("SELECT MembID FROM Members WHERE ADT=:ausweis");
        q.bindValue(":ausweis",f.getADT());
        q.exec();

        while (q.next()) {
            sid=q.value(0).toInt();
        }

        if (sid<=0) {
            throw 10;
        }
        QString s="INSERT INTO `Funds`  (`StudentID`, `GroupID`, `Dat`, `Amount`) VALUES (:sid,:gid,:dat,:euro)";
        qDebug() << s;
        q.prepare(s);
        q.bindValue(":sid",sid);
        q.bindValue(":gid",f.getGroupID());
        q.bindValue(":dat",QDate::currentDate());
        q.bindValue(":euro",f.getAmount());

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

void ORM::save(FeeSchule fsh) {
    QSqlQuery q;
    try {

        vasi.transaction();

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

        if (!q.exec())    {
            throw 10;

        }
        //for every valid history record from today and on update fee
        q.prepare("UPDATE History SET fee =:new_fee Where GroupID IN (SELECT GroupID FROM Groups Where CourseID=:cid) AND Dat>=CURRENT_DATE() AND Valid=1");
        q.bindValue(":new_fee",fsh.getFee());
        q.bindValue(":cid",CourseID);

        if (!q.exec())    {
            throw 10;

        }

        vasi.commit();
        ShowSuccess();
    }
    catch (int ex) {
        vasi.rollback();
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



Student ORM::searchStudentByADT(QString adt) {
    QSqlQuery q;
    Student st;

    QString s="SELECT M.Name, M.ADT,M.MembID FROM Members M  WHERE  M.ADT LIKE '%" + adt + "%'";
    qDebug() << s;

    QString membid;
    q.exec(s);
    while (q.next()) {

        st.setName(q.value(0).toString());
        st.setADT(q.value(1).toString());
        membid = q.value(2).toString();
    }
    q.finish();

    //get active courses
    q.prepare("select GroupID FROM Ensembles Where StudID=:sid");
    q.bindValue(":sid",membid);
    q.exec();
    QList<QString> groups;
    while (q.next()){
       groups.append(q.value(0).toString());
    }

    st.setGroupIDs(groups);


    return st;
}



QList<Rooms> ORM::getRooms() {

    QList<Rooms> domatia;
    QSqlQuery q;
    q.exec("SELECT R.RoomID,B.Address,R.Name,R.Capacity FROM Rooms R,Buildings B WHERE B.BuildID=R.BuildID ORDER BY B.Address ASC , R.Name ASC");
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


    QString s="SELECT B.BuildID,B.Address,Count(R.RoomID) As Plithos FROM Buildings B,Rooms R ";
    s+=" WHERE B.BuildID=R.BuildID GROUP BY R.BuilDID UNION SELECT BuildID,Address,0 As Plithos ";
    s+=" FROM Buildings B WHERE BuildID NOT IN (SELECT BuildID FROM Rooms) ORDER BY Address ASC";

    q.exec(s);
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
        q.prepare("SELECT BuildID FROM Buildings WHERE Address=:add  ");
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




        q.prepare("SELECT MembID FROM Members WHERE ADT=:nm");
        q.bindValue(":nm",rec.getStudent().getADT());
        q.exec();
        while (q.next()) {
            StudID = q.value(0).toInt();
        }

        qDebug() << "CourseID  " << CourseID << " " << StudID ;

        if ((StudID<=0) || (CourseID<=0)) {
            throw 10;


        }


        int exists =0;
        q.prepare("Select Count(CourseID) From RequestSchule Where CourseID=:cid AND StudentID=:stid");
        q.bindValue(":stid",StudID);
        q.bindValue(":cid",CourseID);
        q.exec();
        while (q.next()) {
            exists=q.value(0).toInt();
            qDebug() << "existsing records" << exists;
        }
        if (exists==0) {
            //dont insert if record exists....
            q.prepare("INSERT INTO `RequestSchule`  ( `StudentID`, `CourseID`, `Settled`, `ReqDate`, `Comments`) VALUES (:stid,:cid,'0',:dat,:coms)");
            q.bindValue(":stid",StudID);
            q.bindValue(":cid",CourseID);
            q.bindValue(":dat",rec.getDat());
            q.bindValue(":coms",rec.getComments());

            if (!q.exec())  {
                qDebug() << "error.." << q.lastError().driverText() << " " << q.lastError().databaseText();
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



QComboBox* getComboUniCourses(QString DepName) {
    QSqlQuery q;

    QComboBox *box=new QComboBox();
    q.exec("Select C.CourseName ,S.Red,S.Green,S.Blue From Courses C,Schwierigkeit S Where S.SchwerID=C.Schwer AND C.DepID IN (SELECT DepID FROM Departments Where DepName='"+ DepName+"') ORDER BY C.CourseName  ASC");
    int row=0;
    while (q.next()) {
        qDebug() << "Uni Course " << q.value(0).toString() << " @ " << DepName;

        QColor col;

        col.setRed(q.value(1).toInt());
        col.setGreen(q.value(2).toInt());
        col.setBlue(q.value(3).toInt());
        box->addItem(q.value(0).toString());

        box->setItemData(row,col,Qt::ForegroundRole);
        row++;



    }
    q.finish();

    return box;
}

QList<Courses> ORM::getUniCourses(QString DepName) {
    QList<Courses> CL;
    QSqlQuery q;

    q.exec("Select C.CourseName ,S.Red,S.Green,S.Blue From Courses C,Schwierigkeit S Where S.SchwerID=C.Schwer AND C.DepID IN (SELECT DepID FROM Departments Where DepName='"+ DepName+"') ORDER BY C.CourseName  ASC");
    while (q.next()) {
        Courses C=Courses();
        qDebug() << "Uni Course " << q.value(0).toString() << " @ " << DepName;
        Schwierigkeit S=Schwierigkeit();
        S.setRed(q.value(1).toInt());
        S.setGreen(q.value(2).toInt());
        S.setBlue(q.value(3).toInt());
        C.setS(S);
        C.setName(q.value(0).toString());
        CL.append(C);
    }
    q.finish();
    qDebug() << "Uni Courses " << CL.size();
    return CL;
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

        qDebug() << "departments " << q.value(1).toString();
        D.append(dep);
    }

    q.finish();
    return D;
}


QList<PayType> ORM::getPayTypes() {
    QList<PayType> Ps;
    QSqlQuery q;
    q.exec("SELECT * FROM PayType");
    while (q.next()) {
        PayType p = PayType();
        qDebug () << "pay type " << q.value(1).toString();
        p.setComment(q.value(1).toString());

        Ps.append(p);
    }

    q.finish();
    return Ps;
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



void ORM::saveSchule(Groups g,Permament Perma,QList<Permatimes> Programma) {
    QSqlQuery q;

    try {

        vasi.transaction();
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


        q.prepare("INSERT INTO `Groups`  (`TeacherID`, `CourseID`, `StartDate`,`LessTypeID`) VALUES (:tid,:cid,:sdat,'1')");
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
            //insert into should be payed
            q.prepare("INSERT INTO `ShouldBePayed`  (`StudentID`, `Amount`, `GroupID`, `Updated`) VALUES (:sid,'0',:gid,:dat)");
            q.bindValue(":sid",SID);
            q.bindValue(":gid",GroupID);
            q.bindValue(":dat",QDate::currentDate());

            if (!q.exec()) {
                throw 10;
            }








            q.prepare("INSERT INTO `Ensembles` ( `GroupID`, `StudID`,`Added`) VALUES (:gid,:sid,:dat)");
            q.bindValue(":gid",GroupID);
            q.bindValue(":sid",SID);
            q.bindValue(":dat",QDate::currentDate());

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


        //ADD USEFUL COMMENTS!!!!!!!!!!!!!1
        QString s;


        //insert into permament
        int PermaID=0;
        s= "INSERT INTO `Permament` (`GroupID`, `StartsOn`, `EndsOn`) VALUES (:grid,:start,:end)";
        qDebug () << s;
        q.prepare(s);
        q.bindValue(":grid",GroupID);
        q.bindValue(":start",Perma.getStarts());
        q.bindValue(":end",Perma.getEnds());


        if (!q.exec()) {
            throw 10;
        }
        qDebug() << s;



        q.exec("SELECT MAX(PermaID) FROM Permament");
        while (q.next()) {
            PermaID=q.value(0).toInt();
        }

        if (PermaID<=0) {
            throw 10;
        }

        qDebug() << "maximum permament ID " << PermaID;

        qDebug() << "Querying for room names " ;

        //insert to perma times
        for (int z=0;z<Programma.size();z++) {




            // query to the the room
            QSqlQuery q2;
            int roomid=-1;
            q2.exec("SELECT RoomID FROM Rooms WHERE Name = '"+ Programma.at(z).getRoom()+"'");
            while (q2.next()) {
                roomid= q2.value(0).toInt();
            }

            Programma[z].setRoomID(roomid);


            qDebug() << "Room Name " << Programma.at(z).getRoom() << " RoomID " << roomid << " " << Programma[z].getRoomID();


            if (roomid<=0) {
                throw 10;
            }

            s = "INSERT INTO `PermaTimes` (`PermaID`, `DayID`, `StartHourID`, `Duration`,`RoomID`) VALUES (:perid,:did,:shid,:dur,:rid)";
            q.prepare(s);
            q.bindValue(":perid",PermaID);
            q.bindValue(":did",Programma.at(z).getDayID());
            q.bindValue(":shid",Programma.at(z).getStartHourID());
            q.bindValue(":dur",Programma.at(z).getDiarkeia());
            q.bindValue(":rid",Programma.at(z).getRoomID());

            qDebug () << s;

            if (!q.exec()) {
                throw 10;
            }


            qDebug() << "inserted record to perma times";
        }




        Zukunuft FutureDatesRoomsHours = createFutureDatesAndRooms(Programma,Perma.getStarts(),Perma.getEnds());

        qDebug() << "generated days " << FutureDatesRoomsHours.FutureJulianDays.size() ;
        qDebug() << "generated start hours " << FutureDatesRoomsHours.FutureHourIDs.size() ;
        qDebug() << "generated durations " << FutureDatesRoomsHours.Durations.size() ;
        qDebug() << "generated rooms " << FutureDatesRoomsHours.FutureRoomIDs.size() ;


        //fetch the MOST RECENT base fee of the professor
        float most_recent_bw=0;

        s= "SELECT Wages FROM BaseWages WHERE EchelID IN (select EchelonID FROM TeachEchelon ";
        s+= " Where TeacherID=:tid AND Dat IN (SELECT MAX(Dat) FROM TeachEchelon ";
        s+= " WHERE TeacherID=:tid) ) ORDER BY Dat Desc Limit 1 ";

        qDebug() << s;
        q.prepare(s);
        q.bindValue(":tid",g.getTeacherID());


        if (!q.exec()) {
            throw 10;
        }

        while (q.next()) {
            most_recent_bw=q.value(0).toFloat();
        }


        qDebug() << " most recent bw " << most_recent_bw;
        //get the most recent fee and wage for that course

        float most_recent_fee;
        float most_recent_cw;

        q.prepare("SELECT Fee FROM FeeSchule Where CourseID=:cid order by Dat Desc LIMIT 1");
        q.bindValue(":cid",CID);
        if (!q.exec()) {
            throw 10;
        }

        while (q.next()) {
            most_recent_fee=q.value(0).toFloat();
        }

        qDebug() << " most recent fee " << most_recent_fee;




        s=" SELECT Wage FROM WagesSchule WHERE EchelID IN (select EchelonID FROM TeachEchelon ";
        s+= " Where TeacherID=:tid AND Dat IN (SELECT MAX(Dat) FROM TeachEchelon ";
        s+= " WHERE TeacherID=:tid) ) ORDER BY Dat Desc Limit 1";

        qDebug() << s;
        q.prepare(s);
        q.bindValue(":tid",g.getTeacherID());


        if (!q.exec()) {
            throw 10;
        }

        while (q.next()) {
            most_recent_cw=q.value(0).toFloat();
        }


        qDebug() << " most recent cw " << most_recent_cw;



        int StundeID=1;
        for (int w=0;w<FutureDatesRoomsHours.FutureJulianDays.size();w++ ) {
            qDebug() << "---------------------------";
            s="INSERT INTO `History`  (`GroupID`, `Dat`, `StartHourID`, `Duration`, `RoomID`,`bw`,`cw`,`fee`) VALUES (:grid, :dat , :shourid , :dur , :rid,:bw,:cw,:fee)";
            qDebug() << s;

            q.prepare(s);
            q.bindValue(":grid",GroupID);
            q.bindValue(":dat",QDate::fromJulianDay(FutureDatesRoomsHours.FutureJulianDays.at(w)));
            q.bindValue(":shourid",FutureDatesRoomsHours.FutureHourIDs.at(w));
            q.bindValue(":dur",FutureDatesRoomsHours.Durations.at(w));
            q.bindValue(":rid",FutureDatesRoomsHours.FutureRoomIDs.at(w));
            q.bindValue(":bw",most_recent_bw);
            q.bindValue(":cw",most_recent_cw);
            q.bindValue(":fee",most_recent_fee);

            //copy to history until the end
            q.exec();
            qDebug() << "groupid " << GroupID ;
            qDebug() << "mera " << QDate::fromJulianDay(FutureDatesRoomsHours.FutureJulianDays.at(w));
            qDebug() << "ora " << FutureDatesRoomsHours.FutureHourIDs.at(w);
            qDebug() << "domatio " << FutureDatesRoomsHours.FutureRoomIDs.at(w);
            qDebug() << "diarkeia " << FutureDatesRoomsHours.Durations.at(w);
            qDebug() << "stundeID " << StundeID;
            StundeID++;
        }

        vasi.commit();


        ShowSuccess();
    }
    catch (int ex) {

        vasi.rollback();
        ShowError(q);

    }

    q.finish();

}

Zukunuft ORM::createFutureDatesAndRooms(QList<Permatimes> Settings,QDate startDate,QDate endDate) {



    //qDebug() << "************** COPY TO HISTORY TEST **************";
    //creates a list of dates , whoose id is DayID, starting from today until endDate
    std::vector<long> V;
    std::vector<int> Domatia;
    std::vector<int> Ores;
    std::vector<float> Diarkeia;



    Zukunuft Mellon;

    //dont return QDates boost does not know how to output QDate and
    // i don't know how to tell Boost how to print one

    QStringList StringDays;
    QSqlQuery q;
    q.exec("SELECT DayName From Days");
    while (q.next()) {
        StringDays.append(q.value(0).toString());
    }


    //this test is supposed to start at Sunday 31/05/15
    int TodayID = StringDays.indexOf(QDate::longDayName(QDate::currentDate().dayOfWeek()));


    //qDebug() << TodayID;

    //DayID ==1 is sunday
    int duration = endDate.toJulianDay() - startDate.toJulianDay();

    long StartJul =startDate.toJulianDay(); // the start day in julian day

    for (long i=TodayID;i<duration;i++) {
        //all days must be equal to DayIDs

        int nextday = i % 7 ; //seven are the days of the week
        //in 15 days from now there will be again the same TodayID because the modulo will be zero

        //check if next day exists in the list Settings

        for (Permatimes p : Settings) {
            if (p.getDayID()==nextday) {
                //create a day from startJul
                V.push_back(QDate::fromJulianDay(StartJul).toJulianDay());
                // qDebug() << "out " << QDate::fromJulianDay(StartJul);
                Ores.push_back(p.getStartHourID());




                Domatia.push_back(p.getRoomID());




                Diarkeia.push_back(p.getDiarkeia());
            }
        }

        StartJul++;
    }


    Mellon.FutureHourIDs=Ores;
    Mellon.FutureJulianDays=V;
    Mellon.FutureRoomIDs=Domatia;
    Mellon.Durations=Diarkeia;
    return Mellon;



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



void ORM::saveSchuleStudent(Members m,QString kateuthinsi,QString specialcat) {
    QSqlQuery q;
    try {

        vasi.transaction();
        q.prepare("INSERT INTO `Members` ( `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `ADT`) VALUES (:name,:fname,:mname,:adres,:phone,:mobile,:email,'2',:rdate,:bdate,:adt)");






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



        if (!q.exec()) {
            throw 10;
        }



        vasi.commit();

        int DiscID=0;

        q.exec("SELECT DiscID FROM Disciplines WHERE NAME ='"+ kateuthinsi +"'");
        while (q.next()) {
            DiscID = q.value(0).toInt();
        }


        qDebug() << "disciplineid " << DiscID;

        if (DiscID<=0) {
            throw 10;
        }


        //
        int StudID=0;
        q.exec("SELECT MAX(MembID) FROM Members");
        while (q.next()) {
            StudID=q.value(0).toInt();
        }

        qDebug() << "max memberid MemberID " << StudID;

        if (StudID<=0) {
            throw 10;
        }


        vasi.transaction();


        q.prepare("INSERT INTO `Schuler` ( `StudentID`, `DiscipleID`, `FatherMobile`, `MotherMobile`) VALUES (:sid,:did,:dad,:mom)");
        q.bindValue(":sid",StudID);
        q.bindValue(":did",DiscID);
        q.bindValue(":dad",generateMobile());
        q.bindValue(":mom",generateMobile());

        if (!q.exec()) {
            throw 10;
        }

        qDebug() << "insert into schuler";
        //special category


        int spcatid=0;

        q.exec("SELECT SpecialID FROM DiscountCats Where Description='"+ specialcat+"'");
        while (q.next()) {
            spcatid=q.value(0).toInt();
        }

        qDebug() << "special category " << spcatid;

        if (spcatid<=0) {
            throw 10;
        }

        if (spcatid>1) {

            q.prepare("INSERT INTO `SpecialFees` ( `StudentID`, `CatID`, `Created`, `Expires`) VALUES (:sid,:catid,:start,:exp)");
            q.bindValue(":sid",StudID);
            q.bindValue(":catid",spcatid);
            q.bindValue(":start",QDate::currentDate());
            q.bindValue(":exp",QDate::currentDate().addDays(365));


            if (!q.exec()) {
                throw 10;
            }

        }
        vasi.commit();

        qDebug() << "commit student";
        //ShowSuccess();

    }
    catch (int ex) {

        vasi.rollback();

        qDebug() << "Error " ;

        ShowError(q);
    }


    q.finish();


}



void ORM::saveStudent(Members m) {
    QSqlQuery q;
    try {

        vasi.transaction();
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

        vasi.commit();
        ShowSuccess();

    }
    catch (exception& ex) {

        vasi.rollback();

        qDebug() << "Error " << ex.what() ;

        ShowError(q);
    }


    q.finish();


}

void ORM::save(Schwierigkeit schw) {
    QSqlQuery q;


    try {

        vasi.transaction();

        qDebug() << "saving object schw";
        QString s="INSERT INTO `Schwierigkeit`  ( `Red`, `Green`, `Blue`) VALUES (:r,:g,:b)";
        q.prepare(s);
        q.bindValue(":r",schw.getRed());
        q.bindValue(":g",schw.getGreen());
        q.bindValue(":b",schw.getBlue());

        q.exec();



        vasi.commit();



    }
    catch (exception& ex) {


        vasi.rollback();
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


QList<Discipline> ORM::getDisciplines() {
    QSqlQuery q;
    QList<Discipline> Discs;
    q.exec("SELECT * FROM Disciplines");
    while (q.next()) {
        Discipline D=Discipline();
        D.setDiscID(q.value(0).toInt());
        D.setName(q.value(1).toString());
        Discs.append(D);
    }

    q.finish();
    return Discs;
}



QList<DiscountType> ORM::getDiscountTypes() {
    QSqlQuery q;
    QList<DiscountType> D;

    q.exec("SELECT * FROM DiscountCats");
    while (q.next()) {
        DiscountType dt= DiscountType();
        dt.setDescription(q.value(1).toString());
        D.append(dt);
    }

    q.finish();
    return D;
}




void ORM::CancelLesson(QString GroupID,QList<QString> dats) {
    QSqlQuery q;
    for (QString dat : dats) {
        QString s="UPDATE History SET  Valid=0  WHERE   GroupID='"+ GroupID +"' AND Dat='"+ dat +"'";
        qDebug() << s;
        q.exec(s);
    }



    q.finish();
}



void ORM::AddTempLesson(QString GroupID,QDate dat,QString hour,float duration) {
    /* ignore overlaps
     * pick a room at random
     */
    QSqlQuery q;
    try {
        vasi.transaction();
        int hourid=0;

        q.prepare("SELECT HourID FROM Hours Where HourN=:hn");
        q.bindValue(":hn",hour);
        q.exec();
        while (q.next()) {
            hourid=q.value(0).toInt();
        }
        if (hourid<=0) {
            throw 10;
        }

        int numRooms=0;
        q.exec("SELECT COUNT(RoomID) FROM Rooms");
        while (q.next()) {
            numRooms=q.value(0).toInt();
        }

        if (numRooms<=0) {
            throw 10;
        }
        srand ( time(NULL) );
        int randRoom =  qrand() % numRooms+1;
        q.prepare("INSERT INTO `History`  (`GroupID`, `Dat`, `StartHourID`, `Duration`, `RoomID`) VALUES (:gid,:dt,:sid,:dur,:rid)");
        q.bindValue(":gid",GroupID);
        q.bindValue(":dt",dat);
        q.bindValue(":sid",hourid);
        q.bindValue(":dur",duration);
        q.bindValue(":rid",randRoom);



        q.exec();
        vasi.commit();
        ShowSuccess();
    }
    catch (int ex) {
        ShowError(q);
    }
    q.finish();
}

