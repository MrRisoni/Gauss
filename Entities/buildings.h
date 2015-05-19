#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <QString>

class Buildings
{
public:
    Buildings();
    ~Buildings();
    int getBuildingID() const;
    void setBuildingID(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int BuildingID;
    QString Name;
};

#endif // BUILDINGS_H
