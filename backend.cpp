#include "backend.h"

//***************************      MODEL FOR GENERAL/ShowGroups       ***************************




 MVC::General_ShowGroupsMVC MVC::getGeneral_ShowGroup_Model() {

    QSqlQuery q;
    General_ShowGroupsMVC view;
    view.headers.append("GroupID");
    view.headers.append("CourseName");
    view.headers.append("Starts");
    view.headers.append("Ends");
    view.headers.append("Teacher");
    view.headers.append("# Students");
    view.headers.append("# Hours per week");
    view.headers.append("Hours planned");
    view.headers.append("Ausgeben");
    view.headers.append("Einnehmen");
    view.headers.append("Schulden");
    view.headers.append("Deficit");


    QString s;
    q.exec("SELECT GroupID FROM Groups ");
    while (q.next()) {
        General_ShowGroup G = General_ShowGroup();
        G.GroupID=q.value(0).toString();
        qDebug() << G.GroupID;
        view.Model.append(G);
    }
    qDebug() << s;



    q.finish();
    return view;
}




QStandardItemModel* MVC::getGeneral_ShowGroup_View() {
    General_ShowGroupsMVC view = getGeneral_ShowGroup_Model();


    QStandardItemModel *mod = new QStandardItemModel();
    mod->setHorizontalHeaderLabels(view.headers);

    int row =0;
    for (General_ShowGroup G : view.Model) {
        QStandardItem *itGroupID = new QStandardItem();
        itGroupID->setText(G.GroupID);
        mod->setItem(row,0,itGroupID);
    }
    return mod;
}


//                          ----------------------------------------------------

