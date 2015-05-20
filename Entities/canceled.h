#ifndef CANCELED_H
#define CANCELED_H

#include "history.h"

class Canceled
{
public:
    Canceled();
    ~Canceled();
    History getAkyro() const;
    void setAkyro(const History &value);

private:
    History Akyro;
};

#endif // CANCELED_H
