#include "examschule.h"

ExamSchule::ExamSchule()
{

}

ExamSchule::~ExamSchule()
{

}
Student ExamSchule::getSt() const
{
    return st;
}

void ExamSchule::setSt(const Student &value)
{
    st = value;
}
QDate ExamSchule::getDat() const
{
    return dat;
}

void ExamSchule::setDat(const QDate &value)
{
    dat = value;
}
Courses ExamSchule::getC() const
{
    return C;
}

void ExamSchule::setC(const Courses &value)
{
    C = value;
}
float ExamSchule::getGrade() const
{
    return grade;
}

void ExamSchule::setGrade(float value)
{
    grade = value;
}





