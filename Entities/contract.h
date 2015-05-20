#ifndef CONTRACT_H
#define CONTRACT_H

#include "teacher.h"

class Contract
{
public:
    Contract();
    ~Contract();
    Teacher getT() const;
    void setT(const Teacher &value);

    QDate getEnde() const;
    void setEnde(const QDate &value);

private:
    Teacher T;
    QDate ende;
};

#endif // CONTRACT_H
