
//ALL TABLE MODELS ARE MODELLED HERE
#include <QString>
#include <QList>
#include <QSqlQuery>
#include <QStringList>
#include <QDebug>
#include <QVariant>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QColor>
#include <QBrush>

namespace MVC { //nested namespaces ???



struct RGBColor {
    int Red;
    int Green;
    int Blue;
    //cell coordinates
    int x;
    int y;
};




QStandardItemModel* makeModel(QStringList headers,QList<QStringList> data,QList<RGBColor> coldata);
    //universal QStandardItemModel maker
    /* INPUT :
     * horizontal header labels
     * cell data : a string list for every row : all rows have equal length
     * color data : backround color data for cells
     * OUTPUT a model with headers and colored data
     */



//***************************      MODEL FOR GENERAL/ShowGroups       ***************************


struct General_ShowGroupModel {
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




QStandardItemModel* getGeneral_ShowGroup_Model();



//***************************      MODEL FOR GENERAL/Schwierigkeit       ***************************



struct SchwierigModel {
  QString SchwerID;
  QString NumCourses;
  QString red;
  QString green;
  QString blue;
};






QStandardItemModel* getGeneral_SchwierigModel();




} //END OF NAMESPACE
