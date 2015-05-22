#ifndef TABLESTRUCTS
#define TABLESTRUCTS

#include <QString>
#include <QDate>
#include "schwierigkeit.h"


// i think it is wise to create struct for each TableModel


struct ManageCourseTable {
    int CourseID;
    QString CourseName;
    QString DepName;
    Schwierigkeit Schwer;
    int NumTeachers;
    int NumStudents;
    int NumGroups;
    int NumOpenRequests;
    QString PaySchemes; // if  payschemes  exist for all echelons this is equal to Yes
    QString FeeUpdate ; // last time the fee was updated
};


struct FeeSchuleTable {
    QString CourseID;
    QString Name;
    QString LastUpdate;
    QString Fee;
    QString Changes;
    QString Profit; //how much money have we won from that course
    QString Debt; // how much money the students have not paid us
};



#endif // TABLESTRUCTS


