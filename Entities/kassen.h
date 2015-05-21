#ifndef KASSEN_H
#define KASSEN_H

#include <QString>

class Kassen
{
public:
    Kassen();
    ~Kassen();

    int getKasseID() const;
    void setKasseID(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int KasseID;
    QString Name;

};

#endif // KASSEN_H
