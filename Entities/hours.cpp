#include "hours.h"

Hours::Hours()
{

}

Hours::~Hours()
{

}
int Hours::getHourID() const
{
    return HourID;
}

void Hours::setHourID(int value)
{
    HourID = value;
}
QString Hours::getName() const
{
    return Name;
}

void Hours::setName(const QString &value)
{
    Name = value;
}



