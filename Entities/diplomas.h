#ifndef DIPLOMAS_H
#define DIPLOMAS_H

#include <QString>


class Diplomas
{
public:
    Diplomas();
    ~Diplomas();



    int getActive() const;
    void setActive(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int langID;
    int Active;
    QString Name;

};

#endif // DIPLOMAS_H
