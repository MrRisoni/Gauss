#include "days.h"

Days::Days()
{

}

Days::~Days()
{

}
QString Days::getName() const
{
    return Name;
}

void Days::setName(const QString &value)
{
    Name = value;
}
int Days::getDayID() const
{
    return DayID;
}

void Days::setDayID(int value)
{
    DayID = value;
}



