#ifndef TABLESTRUCTS
#define TABLESTRUCTS

#include <QString>
#include <QDate>
#include "schwierigkeit.h"
#include <QStringList>




struct TimeTableHeaders {
    //horizontal is date
    //vertical is hour
    QStringList horHeaders;
    QStringList verHeaders;
};



//---------------------------------------------------------------



struct SchuleTeacher {
    QString ProfID;
    QString Name;
    QString Monthy_Base_Salary;
    QString Groups;
    QString Hours_for_this_lesson;
    QString Current_Groups;
    QString End_of_Contract;
    QString Mobile;
};


struct SchuleTeacherMVC {
        QStringList SchuleTeacherViewHeaders;
        QList<SchuleTeacher> SchuleTeacherModel;
};


//AddInstitutDialog
struct InstitutModel {
  QString InstitID;
  QString InsName;
  QString NumDiplomas;
  QString NumTeachers;
  QString NumStudents;
  QString NumGroups;
  QString DiplomaTitles; // a list of available diplomas join by EOL!!!!

  
};





struct AddInstitutDialogMVC  {
  QStringList headers;
  QList<InstitutModel> InstitutView;
};
// End AddInstitutDialog


//AddLanguageDialog
struct LanguageModel {
  QString LangID;
  QString Name;
  QString NumInstituts;
  QString NumDiplomas;
  QString NumTeachers;
  QString NumStudents;
  QString SuccessRate; // total success final exam rate for all diplomas :)
  QList<QString> Diplomas; // a list of available diplomas!!!!
  
};

struct AddLanguageDialogMVC {
  QStringList headers;
  QList<LanguageModel> LanguageView;
};




struct UniTeacher {
    QString ProfID;
    QString Name;
    QString Monthy_Base_Salary;
    QString Groups;
    QString Hours_for_this_lesson;
    QString Current_Groups;
    QString End_of_Contract;
    QString Mobile;
};


struct UniTeacherMVC {
        QStringList headers;
        QList<UniTeacher> UniTeacherView;
};



struct SpracheTeacher {
    QString ProfID;
    QString Name;
    QString Monthy_Base_Salary;
    QString Groups;
    QString Hours_for_this_lesson;
    QString Current_Groups;
    QString End_of_Contract;
    QString Mobile;
};


struct SpracheTeacherMVC {
        QStringList headers;
        QList<SpracheTeacher> SpracheTeacherView;
};

//Kassen KassenDialog
struct KasseModel {
  QString ID;
  QString Name;
  QString NumTeachers;
  QString Pays; // how much money have we payed in total
  QString Debt; //how much money do we owe :(

};

struct KassenMVC {
  QStringList headers;
  QList<KasseModel> KasseView;
};

//End KassenDialog


//ManageDepsDialog
struct ManageDepsModel {
  QString DepID;
  QString Name;
  QString NumTeachers; // how many teacher can teach at least one course from that Department
  QString NumCourses;
  QString Groups;
  QString Students;
  
};

struct ManageDepsDialogMVC {
  QStringList headers;
  QList<ManageDepsModel> ManageDepsView;
  
};
//End ManageDepsDialog


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











#endif // TABLESTRUCTS


