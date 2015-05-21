#ifndef WAGESSCHULE_H
#define WAGESSCHULE_H

#include "courses.h"
#include <QDate>
#include "echelon.h"

class WagesSchule
{
public:
    WagesSchule();
    ~WagesSchule();

    float getWage() const;
    void setWage(float value);

    Courses getC() const;
    void setC(const Courses &value);

    int getCourseID() const;
    void setCourseID(int value);

    QDate getDat() const;
    void setDat(const QDate &value);

    Echelon getEchel() const;
    void setEchel(const Echelon &value);

    int getEchelID() const;
    void setEchelID(int value);

    int getTeachers() const;
    void setTeachers(int value);

private:
    int EchelID;
    Echelon Echel;
    QDate dat;
    int CourseID;
    Courses C;
    float Wage;
    int Teachers;



};

#endif // WAGESSCHULE_H
