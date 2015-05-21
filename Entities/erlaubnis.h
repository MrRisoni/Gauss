#ifndef ERLAUBNIS_H
#define ERLAUBNIS_H


#include <QDate>


class Erlaubnis
{
public:
    Erlaubnis();
    ~Erlaubnis();


    QDate getStartDate() const;
    void setStartDate(const QDate &value);

    QDate getEndDate() const;
    void setEndDate(const QDate &value);

    int getDaysLeft() const;
    void setDaysLeft(int value);

private:
    int TeacherID;
    QDate StartDate;
    QDate EndDate;
    int DaysLeft;
};

#endif // ERLAUBNIS_H
