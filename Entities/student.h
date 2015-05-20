#ifndef STUDENT_H
#define STUDENT_H

#include "diplomas.h"

class Student : public Members
{
public:
    Student();
private:
    QList<Groups> groupaki;
    QList<History> istoria;
    QList<Funds> didaktra;
};

#endif // STUDENT_H
