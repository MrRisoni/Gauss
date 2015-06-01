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



    int getRoomID() const;
    void setRoomID(int value);

    QString getRoom() const;
    void setRoom(const QString &value);

    float getDiarkeia() const;
    void setDiarkeia(float value);

    float getDur() const;
    void setDur(float value);

    int getStartHourID() const;
    void setStartHourID(int value);

private:
    int PermaID;
    int DayID;
    int StartHourID;
    float Dur;
    int RoomID;
    float Diarkeia;
    QString Room;
};

#endif // PERMATIMES_H
