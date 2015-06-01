
//ALL TABLE MODELS ARE MODELLED HERE
#include <QString>
#include <QList>
#include <QSqlQuery>
#include <QStringList>
#include <QDebug>
#include <QVariant>
#include <QStandardItem>
#include <QStandardItemModel>

namespace MVC { //nested namespaces ???

//***************************      MODEL FOR GENERAL/ShowGroups       ***************************





struct General_ShowGroup {
    QString GroupID;
    QString CourseName;
    QString Starts;
    QString Ends;
    QString Teacher;
    QString NumStudents;
    QString HoursPerWeek;
    QString PlannedHours;
    QString Ausgeben; //how much money have we given the professor
    QString Einnehmen; // how much money have we earned from the fees
    QString Schulden; // how much money do we owe the professor
    QString Deficit; // how much money do the students owe to us
};

struct General_ShowGroupsMVC {
    QList<General_ShowGroup> Model;
    QStringList headers;
};


General_ShowGroupsMVC getGeneral_ShowGroup_Model();
QStandardItemModel* getGeneral_ShowGroup_View();


//                          ----------------------------------------------------
















} //END OF NAMESPACE
