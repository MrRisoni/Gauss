#ifndef REQUESTSPRACHE_H
#define REQUESTSPRACHE_H


#include <QDate>
#include <QString>


class RequestSprache
{
public:
    RequestSprache();
    ~RequestSprache();

private:
    int diploID;
    int DiplomaID;
    int StudentID;
    int studentID;
    QDate dat;
    QString comments;
};

#endif // REQUESTSPRACHE_H
