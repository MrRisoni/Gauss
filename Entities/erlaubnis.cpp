#include "erlaubnis.h"

Erlaubnis::Erlaubnis()
{

}

Erlaubnis::~Erlaubnis()
{

}
Teacher Erlaubnis::getT() const
{
    return T;
}

void Erlaubnis::setT(const Teacher &value)
{
    T = value;
}
QDate Erlaubnis::getStartDate() const
{
    return StartDate;
}

void Erlaubnis::setStartDate(const QDate &value)
{
    StartDate = value;
}
QDate Erlaubnis::getEndDate() const
{
    return EndDate;
}

void Erlaubnis::setEndDate(const QDate &value)
{
    EndDate = value;
}
int Erlaubnis::getDaysLeft() const
{
    return DaysLeft;
}

void Erlaubnis::setDaysLeft(int value)
{
    DaysLeft = value;
}





