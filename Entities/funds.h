#ifndef FUNDS_H
#define FUNDS_H

#include "student.h"

class Funds
{
public:
    Funds();
    ~Funds();

    Student getStud() const;
    void setStud(const Student &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;

    void setFee(float value);

private:
    Student  stud;
    QDate dat;
    float fee;

};

#endif // FUNDS_H
