#include "versicherung.h"

Versicherung::Versicherung()
{

}

Versicherung::~Versicherung()
{

}
float Versicherung::getAgreement() const
{
    return Agreement;
}

void Versicherung::setAgreement(float value)
{
    Agreement = value;
}
QDate Versicherung::getDat() const
{
    return dat;
}

void Versicherung::setDat(const QDate &value)
{
    dat = value;
}



