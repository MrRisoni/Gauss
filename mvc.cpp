#include "mvc.h"


//***************************      MODEL FOR Student/ShowStudents       ***************************


QStandardItemModel* MVC::getGeneral_ShowStudents_Model() {
    QSqlQuery q,q2;
    QStringList headers;
    headers.append("StudentID");
    headers.append("ADT");
    headers.append("Name");
    headers.append("Birth-Date");
    headers.append("Reg-Date");
    headers.append("Address");
    headers.append("Mobile");
    headers.append("Phone");
    headers.append("Fath Mobile");
    headers.append("Fath Name");
    headers.append("Mom Mobile");
    headers.append("Mom Name");
    headers.append("Discipline");
    headers.append("# Groups");
    headers.append("# Absencies");
    headers.append("Special Cat");
    headers.append("Last lesson");
    headers.append("Last payed");
    headers.append("Schulden");









    QString s="(select M.MembID,M.ADT,M.Name as Namen,M.BirthDate,M.RegDate,M.Address,M.Mobile, M.Phone";
    s+=" , S.FatherMobile,M.FName,S.MotherMobile,M.MName,D.Name,0,0,K.Description FROM Members M,Schuler ";
    s+=" S,Disciplines D , ";
    s+=" SpecialFees SF,DiscountCats K Where M.MembTypeID=2 AND S.DiscipleID = D.DiscID ";
    s+=" AND M.MembID=S.StudentID AND SF.StudentID=M.MembID AND SF.CatID=K.SpecialID ) UNION ";
    s+=" (select M.MembID,M.ADT,M.Name as Namen ,M.BirthDate, M.RegDate,M.Address,M.Mobile,M.Phone, ";
    s+=" S.FatherMobile,M.FName,S.MotherMobile,M.MName, D.Name,0,0,'NONE' FROM Members M,Schuler S, ";
    s+=" Disciplines D Where M.MembTypeID=2 AND S.DiscipleID = D.DiscID AND M.MembID=S.StudentID AND ";
    s+=" M.MembID NOT IN (SELECT StudentID FROM SpecialFees)) order by Namen";

    QList<QStringList> data;

    q.exec(s);
    qDebug () << s;
    while (q.next()) {
        QStringList record;

        QString studid=q.value(0).toString();
        record.append(q.value(0).toString()); //studid
        record.append(q.value(1).toString()); //adt
        record.append(q.value(2).toString()); //name
        record.append(q.value(3).toString()); //birth date
        record.append(q.value(4).toString()); //reg date
        record.append(q.value(5).toString()); //address
        record.append(q.value(6).toString()); //mobile
        record.append(q.value(7).toString()); //phone
        record.append(q.value(8).toString()); //fath mobile
        record.append(q.value(9).toString()); // fath name
        record.append(q.value(10).toString()); //mom mobile
        record.append(q.value(11).toString()); //mom name
        record.append(q.value(12).toString()); // discipline

        //query to find the groups

        q2.prepare("Select Count(E.GroupID) From Ensembles E,Groups G Where E.StudID=:sid AND G.GroupID=E.GroupID AND G.Active=1 AND E.Added<=CURRENT_DATE AND CURRENT_DATE>=E.Dropped");
        q2.bindValue(":sid",studid);
        q2.exec();
        while (q2.next()) {
            record.append(q2.value(0).toString()); //# groups

        }

        //abscencies
        q2.prepare("SELECT COUNT(HistID) FROM Absent WHERE StudentID=:stid");
        q2.bindValue(":stid",studid);
        q2.exec();
        while (q2.next()) {
            record.append(q2.value(0).toString());
        }

        record.append(q.value(15).toString()); //special cat


        record.append("0"); //last lesson and not absent
        record.append("0"); //last payed
        record.append("0"); //schulden //overlap with geld rechen




        data.append(record);
    }





    q.finish();
    QList<RGBColor> farbe;

    return  MVC::makeModel(headers, data,farbe);

}



//***************************      MODEL FOR GENERAL/ShowGroups       ***************************

QList<QListWidgetItem *> MVC::getGeneral_ShowFutureHistoryDates(QString GroupID) {

    QList<QListWidgetItem*> itms;

    QSqlQuery q;
    QString s="SELECT Dat FROM History WHERE  Valid=1 AND Dat>CURRENT_DATE AND GroupID=:gid ORDER BY Dat ASC ";
    qDebug () << s;
    q.prepare(s);
    q.bindValue(":gid",GroupID);
    q.exec();
    while (q.next()) {
        QListWidgetItem *it= new QListWidgetItem();
        it->setText(q.value(0).toString());

        itms.append(it);
    }


    q.finish();
    return itms;
}





QStandardItemModel* MVC::getGeneral_ShowPastHistory(QString GroupID) {
    QSqlQuery q;
    QStringList headers;
    headers.append("Day");
    headers.append("Date");
    headers.append("Room");
    headers.append("Hour");
    headers.append("Duration");
    headers.append("#Absent");

    QList<QStringList> data;

    QString s="SELECT DAYNAME(H.Dat), H.Dat , R.Name , S.HourN,H.Duration FROM History H,Rooms R ,Hours S Where S.HourID=H.StartHourID AND H.RoomID=R.RoomID AND H.Valid=1 AND H.GroupID=:gid AND H.Dat<=CURRENT_DATE";
    qDebug () << s;
    q.prepare(s);
    q.bindValue(":gid",GroupID);
    q.exec();
    while (q.next()) {
        QStringList record;
        record.append(q.value(0).toString());
        record.append(q.value(1).toString());
        record.append(q.value(2).toString());
        record.append(q.value(3).toString());
        record.append(q.value(4).toString());

        data.append(record);

    }

    QList<RGBColor> farbe;

    q.finish();
    return  MVC::makeModel(headers, data,farbe);

}


QStandardItemModel* MVC::getGeneral_ShowGroup_Model() {



    QSqlQuery q,q2;
    QStringList headers;
    headers.append("GroupID");
    headers.append("CourseName");
    headers.append("Starts");
    headers.append("Schedule Ends");
    headers.append("Teacher");
    headers.append("# Students");
    headers.append("# Hours per week");
    headers.append("Hours remain");
    headers.append("Ausgeben"); // money we have given the proffessor
    headers.append("Einnehmen"); // money we have received from students
    headers.append("Unser_Schulden"); //Geld , das wir dem Lehrer schulden
    headers.append("Student_Schulden"); // Geld , das die Schuler uns schulden
    headers.append("Gross salary"); // base wage + course wage
    headers.append("Fee");



    QList<QStringList> data;

    QString s;
    q.exec("SELECT G.GroupID,C.CourseName,G.StartDate,M.Name,G.BW+G.CW,G.Fee FROM Groups G,Courses C,Members M WHERE G.CourseID=C.CourseID AND M.MembID=G.TeacherID AND G.Active=1 ");
    while (q.next()) {

        QStringList record;

        QString teacher_name=q.value(3).toString();

        int GroupID=q.value(0).toInt();
        record.append(q.value(0).toString()); // group ud

        record.append(q.value(1).toString());// course name

        record.append(q.value(2).toString()); // start date


        //permatimes table
        q2.prepare("SELECT PermaID,EndsOn From Permament WHERE GroupID=:gid");
        q2.bindValue(":gid",GroupID);
        int PermaID=0;
        q2.exec();

        while (q2.next()) {
            PermaID=q2.value(0).toInt();  //end date
            record.append(q2.value(1).toString());
        }



        record.append(q.value(3).toString()); //teacher;


        //num of students
        //number of students = count(ensembles)- count(non null dropouts)
        q2.prepare("SELECT Count(StudID) FROM Ensembles WHERE GroupID=:gid AND Dropped< CURRENT_DATE()");
        q2.bindValue(":gid",GroupID);
        q2.exec();

        while (q2.next()) {
            record.append(q2.value(0).toString());

            qDebug() << "number of students for " << GroupID << q2.value(0).toString();
        }





        //avg hours per week
        q2.prepare("SELECT SUM(Duration) FROM PermaTimes Where PermaID=:prid");
        q2.bindValue(":prid",PermaID);
        q2.exec();
        while (q2.next()) {
            qDebug() << "avg hours per week for " << GroupID << q2.value(0).toString();
            record.append(q2.value(0).toString());
        }

        //hours planned sum all history up to endsOn and valid=1  minus sum done and valid=1
        q2.prepare("SELECT SUM(Duration) FROM History WHERE GroupID=:gid and Valid=1 AND Dat>CURRENT_DATE");
        q2.bindValue(":gid",GroupID);
        q2.exec();
        while (q2.next()) {
            record.append(q2.value(0).toString());
        }






        //we know the history of these course and the fee/wages therefor we can calucate the expected earnings...


        float Ausgeben=0;
        q2.prepare("SELECT SUM(Amount) FROM Payments WHERE GroupID=:gid");
        q2.bindValue(":gid",GroupID);
        q2.exec();
        while (q2.next()) {
            Ausgeben=q2.value(0).toFloat();
        }
        record.append(QString::number(Ausgeben));

        q2.prepare("SELECT SUM(Amount) FROM Funds WHERE GroupID=:gid");
        q2.bindValue(":gid",GroupID);
        q2.exec();
        float Einkommen=0;
        while (q2.next()) {
            Einkommen=q2.value(0).toFloat();
        }
        record.append(QString::number(Einkommen)); //einnemhen

        //get the how we should have payed

        q2.prepare("SELECT Amount FROM ShouldPay Where GroupID=:gid");
        q2.bindValue(":gid",GroupID);
        q2.exec();
        float shouldpay;
        while (q2.next()) {
            shouldpay=q2.value(0).toFloat();
        }

        //calc how much have we payed
        float havepayed;
        q2.prepare("SELECT SUM(P.Amount) FROM Payments P,Members M WHERE P.TeacherID=M.MembID AND P.GroupID=:gid AND M.Name=:name");
        q2.bindValue(":name",teacher_name);
        q2.bindValue(":gid",GroupID);
        q2.exec();

        while (q2.next()) {
            havepayed=q2.value(0).toFloat();
        }


        record.append(QString::number(shouldpay-havepayed)); // how much money do we owe in total to the teacher

        //calc how much students should pay
        q2.prepare("SELECT SUM(Amount) FROM ShouldBePayed WHERE GroupID=:gid");
        q2.bindValue(":gid",GroupID);
        q2.exec();
        float shouldreceive=0;
        while (q2.next()) {
            shouldreceive=q2.value(0).toFloat();
        }

        //have actually received

        float havereceived=0;
        q2.prepare("SELECT SUM(Amount)  FROM Funds Where GroupID=:gid");
        q2.bindValue(":gid",GroupID);
        q2.exec();
        while (q2.next()) {
            havereceived=q2.value(0).toFloat();
        }

        record.append(QString::number(shouldreceive-havereceived));
        record.append(q.value(4).toString().mid(0,5)); // gross salary
        record.append(q.value(5).toString().mid(0,5)); //fee





        data.append(record);


    }




    q.finish();
    q2.finish();

    QList<RGBColor> farbe;


    return  MVC::makeModel(headers, data,farbe);

}





QStandardItemModel* MVC::getGeneral_SchwierigModel() {


    qDebug() << "MVC";


    QStringList headers;

    headers.append("SchwerID");
    headers.append("# Courses");


    QSqlQuery q;

    //get schwerid,color
    QString s="SELECT SchwerID,Red,Green,Blue,Plithos FROM (SELECT SchwerID,Red,Green, ";
    s+=" BLUE FROM Schwierigkeit) AS Stuffe INNER JOIN ";
    s+="  ( SELECT Schwer,Count(Schwer) As Plithos From Courses Group By Schwer) ";
    s+=" AS Kursen ON Kursen.Schwer = Stuffe.SchwerID ";

    qDebug() << s;


    q.exec(s);

    //translate to model;

    QList<SchwierigModel> modelo;

    while (q.next()) {
        SchwierigModel mod=SchwierigModel();
        mod.SchwerID=q.value(0).toString();
        mod.red=q.value(1).toString();
        mod.green=q.value(2).toString();
        mod.blue=q.value(3).toString();
        mod.NumCourses=q.value(4).toString();

        modelo.append(mod);

    }
    q.finish();

    QList<QStringList> data;
    QList<RGBColor> coldata;

    int grammi=0;

    qDebug() << "fetched " << modelo.size() << "stufen";
    for (SchwierigModel  m : modelo) {
        QStringList record;


        record.append(m.SchwerID);
        record.append(m.NumCourses);

        data.append(record);

        RGBColor F;
        F.Red = m.red.toInt();
        F.Green = m.green.toInt();
        F.Blue = m.blue.toInt();
        F.y=1;
        F.x=grammi;



        qDebug () << "Schwer Stuffe " << m.SchwerID << "r " << m.red << "g" << m.green << "b" << m.blue;
        coldata.append(F);

        grammi++;

    }


    return  makeModel(headers, data,coldata);

}



//***************************      MODEL FOR Sprache/ManageDiplomas       ***************************







QStandardItemModel* MVC::getSpracheDiplomas() {
    QStringList headers;

    headers.append("DiploID");
    headers.append("Name");
    headers.append("Institut");
    headers.append("NumTeachers");
    headers.append("NumStudents");
    headers.append("SuccessRate");
    headers.append("SuccessGrade");

    QList<QStringList> data;
    QList<RGBColor> coldata;

    return makeModel(headers, data,coldata);

}



//***************************      MODEL FOR Receipts/ManageSalaries       ***************************


QStandardItemModel* MVC::getReceiptEchelons() {


    QSqlQuery q;
    QStringList headers;
    headers.append("EchelID");
    headers.append("Xp");
    headers.append("NumTeachers");

    QList<QStringList> data;
    QList<RGBColor> coldata;


    q.exec("Select EchelID,Exp From Echelon Where Active=1");

    while (q.next()) {
        QStringList row;
        row.append(q.value(0).toString());
        row.append(q.value(1).toString());
        row.append("0");
        data.append(row);
    }


    q.finish();



    return makeModel(headers,data,coldata);


}

//***************************      MODEL FOR Receipts/BaseWages       ***************************

QStandardItemModel* MVC::getReceiptBaseWages(){

    QStringList headers;
    headers.append("EchelID");
    headers.append("Xp");
    headers.append("Date");
    headers.append("Wage");


    QList<RGBColor> coldata;

    QString s ="Select E.EchelID, E.Exp ,B.Dat, B.Wages FROM Echelon E,BaseWages B Where B.EchelID=E.EchelID ORDER BY E.Exp DESC";\


    return makeModel( headers,QueryToList(s), coldata);

}





QStandardItemModel* MVC::getGeneralManageCourses() {

    QStringList headers;
    headers.append("CourseID");
    headers.append("CourseName");
    headers.append("DepName");
    headers.append("NumTeachers");
    headers.append("NumStudents");
    headers.append("NumGroups");
    headers.append("NumOpenRequests");
    headers.append("PaySchemes");
    headers.append("FeeUpdate");

    QList<QStringList> data ;
    QList<RGBColor> coldata;

    return makeModel(headers,data,coldata);

}


QStandardItemModel* MVC::getGeneralManageFees() {

    QList<QStringList> data;
    QList<RGBColor> coldata;


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


    s=" Select Alpha.CourseID ,Alpha.CourseName,Charlie.Plithos,Charlie.Latest FROM (Select CourseID,CourseName From Courses Where DepID=1 ORDER BY CourseName ASC) as Alpha INNER JOIN (Select CourseID,0 as Plithos,0 as Latest FROM Courses Where DepID=1 AND CourseID NOT IN (SELECT CourseID FROM FeeSchule) UNION SELECT CourseID,Count(Dat) As Fores ,MAX(Dat) as Latest FROM `FeeSchule`Group By CourseID) AS Charlie WHERE Charlie.CourseID=Alpha.CourseID  ORDER BY Alpha.CourseName ASC" ;
    qDebug() << s;

    q.exec(s);









    QStringList headers;
    headers.append("CourseID");
    headers.append("Name");
    headers.append("#Changes");
    headers.append("Latest update");
    headers.append("Fee");
    headers.append("Debt");
    headers.append("Profit");



    while (q.next()) {

        QStringList record;

        record.append(q.value(0).toString()); //courseid
        record.append(q.value(1).toString()); //name
        record.append(q.value(2).toString()); //#changes
        record.append(q.value(3).toString()); //updated

        record.append("0"); //fee
        record.append("0");
        record.append("0");



        data.append(record);
    }


    //query for fee price
    s="select Kursen.CourseID,Kursen.Fee FROM (Select CourseID,Fee,Dat From FeeSchule) As Kursen INNER JOIN (Select CourseID,MAX(Dat) As Updat From FeeSchule GROUP BY CourseID ) As Daten ON Daten.CourseID=Kursen.CourseID AND Daten.Updat=Kursen.Dat ";
    qDebug() << s;

    q.exec(s);
    while (q.next()) {
        //search every record of the data

        for (int i=0;i<data.size();i++) {

            if (data.at(i).at(0)==q.value(0).toString()) {
                // record.replace(4,q.value(1).toString());
                data[i][4]=q.value(1).toString();
                // qDebug() << "setting price for courseid " << q.value(0).toString() << " " << q.value(1).toString() << " " << record[4];

            }

        }
    }
    q.finish();




    return makeModel(headers,data,coldata);
}










































//                          ----------------------------------------------------



QList<QStringList> MVC::QueryToList(QString qry) {
    QSqlQuery q;
    QList<QStringList> data;

    q.exec(qry);

    QSqlRecord rec = q.record();



    qDebug() << "Number of columns: " << rec.count();
    while (q.next()) {
        QStringList record;
        for (int i=0;i<rec.count();i++) {
            record.append(q.value(i).toString());
        }
        data.append(record);
    }
    q.finish();

    return data;

}






QStandardItemModel* MVC::makeModel(QStringList headers,QList<QStringList> data,QList<RGBColor> coldata) {
    //universal QStandardItemModel maker
    /* INPUT :
     * horizontal header labels
     * cell data : a string list for every row : all rows have equal length
     * color data : backround color data for cells
     * OUTPUT a model with headers and colored data
     */

    QStandardItemModel *mod = new QStandardItemModel();
    mod->setHorizontalHeaderLabels(headers);




    //for each row
    int row =0;
    for (QStringList record : data ) {
        int col=0;
        for (QString cell : record) {

            // no duplicate insertion
            QStandardItem *itm = new QStandardItem();
            itm->setText(cell);


            //search the coldata array for the coordsd row,col
            for (RGBColor farbe : coldata) {
                if ((farbe.x == row) && (farbe.y == col)) {
                    QBrush br;
                    QColor c;
                    c.setRed(farbe.Red);
                    c.setGreen(farbe.Green);
                    c.setBlue(farbe.Blue);
                    br.setColor(c);
                    br.setStyle(Qt::SolidPattern);
                    itm->setBackground(br);
                }

            }

            mod->setItem(row,col,itm);
            col++;


        }

        row++;
    }

    return mod;
}
