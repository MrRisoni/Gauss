#include "geldrechen.h"


#include <QDate>
#include <QSqlError>
#include <QDebug>

//calculates the fees and payments
GeldRechen::GeldRechen()
{

}

// take into account the dropout from group


QDate GeldRechen::minDate(QDate a,QDate b) {
    if (a.toJulianDay()> b.toJulianDay()) {
        return b;
    }
    else {
        return a;
    }
}

QDate GeldRechen::maxDate(QDate a,QDate b) {
    if (a.toJulianDay()> b.toJulianDay()) {
        return a;
    }
    else {
        return b;
    }

}

void GeldRechen::calcStudentFees() {
    /*
      absencies are NOT and SHOULD NOT be taken into account
      unless SERIOUS REASON
      see table absent


      discounts ????
    */
    QSqlQuery q,q2,q3,q4;
    q.exec("SELECT GroupID,Fee,StartDate FROM Groups Where Active=1");
    while (q.next()) {
        QString gid=q.value(0).toString();
        float fee=q.value(1).toFloat();
        QDate start_date = q.value(2).toDate();
        //for every active group

        //for every student in that group
         q2.prepare("SELECT StudID,Added,Dropped FROM Ensembles WHERE GroupID=:gid");
         q2.bindValue(":gid",gid);
         while (q2.exec()) {
             QString studid=q2.value(0).toString();
             QDate joined=q2.value(1).toDate();
             QDate dropped = q2.value(1).toDate();
             //get group history  from GREATEST(groupstart,added) up to LEAST(dropout,curdate)  MINUS  Truant==0 abscencies

             q3.prepare("SELECT SUM(Duration) FROM History  Where Dat>= :join_date AND Dat<=:leave_date AND GroupID=:gid  AND Valid=1  AND HistID NOT IN (SELECT HistID FROM Absent WHERE StudentID=:sid and Truant=0)") ;
             q3.bindValue(":join_date",maxDate(joined,start_date));
             q3.bindValue(":leave_date",minDate(dropped,QDate::currentDate()));
             q3.bindValue(":gid",gid);
             q3.bindValue(":sid",studid);
             q3.exec();
             float muss_bezahlen;
             while (q3.next()) {
                  muss_bezahlen= fee*q3.value(0).toFloat();
             }

            // q4
                //     insert else update
         }


    }
}

void GeldRechen::calcSProfSalaries() {
    QSqlQuery q,q2,q3;


    q.exec("SELECT GroupID,TeacherID,BW,CW FROM Groups Where Active=1");
    while (q.next()) {
        /*
         for that group id
         calculate the duration of history whose valid =1 and date<=current_date


         salary = duration*(bw+cw)



         */

        qDebug() << "-------------------------";
        float sal =0;
        QString gid = q.value(0).toString();
        QString tid = q.value(1).toString();
        float bw = q.value(2).toFloat();
        float cw = q.value(3).toFloat();


        qDebug() << "fetching hrous for " << tid << " group " << gid << " bw is " << bw << " cw is " << cw;
        q2.exec("SELECT SUM(Duration) FROM History Where GroupID='"+ gid+"' AND Valid=1 AND Dat<=CURRENT_DATE");
        while (q2.next()) {
            sal = q2.value(0).toFloat()*(bw+cw);

            qDebug() << " dur is " << q2.value(0).toFloat() << " sal is " << sal;
        }


        QString s;


        s+="INSERT INTO ShouldPay  (TeacherID,Amount, GroupID, Updated) VALUES (:tid,:euro,:gid,CURDATE()) ";
        s+=" ON DUPLICATE KEY UPDATE  Amount=:euro , Updated=CURDATE()";


        qDebug() << s;
        q3.prepare(s);
        q3.bindValue(":euro",sal);
        q3.bindValue(":tid",tid);
        q3.bindValue(":gid",gid);

        if (!q3.exec())  {
            qDebug() << "error.." << q3.lastError().driverText() << " " << q3.lastError().databaseText();

        }

    }


    q.finish();
    q2.finish();
    q3.finish();
}
