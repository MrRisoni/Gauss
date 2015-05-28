#ifndef TEACHECHEL_H
#define TEACHECHEL_H

#include <QDate>


class TeachEchel
{
public:
    TeachEchel();
    int getTeacherID() const;
    void setTeacherID(int value);

    int getEchelID() const;
    void setEchelID(int value);

    QDate getDat() const;
    void setDat(const QDate &value);

private:
    int TeacherID;
    int EchelID;
    QDate dat;
};

#endif // TEACHECHEL_H
