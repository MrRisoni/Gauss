#ifndef TABLESTRUCTS
#define TABLESTRUCTS

#include <QString>
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
};

#endif // TABLESTRUCTS


