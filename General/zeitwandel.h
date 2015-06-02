#ifndef ZEITWANDEL_H
#define ZEITWANDEL_H


class ZeitWandel
{
public:
    ZeitWandel();
    void populateSchuleTable();
private:
    void setSchuleHeaders(int TimeWin); //get days and dates from today until today + TimeWin

};

#endif // ZEITWANDEL_H
