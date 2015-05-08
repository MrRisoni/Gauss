#include "courses.h"

Courses::Courses()
{

}

Courses::~Courses()
{

}
int Courses::getCourseID() const
{
    return CourseID;
}

void Courses::setCourseID(int value)
{
    CourseID = value;
}
int Courses::getDepID() const
{
    return DepID;
}

void Courses::setDepID(int value)
{
    DepID = value;
}
QString Courses::getName() const
{
    return Name;
}

void Courses::setName(const QString &value)
{
    Name = value;
}
int Courses::getSchwerID() const
{
    return SchwerID;
}

void Courses::setSchwerID(int value)
{
    SchwerID = value;
}
Departments Courses::getD() const
{
    return D;
}

void Courses::setD(const Departments &value)
{
    D = value;
}
Schwierigkeit Courses::getS() const
{
    return S;
}

void Courses::setS(const Schwierigkeit &value)
{
    S = value;
}







