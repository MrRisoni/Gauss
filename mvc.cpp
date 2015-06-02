#include "mvc.h"

//***************************      MODEL FOR GENERAL/ShowGroups       ***************************




QStandardItemModel* MVC::getGeneral_ShowGroup_Model() {


    QSqlQuery q;
    QStringList headers;
    headers.append("GroupID");
    headers.append("CourseName");
    headers.append("Starts");
    headers.append("Ends");
    headers.append("Teacher");
    headers.append("# Students");
    headers.append("# Hours per week");
    headers.append("Hours planned");
    headers.append("Ausgeben");
    headers.append("Einnehmen");
    headers.append("Unser_Schulden");
    headers.append("Student_Schulden");


    QList<General_ShowGroupModel> modelo;


    QString s;
    q.exec("SELECT GroupID FROM Groups ");
    while (q.next()) {
        General_ShowGroupModel G = General_ShowGroupModel();
        G.GroupID=q.value(0).toString();
        qDebug() << G.GroupID;
        modelo.append(G);
    }
    qDebug() << s;



    q.finish();


    QList<RGBColor> farbe;

    QStandardItemModel *mod = new QStandardItemModel();
    mod->setHorizontalHeaderLabels(headers);

    int row =0;
    for (General_ShowGroupModel G : modelo) {
        QStandardItem *itGroupID = new QStandardItem();
        itGroupID->setText(G.GroupID);
        mod->setItem(row,0,itGroupID);


    }

    QList<QStringList> data;

    for (General_ShowGroupModel G : modelo) {
        QStringList record;
        record.append(G.GroupID);


        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");
        record.append("");


        data.append(record);
    }


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
