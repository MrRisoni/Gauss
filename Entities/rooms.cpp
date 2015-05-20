#include "rooms.h"

Rooms::Rooms()
{

}

Rooms::~Rooms()
{

}
int Rooms::getRoomID() const
{
    return RoomID;
}

void Rooms::setRoomID(int value)
{
    RoomID = value;
}
int Rooms::getBuildingID() const
{
    return BuildingID;
}

void Rooms::setBuildingID(int value)
{
    BuildingID = value;
}
QString Rooms::getName() const
{
    return Name;
}

void Rooms::setName(const QString &value)
{
    Name = value;
}
int Rooms::getCapacity() const
{
    return Capacity;
}

void Rooms::setCapacity(int value)
{
    Capacity = value;
}
Buildings Rooms::getB() const
{
    return b;
}

void Rooms::setB(const Buildings &value)
{
    b = value;
}






