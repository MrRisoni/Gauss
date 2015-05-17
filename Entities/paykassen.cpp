#include "paykassen.h"

PayKassen::PayKassen()
{

}

PayKassen::~PayKassen()
{

}
float PayKassen::getWages() const
{
    return wages;
}

void PayKassen::setWages(float value)
{
    wages = value;
}
QDate PayKassen::getDat() const
{
    return Dat;
}

void PayKassen::setDat(const QDate &value)
{
    Dat = value;
}
int PayKassen::getTeacherID() const
{
    return TeacherID;
}

void PayKassen::setTeacherID(int value)
{
    TeacherID = value;
}




