#ifndef INSTITUTS_H
#define INSTITUTS_H


#include <QString>
#include <QList>

class Instituts
{
public:
    Instituts();
    ~Instituts();



private:
    int InstitID;
    QString Name;
    QList<int> diploID;
};

#endif // INSTITUTS_H
