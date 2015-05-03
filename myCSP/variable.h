#ifndef VARIABLE_H
#define VARIABLE_H
#include <QList>
#include <QString>
#include "point.h"

class Variable
{
public:
    Variable();

    int VarID;
    int ClassID;

    QString Name;
    //the initial domain variables
    QList<Point*> InitDomain;


    Point* CurrentDomain;

    QList<int> AllowedValues ; // a list of values associated with InitDomain
    //has length equal to InitDomain length 1 means value is allowed 0 is not
    void ResetDomain();


};

#endif // VARIABLE_H
