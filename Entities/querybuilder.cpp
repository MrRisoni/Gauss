#include "querybuilder.h"

QueryBuilder::QueryBuilder()
{

}

void QueryBuilder::setQuery(QString sql)
{
    this->sql = sql;
    this->qry.prepare(this->sql);
}


void QueryBuilder::addParameter(QString param, QString val)
{
    this->qry.bindValue(param, val);
}


QList<QStringList> QueryBuilder::execSelect()
{
    QList<QStringList> l;


    if (!this->qry.exec()) {
            throw 10;
    }
    while (this->qry.next())
    {
        QStringList sl;
        //get columnts
        for (int w=0;w<this->qry.record().count();w++)
        {
           sl.append(this->qry.value(w).toString());

        }


       l.append(sl);


    }

    this->qry.finish();
    return l;
}
