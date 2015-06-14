#include "crud.h"


extern QSqlDatabase vasi;



QList<QString> CRUD::getPayTypes() {
    QSqlQuery q;

    QList<QString> types;
    q.exec("SELECT Comment FROM PayType");
    while (q.next()) {

        types.append(q.value(0).toString());
        qDebug() << q.value(0).toString();
    }
    q.finish();
    return types;
}


QList<QString> CRUD::getGroupIDs(QString Name) {
    QList<QString> groups;
    QSqlQuery q;
    int tid;
    q.exec("SELECT MembID FROM Members Where Name  LIKE '%" + Name + "%'");
    while (q.next()) {
        tid=q.value(0).toInt();
    }

    qDebug () << "crud teacherid " << tid;
    q.prepare("SELECT GroupID FROM Groups Where TeacherID=:tid");
    groups.append("-1");

    q.bindValue(":tid",tid);
    q.exec();
    while (q.next()) {
        groups.append(q.value(0).toString());
    }


    return groups;
}

void CRUD::save(Payments p) {
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

        if (p.getGroupID()<0) {
            //it means it was a gift or kassen pay
        q.prepare("INSERT INTO `Payments`  (`TeacherID`, `Dat`, `Amount`,  `PayTypeID`) VALUES (:tid,:dat,:euro,:ptid)");

}
        else {
            // payment for group
            q.prepare("INSERT INTO `Payments`  (`TeacherID`, `Dat`, `Amount`,  `PayTypeID`,`GroupID`) VALUES (:tid,:dat,:euro,:ptid,:gid)");
            q.bindValue(":gid",p.getGroupID());
        }

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



void CRUD::ShowSuccess() {
    QMessageBox msgBox;
    msgBox.setText("OK");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Information);
    int ret = msgBox.exec();

}


void CRUD::ShowError(QSqlQuery q) {
    QMessageBox msgBox;
    msgBox.setText(q.lastError().text());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon( QMessageBox::Critical);

    int ret = msgBox.exec();
    q.finish();
}

