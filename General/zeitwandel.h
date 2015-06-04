#ifndef ZEITWANDEL_H
#define ZEITWANDEL_H


#include <QStandardItemModel>
#include <QSqlQuery>
#include <QVariant>
#include <tuple>

struct Cell {
    int row;
    int col;
    int row_span;
};

class ZeitWandel
{
public:
    ZeitWandel();

//    returns a tuple {
//    -QStandardTableModel -
//    -and a list of structs { int row,int col,int rowSpan}
//    }

    std::tuple<QStandardItemModel*,QList<Cell>> getSchule();

private:
    void setSchuleHeaders(int TimeWin); //get days and dates from today until today + TimeWin
    QList<int> RoomIDs; // add here the room ids
    //the rooms will be shown in alphabetical order



};

#endif // ZEITWANDEL_H
