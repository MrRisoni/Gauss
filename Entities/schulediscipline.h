#ifndef SCHULEDISCIPLINE_H
#define SCHULEDISCIPLINE_H

#include <QString>

class SchuleDiscipline
{
public:
    SchuleDiscipline();
    int getSchuleDiscID() const;
    void setSchuleDiscID(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int SchuleDiscID;
    QString Name;
};

#endif // SCHULEDISCIPLINE_H
