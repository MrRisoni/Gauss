#ifndef ROOMS_H
#define ROOMS_H

#include <QString>
#include "buildings.h"

class Rooms
{
public:
    Rooms();
    ~Rooms();
    int getRoomID() const;
    void setRoomID(int value);

    int getBuildingID() const;
    void setBuildingID(int value);

    QString getName() const;
    void setName(const QString &value);

    int getCapacity() const;
    void setCapacity(int value);

    Buildings getB() const;
    void setB(const Buildings &value);

private:
    int RoomID;
    int BuildingID;
    Buildings b;
    QString Name;
    int Capacity;
};

#endif // ROOMS_H
