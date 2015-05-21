#ifndef FEEUNI_H
#define FEEUNI_H

#include <QDate>

class FeeUni
{
public:
    FeeUni();
    ~FeeUni();



    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;
    void setFee(float value);

private:
    int CourseID;
    QDate dat;
    float fee;

};

#endif // FEEUNI_H
