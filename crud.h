
#include "Entities/payments.h"
#include <QString>
#include <QList>
#include <QSqlQuery>
#include <QStringList>
#include <QDebug>
#include <QVariant>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>

namespace CRUD {



    QList<QString> getPayTypes();
    QList<QString> getGroupIDs(QString Name);
    void save(Payments p);
    void ShowSuccess();
    void ShowError(QSqlQuery q);



}  //END OF NAMESPACE
