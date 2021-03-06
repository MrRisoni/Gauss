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


    //qDebug () << "date compar " << a.toString() << " with " << b.toString();
    if ((a.month()==0) && (a.year()==0) && (a.day()==0)) {
        return b;
    }
    else {



        if (a.toJulianDay()> b.toJulianDay()) {
            return b;
        }
        else {
            return a;
        }
    }
}

QDate GeldRechen::maxDate(QDate a,QDate b) {
    //check for null date

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

    qDebug () << "FEE FOR STUDENTS";
    QSqlQuery q,q2,q3,q4;
    q.exec("SELECT GroupID,StartDate FROM Groups");
    while (q.next()) {
        QString gid=q.value(0).toString();

        QDate start_date = q.value(1).toDate();
        //for every active group

        qDebug() << " fee calc for group " << gid;


        // a student may have joined the group after the group started and may have left before the group ended
        //for every student in that group
         q2.prepare("SELECT StudID,Added,Dropped FROM Ensembles WHERE GroupID=:gid");
         q2.bindValue(":gid",gid);
         q2.exec();

         while (q2.next()) {
             QString studid=q2.value(0).toString();
             QDate joined=q2.value(1).toDate();
             QDate dropped = q2.value(2).toDate();
             float discount =0;
             qDebug() << "--------------------";
             qDebug () << "studid " << studid << "joined " << maxDate(joined,start_date) << " dropped " << minDate(dropped,QDate::currentDate());
             //get group history  from GREATEST(groupstart,added) up to LEAST(dropout,curdate)  MINUS  Truant==0 abscencies

             q3.prepare("SELECT Duration,fee+ fee*vat FROM History  Where Dat>= :join_date AND Dat<=:leave_date AND GroupID=:gid  AND Valid=1  AND HistID NOT IN (SELECT HistID FROM Absent WHERE StudentID=:sid and Truant=0)") ;
             qDebug() << "Joined date " << joined.toString() << " dropped " << dropped.toString();
             q3.bindValue(":join_date",maxDate(joined,start_date));
             q3.bindValue(":leave_date",minDate(dropped,QDate::currentDate()));
             q3.bindValue(":gid",gid);
             q3.bindValue(":sid",studid);

             q3.exec();

             float unterricht = 0;
             float muss_bezahlen=0;
             while (q3.next()) {
                 //qDebug() << "VATED" << q3.value(1).toFloat();
                  muss_bezahlen += q3.value(0).toFloat() * q3.value(1).toFloat() ;
                  unterricht += q3.value(0).toFloat();
             }

             //discount
             muss_bezahlen -= muss_bezahlen * discount/100.0f;


             qDebug() << "student " << studid <<  "group " << gid <<  " must pay " << muss_bezahlen << " total hours " << unterricht;


             QString qry=" UPDATE  ShouldBePayed SET  Amount=:euro , Updated=CURDATE()  WHERE GroupID=:gid AND  StudentID=:stid ";
             q4.prepare(qry);
             q4.bindValue(":stid",studid);
             q4.bindValue(":gid",gid);
             q4.bindValue(":euro",muss_bezahlen);

             if (!q4.exec()) {

                 qDebug() << "error.." << q4.lastError().driverText() << " " << q4.lastError().databaseText();

             }



         }


    }
}




void GeldRechen::calcSProfSalaries() {
    QSqlQuery q,q2,q3;


    q.exec("SELECT GroupID,TeacherID FROM Groups");
    while (q.next()) {
        /*
         for that group id
         calculate the duration of history whose valid =1 and date<=current_date


         salary = duration*(bw+fw)



         */

        qDebug() << "-------------------------";
        float sal =0;
        QString gid = q.value(0).toString();
        QString tid = q.value(1).toString();



        qDebug() << "fetching hrous for " << tid << " group " << gid;
        q2.exec("SELECT Duration,bw,fw FROM History Where GroupID='"+ gid+"' AND Valid=1 AND Dat<=CURRENT_DATE");

        while (q2.next()) {
            sal += q2.value(0).toFloat()*(q2.value(1).toFloat()+q2.value(2).toFloat());

        }


        QString s;


        s+="INSERT INTO ShouldPay  ( GroupID, Amount,Updated) VALUES (:gid,:euro,CURDATE()) ";


        qDebug() << s;
        q3.prepare(s);
        q3.bindValue(":euro",sal);
        q3.bindValue(":gid",gid);

        if (!q3.exec())  {
            qDebug() << "error.." << q3.lastError().driverText() << " " << q3.lastError().databaseText();

        }

    }


    q.finish();
    q2.finish();
    q3.finish();
}
