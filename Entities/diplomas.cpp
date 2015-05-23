#include "diplomas.h"

Diplomas::Diplomas()
{

}

Diplomas::~Diplomas()
{

}




int Diplomas::getActive() const
{
    return Active;
}

void Diplomas::setActive(int value)
{
    Active = value;
}
QString Diplomas::getName() const
{
    return Name;
}

void Diplomas::setName(const QString &value)
{
    Name = value;
}
QString Diplomas::getLanguage() const
{
    return Language;
}

void Diplomas::setLanguage(const QString &value)
{
    Language = value;
}
QString Diplomas::getInstitutName() const
{
    return InstitutName;
}

void Diplomas::setInstitutName(const QString &value)
{
    InstitutName = value;
}
QString Diplomas::getSchwerID() const
{
    return SchwerID;
}

void Diplomas::setSchwerID(const QString &value)
{
    SchwerID = value;
}








