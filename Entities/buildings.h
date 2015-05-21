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

    int getRoomsNum() const;
    void setRoomsNum(int value);

private:
    int BuildingID;
    QString Name;
    int RoomsNum;
};

#endif // BUILDINGS_H
