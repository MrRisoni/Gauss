#ifndef ERLAUBNIS_H
#define ERLAUBNIS_H


#include "teacher.h"

class Erlaubnis
{
public:
    Erlaubnis();
    ~Erlaubnis();
    Teacher getT() const;
    void setT(const Teacher &value);

    QDate getStartDate() const;
    void setStartDate(const QDate &value);

    QDate getEndDate() const;
    void setEndDate(const QDate &value);

    int getDaysLeft() const;
    void setDaysLeft(int value);

private:
    Teacher T;
    QDate StartDate;
    QDate EndDate;
    int DaysLeft;
};

#endif // ERLAUBNIS_H
