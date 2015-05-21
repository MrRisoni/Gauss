#include "groups.h"

Groups::Groups()
{

}

Groups::~Groups()
{

}
int Groups::getGroupID() const
{
    return GroupID;
}

void Groups::setGroupID(int value)
{
    GroupID = value;
}
QDate Groups::getStartDate() const
{
    return StartDate;
}

void Groups::setStartDate(const QDate &value)
{
    StartDate = value;
}
bool Groups::getActive() const
{
    return Active;
}

void Groups::setActive(bool value)
{
    Active = value;
}
int Groups::getEduType() const
{
    return EduType;
}

void Groups::setEduType(int value)
{
    EduType = value;
}





