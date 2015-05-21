#include "examschule.h"

ExamSchule::ExamSchule()
{

}

ExamSchule::~ExamSchule()
{

}


QDate ExamSchule::getDat() const
{
    return dat;
}

void ExamSchule::setDat(const QDate &value)
{
    dat = value;
}



float ExamSchule::getGrade() const
{
    return grade;
}

void ExamSchule::setGrade(float value)
{
    grade = value;
}





