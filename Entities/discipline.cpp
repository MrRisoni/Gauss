#include "discipline.h"

Discipline::Discipline()
{

}
int Discipline::getDiscID() const
{
    return DiscID;
}

void Discipline::setDiscID(int value)
{
    DiscID = value;
}
QString Discipline::getName() const
{
    return Name;
}

void Discipline::setName(const QString &value)
{
    Name = value;
}



