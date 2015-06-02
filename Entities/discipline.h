#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <QString>

class Discipline
{
public:
    Discipline();
    int getDiscID() const;
    void setDiscID(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int DiscID;
    QString Name;
};

#endif // DISCIPLINE_H
