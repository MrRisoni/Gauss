#include "absent.h"

Absent::Absent()
{

}

Absent::~Absent()
{

}
int Absent::getStudentID() const
{
    return StudentID;
}

void Absent::setStudentID(int value)
{
    StudentID = value;
}
Student Absent::getSt() const
{
    return st;
}

void Absent::setSt(const Student &value)
{
    st = value;
}
History Absent::getH() const
{
    return h;
}

void Absent::setH(const History &value)
{
    h = value;
}




