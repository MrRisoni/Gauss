#include "examsprache.h"

ExamSprache::ExamSprache()
{

}

ExamSprache::~ExamSprache()
{

}


QDate ExamSprache::getDat() const
{
    return dat;
}

void ExamSprache::setDat(const QDate &value)
{
    dat = value;
}



float ExamSprache::getGrade() const
{
    return grade;
}

void ExamSprache::setGrade(float value)
{
    grade = value;
}





