#ifndef PAYTYPE_H
#define PAYTYPE_H

#include <QString>

class PayType
{
public:
    PayType();
    QString getComment() const;
    void setComment(const QString &value);

private:
    int TypeID;
    QString Comment;
};

#endif // PAYTYPE_H
