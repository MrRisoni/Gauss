#ifndef PERMATIMES_H
#define PERMATIMES_H


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

private:
    int PermaID;
    int DayID;
    int HourID;
    int RoomID;
};

#endif // PERMATIMES_H
