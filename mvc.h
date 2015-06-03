
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
#include <QSqlRecord>
#include <QListWidgetItem>

namespace MVC { //nested namespaces ???



struct RGBColor {
    int Red;
    int Green;
    int Blue;
    //cell coordinates
    int x;
    int y;
};

QList<QStringList> QueryToList(QString qry);


QStandardItemModel* makeModel(QStringList headers,QList<QStringList> data,QList<RGBColor> coldata);
    //universal QStandardItemModel maker
    /* INPUT :
     * horizontal header labels
     * cell data : a string list for every row : all rows have equal length
     * color data : backround color data for cells
     * OUTPUT a model with headers and colored data
     */
    
    
//***************************      MODEL FOR Student/ShowStudents       ***************************

QStandardItemModel* getGeneral_ShowStudents_Model();

//***************************      MODEL FOR GENERAL/ShowGroups       ***************************


QList<QListWidgetItem *> getGeneral_ShowFutureHistoryDates(QString GroupID);



QStandardItemModel* getGeneral_ShowPastHistory(QString GroupID);

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



//***************************      MODEL FOR Discount       ***************************

struct DiscountModel {
    QString DiscountID;
    QString Name;
    QString percent;
    QString LastUpdated;
    QString TimesUpdated;
    QString NumStudents;

};


QStandardItemModel* getReceipts_DiscountModel();


//***************************      MODEL FOR Schule/Disciplines       ***************************



struct SchuleDisciplineModel {
    QString ID;
    QString Name;
    QString NumStudents;
    QString ActiveStudents;
};


QStandardItemModel* getSchuleDisciplines();


//***************************      MODEL FOR Sprache/ManageDiplomas       ***************************



struct DiplomaModel {
  QString DiploID;
  QString Name;
  QString Institut;
  QString NumTeachers;
  QString NumStudents;
  QString SuccessRate; // success final exam rate :)
  QString SuccessGrade; //avg of pass grades
};

QStandardItemModel* getSpracheDiplomas();


//***************************      MODEL FOR Receipts/ManageSalaries       ***************************


struct EchelonModel {
  QString EchelID;
  QString Xp;
  QString NumTeachers;
};


QStandardItemModel* getReceiptEchelons();


//***************************      MODEL FOR Receipts/BaseWages       ***************************


struct BaseWagesModel {
    QString EchelID;
    QString Xp;
    QString Dat;
    QString Wage;
};


QStandardItemModel* getReceiptBaseWages();


//***************************      MODEL FOR General/ManageCourses       ***************************



struct ManageCourseTable {
    int CourseID;
    QString CourseName;
    QString DepName;
    QString NumTeachers;
    QString NumStudents;
    QString NumGroups;
    QString NumOpenRequests;
    QString PaySchemes; // if  payschemes  exist for all echelons this is equal to Yes
    QString FeeUpdate ; // last time the fee was updated
};

QStandardItemModel* getGeneralManageCourses();


//***************************      MODEL FOR General/ManageFees       ***************************




struct FeeSchuleTable {
    QString CourseID;
    QString Name;
    QString LastUpdate;
    QString Fee;
    QString Changes;
    QString Profit; //how much money have we won from that course
    QString Debt; // how much money the students have not paid us
};

QStandardItemModel* getGeneralManageFees();






} //END OF NAMESPACE
