#include "wagesschule.h"

WagesSchule::WagesSchule()
{

}

WagesSchule::~WagesSchule()
{

}
float WagesSchule::getWage() const
{
    return Wage;
}

void WagesSchule::setWage(float value)
{
    Wage = value;
}
Courses WagesSchule::getC() const
{
    return C;
}

void WagesSchule::setC(const Courses &value)
{
    C = value;
}
int WagesSchule::getCourseID() const
{
    return CourseID;
}

void WagesSchule::setCourseID(int value)
{
    CourseID = value;
}
QDate WagesSchule::getDat() const
{
    return dat;
}

void WagesSchule::setDat(const QDate &value)
{
    dat = value;
}
Echelon WagesSchule::getEchel() const
{
    return Echel;
}

void WagesSchule::setEchel(const Echelon &value)
{
    Echel = value;
}
int WagesSchule::getEchelID() const
{
    return EchelID;
}

void WagesSchule::setEchelID(int value)
{
    EchelID = value;
}







