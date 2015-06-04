#include "zeitwandel.h"
#include <tuple>
#include <algorithm>

#include <QDebug>


inline bool SegmentOverpap(short a_start,short a_dur,short b_start,short b_dur) {
    return std::max(0, std::min(a_start+a_dur, b_start+b_dur) - std::max(a_start, b_start));

}


struct Studen{
    QString GroupID;
    int RoomID;
    int SHhour;
    int DurInUnits;
    QString Course;
    QString Teacher;
    bool dontInsert=false;
};

ZeitWandel::ZeitWandel()
{
    //setup heads for timetable

}


std::tuple<QStandardItemModel*,QList<Cell>> ZeitWandel::getSchule() {



    QStringList HorHeaders;
    QStringList VerHeaders;

    QSqlQuery q;
    q.exec("SELECT RoomID,Name From Rooms ORDER BY Name ASC ");
    while (q.next()) {
        RoomIDs.append(q.value(0).toInt());
        HorHeaders.append(q.value(1).toString());
    }
    //calculats timetable
    //headers are rooms
    //columns are hours

    //get the hours
    q.exec("SELECT HourN FROM Hours");
    while (q.next()) {
        VerHeaders.append(q.value(0).toString());
    }

    QStandardItemModel *schule_time_mod = new QStandardItemModel();
    schule_time_mod->setHorizontalHeaderLabels(HorHeaders);
    schule_time_mod->setVerticalHeaderLabels(VerHeaders);





    //get the data from the db
    //groupid,roomid,hourid,duration,teacher,coursename

    QString s="select H.GroupID,H.RoomID,H.StartHourID-1,H.Duration,M.Name,C.CourseName From History H ";
    s+=" ,Members M,Courses C,Groups G Where H.Valid=1 AND H.Dat=CURRENT_DATE AND G.GroupID=H.GroupID ";
    s+=" AND C.CourseID=G.CourseID AND M.MembID=G.TeacherID ";

    qDebug() << s;
    //OVERLAPS PICK THE FIRST ENTRY IN THE TABLE
    QList<Studen> QueryResults;
    q.exec(s);
    while (q.next()) {
        Studen S=Studen();
        S.GroupID=q.value(0).toString();
        S.RoomID=q.value(1).toInt();
        S.SHhour=q.value(2).toInt();
        S.DurInUnits=q.value(3).toFloat()/0.5f; // divide by 0.5 that is our unit
        S.Teacher=q.value(4).toString();
        S.Course=q.value(5).toString();

        QueryResults.append(S);


    }

    //random shuffle :)
    //std::random_shuffle(QueryResults.begin(),QueryResults.end());

    QList<Cell> kelia;

    //append to table
    for (int w=0;w<QueryResults.size();w++) {

        //check if it can be inserted to the model
        if (QueryResults.at(w).dontInsert==false) {

            QStandardItem* itStunde= new QStandardItem();
            itStunde->setText(QueryResults.at(w).GroupID+  " \n" + QueryResults.at(w).Course + "\n" + QueryResults.at(w).Teacher );

            //search the RoomsID to get the column
            int col=RoomIDs.indexOf(QueryResults.at(w).RoomID);

            schule_time_mod->setItem(QueryResults.at(w).SHhour,col,itStunde);

            // iterate the other members of Query results
            //if you find an overlap set the dont_insert to true
            for (int x=w+1;x<QueryResults.size();x++) {
                //check for ROOM!!!!
                if (QueryResults.at(w).RoomID==QueryResults.at(x).RoomID) {
                    if (SegmentOverpap(QueryResults.at(w).SHhour,QueryResults.at(w).DurInUnits,QueryResults.at(x).SHhour,QueryResults.at(x).DurInUnits)>0){
                        QueryResults[x].dontInsert=true;
                    }
                }
            }

            //insert the duration as row span
            Cell zell=Cell();
            zell.row=QueryResults.at(w).SHhour;
            zell.col=col;
            zell.row_span=QueryResults.at(w).DurInUnits;

            kelia.append(zell);



        }


    }


    q.finish();


    return std::tuple<QStandardItemModel*,QList<Cell>>(schule_time_mod,kelia);
}
