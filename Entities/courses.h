#ifndef COURSES_H
#define COURSES_H

#include <QString>
#include "departments.h"
#include "schwierigkeit.h"



class Courses
{
public:
    Courses();
    ~Courses();


    int getCourseID() const;
    void setCourseID(int value);

    int getDepID() const;
    void setDepID(int value);

    QString getName() const;
    void setName(const QString &value);

    int getSchwerID() const;
    void setSchwerID(int value);

    Departments getD() const;
    void setD(const Departments &value);

    Schwierigkeit getS() const;
    void setS(const Schwierigkeit &value);

private:
    int CourseID;
    int DepID;
    QString Name;
    int SchwerID;

    Departments D;
    Schwierigkeit S;
};

#endif // COURSES_H
