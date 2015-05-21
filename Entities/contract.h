#ifndef CONTRACT_H
#define CONTRACT_H


#include <QDate>

class Contract
{
public:
    Contract();
    ~Contract();


private:
    int TeacherID;
    QDate ende;
};

#endif // CONTRACT_H
