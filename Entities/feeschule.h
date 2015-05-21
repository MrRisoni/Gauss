#ifndef FEESCHULE_H
#define FEESCHULE_H

#include "courses.h"
#include <QDate>

class FeeSchule
{
public:
    FeeSchule();
    ~FeeSchule();

    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;
    void setFee(float value);

    Courses getC() const;
    void setC(const Courses &value);

private:
    Courses C;
    QDate dat;
    float fee;

};

#endif // FEESCHULE_H
