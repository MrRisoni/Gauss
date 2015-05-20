#include "ensembles.h"

Ensembles::Ensembles()
{

}

Ensembles::~Ensembles()
{

}
int Ensembles::getEnsembleID() const
{
    return EnsembleID;
}

void Ensembles::setEnsembleID(int value)
{
    EnsembleID = value;
}
QList<Student> Ensembles::getMeli() const
{
    return meli;
}

void Ensembles::setMeli(const QList<Student> &value)
{
    meli = value;
}



