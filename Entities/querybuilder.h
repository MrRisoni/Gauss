#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QSqlQuery>
#include <QStringList>
#include <QSqlRecord>
#include <QVariant>
#include <QString>

class QueryBuilder
{
public:
    QueryBuilder();

    QString getSql() const;


    int executeInsert();
    void execUpdate();
    QList<QStringList> execSelect();
    void setQuery(QString sql);

    void addParameter(QString param, QString val);


private:
    QString sql;
    QSqlQuery qry;







};

#endif // QUERYBUILDER_H
