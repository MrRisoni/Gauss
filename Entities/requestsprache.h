#ifndef REQUESTSPRACHE_H
#define REQUESTSPRACHE_H

#include "student.h"
#include "diplomas.h"

class RequestSprache
{
public:
    RequestSprache();
    ~RequestSprache();

private:
    Diplomas diplo;
    int DiplomaID;
    int StudentID;
    Student student;
    QDate dat;
    QString comments;
};

#endif // REQUESTSPRACHE_H
