#include "departments.h"

Departments::Departments()
{

}

Departments::~Departments()
{

}
QString Departments::getDepName() const
{
    return DepName;
}

void Departments::setDepName(const QString &value)
{
    DepName = value;
}
int Departments::getDepID() const
{
    return DepID;
}

void Departments::setDepID(int value)
{
    DepID = value;
}



