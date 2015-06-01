#ifndef ENSEMBLES_H
#define ENSEMBLES_H


#include <QList>
#include <QDate>

class Ensembles
{
public:
    Ensembles();
    ~Ensembles();
    int getEnsembleID() const;
    void setEnsembleID(int value);


    QList<int> getMeliID() const;
    void setMeliID(const QList<int> &value);

private:
    int EnsembleID;
    QList<int> meliID;
    QList<QDate> DateAdded; // we can add new members to group this will increase the complexity of the fee
    //calculation algorithm
};

#endif // ENSEMBLES_H
