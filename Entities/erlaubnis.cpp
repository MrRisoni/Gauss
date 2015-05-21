#include "erlaubnis.h"

Erlaubnis::Erlaubnis()
{

}

Erlaubnis::~Erlaubnis()
{

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





