#ifndef REQUESTUNI_H
#define REQUESTUNI_H

#include <QDate>
#include <QString>

class RequestUni
{
public:
    RequestUni();
    ~RequestUni();

private:
    int CourseID;
    int studentID;
    QDate dat;
    QString comments;

};

#endif // REQUESTUNI_H
