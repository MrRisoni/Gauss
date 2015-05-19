#ifndef VERSICHERUNG_H
#define VERSICHERUNG_H

#include "teacher.h"
#include "kassen.h"

class Versicherung
{
public:
    Versicherung();
    ~Versicherung();
private:
    Teacher T;
    Kassen K;

};

#endif // VERSICHERUNG_H
