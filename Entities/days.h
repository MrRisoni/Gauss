#ifndef DAYS_H
#define DAYS_H

#include <QString>

class Days
{
public:
    Days();
    ~Days();
    QString getName() const;
    void setName(const QString &value);

private:
    int DayID;
    QString Name;
};

#endif // DAYS_H
