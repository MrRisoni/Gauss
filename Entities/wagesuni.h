#ifndef WAGESUNI_H
#define WAGESUNI_H


#include "echelon.h"
#include "courses.h"
#include <QDate>

class WagesUni
{
public:
    WagesUni();
    ~WagesUni();

    int getTeachers() const;
    void setTeachers(int value);

private:
    int Teachers;
    int EchelID;
    Echelon Echel;
    QDate dat;
    int CourseID;
    Courses C;
    float Wage;
};

#endif // WAGESUNI_H
