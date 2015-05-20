#include "examsprache.h"

ExamSprache::ExamSprache()
{

}

ExamSprache::~ExamSprache()
{

}
Student ExamSprache::getSt() const
{
    return st;
}

void ExamSprache::setSt(const Student &value)
{
    st = value;
}
QDate ExamSprache::getDat() const
{
    return dat;
}

void ExamSprache::setDat(const QDate &value)
{
    dat = value;
}
Diplomas ExamSprache::getD() const
{
    return D;
}

void ExamSprache::setD(const Diplomas &value)
{
    D = value;
}
float ExamSprache::getGrade() const
{
    return grade;
}

void ExamSprache::setGrade(float value)
{
    grade = value;
}





