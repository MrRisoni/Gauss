#include "payments.h"

Payments::Payments()
{

}

Payments::~Payments()
{

}



QDate Payments::getDat() const
{
    return dat;
}

void Payments::setDat(const QDate &value)
{
    dat = value;
}
float Payments::getMoney() const
{
    return Money;
}

void Payments::setMoney(float value)
{
    Money = value;
}
QString Payments::getPayType() const
{
    return PayType;
}

void Payments::setPayType(const QString &value)
{
    PayType = value;
}
QString Payments::getTeacherName() const
{
    return TeacherName;
}

void Payments::setTeacherName(const QString &value)
{
    TeacherName = value;
}






