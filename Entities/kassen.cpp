#include "kassen.h"

Kassen::Kassen()
{

}

Kassen::~Kassen()
{

}
int Kassen::getKasseID() const
{
    return KasseID;
}

void Kassen::setKasseID(int value)
{
    KasseID = value;
}
QString Kassen::getName() const
{
    return Name;
}

void Kassen::setName(const QString &value)
{
    Name = value;
}



