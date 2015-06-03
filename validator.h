#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QList>
#include <QLineEdit>
class Validator
{
public:
    Validator();


 bool ValidateFields(QList<QLineEdit*> widgets);


};

#endif // VALIDATOR_H
