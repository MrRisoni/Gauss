#ifndef PAYKASSEN_H
#define PAYKASSEN_H

#include <QDate>

class PayKassen
{
public:
    PayKassen();
    ~PayKassen();
    float getWages() const;
    void setWages(float value);

    QDate getDat() const;
    void setDat(const QDate &value);

    int getTeacherID() const;
    void setTeacherID(int value);

private:
    int TeacherID;
    QDate Dat;
    float wages;
};

#endif // PAYKASSEN_H
