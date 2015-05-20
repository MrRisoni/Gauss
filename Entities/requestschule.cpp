#include "requestschule.h"

RequestSchule::RequestSchule()
{

}

RequestSchule::~RequestSchule()
{

}
Courses RequestSchule::getC() const
{
    return C;
}

void RequestSchule::setC(const Courses &value)
{
    C = value;
}
int RequestSchule::getCourseID() const
{
    return CourseID;
}

void RequestSchule::setCourseID(int value)
{
    CourseID = value;
}
int RequestSchule::getStudentID() const
{
    return StudentID;
}

void RequestSchule::setStudentID(int value)
{
    StudentID = value;
}
Members RequestSchule::getStudent() const
{
    return student;
}

void RequestSchule::setStudent(const Members &value)
{
    student = value;
}
QDate RequestSchule::getDat() const
{
    return dat;
}

void RequestSchule::setDat(const QDate &value)
{
    dat = value;
}
QString RequestSchule::getComments() const
{
    return comments;
}

void RequestSchule::setComments(const QString &value)
{
    comments = value;
}







