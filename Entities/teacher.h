#ifndef TEACHER_H
#define TEACHER_H

#include "courses.h"
#include "basewages.h"
#include "unavailable.h"
#include "kassen.h"

class Teacher //: public Members
{
public:
    Teacher();
    ~Teacher();

private:
    BaseWages base_wages;
    QList<Courses> CanTeach;
    int XpYears;
    QByteArray photo;
    Kassen Versichern;
    QList<Unavailable> UnAvailability;

    QDate EndOfContract;





};

#endif // TEACHER_H
