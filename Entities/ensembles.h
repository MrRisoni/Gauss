#ifndef ENSEMBLES_H
#define ENSEMBLES_H


#include <QList>


class Ensembles
{
public:
    Ensembles();
    ~Ensembles();
    int getEnsembleID() const;
    void setEnsembleID(int value);


private:
    int EnsembleID;
    QList<int> meliID;
};

#endif // ENSEMBLES_H
