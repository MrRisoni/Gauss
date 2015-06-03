#ifndef HISTORY_H
#define HISTORY_H

#include <QDate>
#include <QString>
#include "rooms.h"

class History
{
public:
    History();
    ~History();
    int getHistID() const;
    void setHistID(int value);

    int getGroupID() const;
    void setGroupID(int value);

    QDate getDat() const;
    void setDat(const QDate &value);

    QString getHour() const;
    void setHour(const QString &value);

    float getDuration() const;
    void setDuration(float value);

    int getRoomID() const;
    void setRoomID(int value);

    Rooms getR() const;
    void setR(const Rooms &value);

private:
    int HistID;
    int GroupID;
    QDate dat;
    QString Hour;
    float Duration;
    int RoomID;
    Rooms R;
    bool Active;
    short StartHour;


};

#endif // HISTORY_H
