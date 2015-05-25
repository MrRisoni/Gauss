#ifndef RECEIPT_H
#define RECEIPT_H

#include <QDate>

class Receipt
{
public:
    Receipt();
private:
    int ReceiptID;
    QDate dat;
    int MemberID;
    float Amount;
    short ReceiptTypeID;
};

#endif // RECEIPT_H
