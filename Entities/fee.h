#ifndef FEE_H
#define FEE_H

#include <QDate>


class Fee
{
public:
    Fee();

    QDate dat;
    int FachID;
    float fee;
};

#endif // FEE_H
