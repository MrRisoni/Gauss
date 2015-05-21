#include "funds.h"

Funds::Funds()
{

}

Funds::~Funds()
{

}

QDate Funds::getDat() const
{
    return dat;
}

void Funds::setDat(const QDate &value)
{
    dat = value;
}
float Funds::getFee() const
{
    return fee;
}
void Funds::setFee(float value)
{
    fee = value;
}





