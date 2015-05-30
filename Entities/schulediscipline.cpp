#include "schulediscipline.h"

SchuleDiscipline::SchuleDiscipline()
{

}
int SchuleDiscipline::getSchuleDiscID() const
{
    return SchuleDiscID;
}

void SchuleDiscipline::setSchuleDiscID(int value)
{
    SchuleDiscID = value;
}
QString SchuleDiscipline::getName() const
{
    return Name;
}

void SchuleDiscipline::setName(const QString &value)
{
    Name = value;
}



