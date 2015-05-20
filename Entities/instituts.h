#ifndef INSTITUTS_H
#define INSTITUTS_H

#include "diplomas.h"

class Instituts
{
public:
    Instituts();
    ~Instituts();
private:
    int InstitID;
    QString Name;
    QList<Diplomas> diplos;
};

#endif // INSTITUTS_H
