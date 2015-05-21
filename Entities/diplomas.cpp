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





