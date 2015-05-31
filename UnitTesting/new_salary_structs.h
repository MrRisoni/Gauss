#ifndef NEW_SALARY_STRUCTS
#define NEW_SALARY_STRUCTS


#include <QDebug>
#include <QDate>
#include <QList>



struct EchelUpdate {
    int ID;
    //how many xp months do you have at that date
    int xp;
    QDate dat;

};

struct BaseWages {
    //how  much was the base wage for EchelID at that date
    int EchelID;
    QDate dat;
    float wage;

};





struct WageUni {
    //how much was the wage for EchelID and CourseID at that date
    int EchelID;
    int CourseID;
    QDate dat;
    float wage;
};

#endif // NEW_SALARY_STRUCTS

