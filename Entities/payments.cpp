#include "payments.h"

Payments::Payments()
{

}

Payments::~Payments()
{

}
Teacher Payments::getTeacher() const
{
    return teacher;
}

void Payments::setTeacher(const Teacher &value)
{
    teacher = value;
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





