#ifndef TABLESTRUCTS
#define TABLESTRUCTS

#include <QString>
#include <QDate>
#include "schwierigkeit.h"
#include <QStringList>

// i think it is wise to create struct for each TableModel



struct TimeTableHeaders {
    //horizontal is date
    //vertical is hour
    QStringList horHeaders;
    QStringList verHeaders;
};

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


// it may be wise to return the string headers for the table as well...
//---------------------------------------------------------------
struct FeeSchuleMVC {
     QStringList FeeViewHeaders;
     QList<FeeSchuleTable> FeeModel;
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
//End AddLanguageDialog


//AddNewSchwerDialog
struct SchwerModel {
  QString SchwerID;
  QString NumCourses;
  QString red;
  QString green;
  QString blue;
};

struct AddSchwerDialogMVC {
  QStringList headers;
  QList<SchwerModel> SchwerView;  
};
//End AddNewSchwerDialog



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


struct EchelonModel {
  QString EchelID;
  QString Xp;
  QString NumTeachers;
};


struct EchelonMVC {
  QStringList headers;
  QList<EchelonModel> EchelonView;
};



struct DiplomaModel {
  QString DiploID;
  QString Name;
  QString Institut;
  QString NumTeachers;
  QString NumStudents;
  QString SuccessRate; // success final exam rate :)
  QString SuccessGrade; //avg of pass grades
  QString red;
  QString green;
  QString blue;
};

struct DiplomaModelMVC {
  QStringList headers;
  QList<DiplomaModel> DiplomaView;
};


struct GroupsDialogModel {
    QString GroupID;
    QString CourseName;
    QString TeacherName;
    QString NumStudents;
    QList<QString> Students;
    QString created;
    QString HoursPerWeek;
    QString Debts;//how much do we owe the professor
    QString Profits ;// how much money have we earned from the fees
    QString Schulden; // how much money must be payed by the students
    QString AverageStuffe; // in schule mündlich tests take place every now and then
    QString EndsOn; //end of unterricht
    QString TotHours; // total Unterrichtstuden
};


struct GroupsDialogMVC {
    QStringList headers;
    QList<GroupsDialogModel> group_model;
};



// ManageDiscountModel

struct DiscountModel {
    QString DiscountID;
    QString Name;
    QString percent;
    QString LastUpdated;
    QString TimesUpdated;
    QString NumStudents;

};

struct DiscountDialogMVC {
    QStringList headers;
    QList<DiplomaModel> disc_model;
};




struct SchuleDisciplineModel {
    QString ID;
    QString Name;
    QString NumStudents;
    QString ActiveStudents;
};


struct SchuleDisciplineMVC {
    QStringList headers;
    QList<SchuleDisciplineModel> schuledisc_model;
};







#endif // TABLESTRUCTS


