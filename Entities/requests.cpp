#include "requests.h"

Requests::Requests()
{

}
Courses Requests::getC() const
{
    return C;
}

void Requests::setC(const Courses &value)
{
    C = value;
}
int Requests::getCourseID() const
{
    return CourseID;
}

void Requests::setCourseID(int value)
{
    CourseID = value;
}
int Requests::getStudentID() const
{
    return StudentID;
}

void Requests::setStudentID(int value)
{
    StudentID = value;
}
Members Requests::getStudent() const
{
    return student;
}

void Requests::setStudent(const Members &value)
{
    student = value;
}
QDate Requests::getDat() const
{
    return dat;
}

void Requests::setDat(const QDate &value)
{
    dat = value;
}
QString Requests::getComments() const
{
    return comments;
}

void Requests::setComments(const QString &value)
{
    comments = value;
}







