#ifndef WAGES_H
#define WAGES_H
#include <QDate>


class Wages
{
public:
    Wages();
    int EchelID;
    int FachID;
    QDate dat;
    float Wage;
};

#endif // WAGES_H
