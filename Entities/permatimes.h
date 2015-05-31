#ifndef PERMATIMES_H
#define PERMATIMES_H


#include <QString>


class Permatimes
{
public:
    Permatimes();
    int getPermaID() const;
    void setPermaID(int value);

    int getDayID() const;
    void setDayID(int value);

    int getHourID() const;
    void setHourID(int value);

    int getRoomID() const;
    void setRoomID(int value);

    QString getRoom() const;
    void setRoom(const QString &value);

private:
    int PermaID;
    int DayID;
    int HourID;
    int RoomID;
    QString Room;
};

#endif // PERMATIMES_H
