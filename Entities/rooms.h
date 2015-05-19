#ifndef ROOMS_H
#define ROOMS_H

#include <QString>


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

private:
    int RoomID;
    int BuildingID;
    QString Name;
    int Capacity;
};

#endif // ROOMS_H
