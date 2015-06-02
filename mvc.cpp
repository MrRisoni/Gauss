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
    headers.append("Schulden");
    headers.append("Deficit");


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
























//                          ----------------------------------------------------


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
