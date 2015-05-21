#ifndef VERSICHERUNG_H
#define VERSICHERUNG_H


#include <QDate>
#include "teacher.h"
#include "kassen.h"


class Versicherung
{
public:
    Versicherung();
    ~Versicherung();
    float getAgreement() const;
    void setAgreement(float value);

    QDate getDat() const;
    void setDat(const QDate &value);

private:
    Teacher T;
    Kassen K;
    float Agreement; //how much money do we agree to pay for insurance
    QDate dat; //day of arrangement

};

#endif // VERSICHERUNG_H
