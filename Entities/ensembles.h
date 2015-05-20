#ifndef ENSEMBLES_H
#define ENSEMBLES_H

#include "student.h"

class Ensembles
{
public:
    Ensembles();
    ~Ensembles();
    int getEnsembleID() const;
    void setEnsembleID(int value);

    QList<Student> getMeli() const;
    void setMeli(const QList<Student> &value);

private:
    int EnsembleID;
    QList<Student> meli;
};

#endif // ENSEMBLES_H
