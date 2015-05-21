#ifndef FEESPRACHE_H
#define FEESPRACHE_H


#include <QDate>

class FeeSprache
{
public:
    FeeSprache();
    ~FeeSprache();

    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;
    void setFee(float value);

private:
    int diploID;
    QDate dat;
    float fee;

};

#endif // FEESPRACHE_H
