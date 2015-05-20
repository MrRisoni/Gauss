#ifndef FEEUNI_H
#define FEEUNI_H

#include "courses.h"

class FeeUni
{
public:
    FeeUni();
    ~FeeUni();

    Courses getC() const;
    void setC(const Courses &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;
    void setFee(float value);

private:
    Courses C;
    QDate dat;
    float fee;

};

#endif // FEEUNI_H
