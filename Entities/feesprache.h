#ifndef FEESPRACHE_H
#define FEESPRACHE_H

#include "diplomas.h"


class FeeSprache
{
public:
    FeeSprache();
    ~FeeSprache();
    Diplomas getDiplo() const;
    void setDiplo(const Diplomas &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;
    void setFee(float value);

private:
    Diplomas diplo;
    QDate dat;
    float fee;

};

#endif // FEESPRACHE_H
