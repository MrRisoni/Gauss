#include "teachechel.h"

TeachEchel::TeachEchel()
{

}
int TeachEchel::getTeacherID() const
{
    return TeacherID;
}

void TeachEchel::setTeacherID(int value)
{
    TeacherID = value;
}
int TeachEchel::getEchelID() const
{
    return EchelID;
}

void TeachEchel::setEchelID(int value)
{
    EchelID = value;
}
QDate TeachEchel::getDat() const
{
    return dat;
}

void TeachEchel::setDat(const QDate &value)
{
    dat = value;
}




