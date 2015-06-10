#include "funds.h"

Funds::Funds()
{

}

Funds::~Funds()
{

}

QString Funds::getGroupID() const
{
    return GroupID;
}

void Funds::setGroupID(QString value)
{
    GroupID = value;
}
float Funds::getAmount() const
{
    return amount;
}

void Funds::setAmount(float value)
{
    amount = value;
}
QString Funds::getADT() const
{
    return ADT;
}

void Funds::setADT(const QString &value)
{
    ADT = value;
}





