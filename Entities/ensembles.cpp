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
QList<int> Ensembles::getMeliID() const
{
    return meliID;
}

void Ensembles::setMeliID(const QList<int> &value)
{
    meliID = value;
}





