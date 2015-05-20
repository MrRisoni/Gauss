#ifndef REQUESTUNI_H
#define REQUESTUNI_H

#include "courses.h"
#include "student.h"

class RequestUni
{
public:
    RequestUni();
    ~RequestUni();

private:
    Courses C;
    int CourseID;
    int StudentID;
    Student student;
    QDate dat;
    QString comments;

};

#endif // REQUESTUNI_H
