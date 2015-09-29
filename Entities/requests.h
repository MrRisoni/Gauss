#ifndef REQUESTS_H
#define REQUESTS_H

#include "courses.h"
#include "members.h"
#include <QDate>


class Requests
{
public:
    Requests();


    Courses getC() const;
    void setC(const Courses &value);

    int getCourseID() const;
    void setCourseID(int value);

    int getStudentID() const;
    void setStudentID(int value);

    Members getStudent() const;
    void setStudent(const Members &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    QString getComments() const;
    void setComments(const QString &value);

private:
    Courses C;
    int CourseID;
    int StudentID;
    Members student;
    QDate dat;
    QString comments;

};

#endif // REQUESTS_H
