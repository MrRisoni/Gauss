#ifndef OBJEKTDELEGATE_H
#define OBJEKTDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QComboBox>
#include <QSize>

#include <QStyledItemDelegate>

class ObjektDelegate : public QStyledItemDelegate
{
 Q_OBJECT

public:
 ObjektDelegate(QObject *parent = 0);
 ~ObjektDelegate();

virtual QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
 virtual void setEditorData ( QWidget *editor, const QModelIndex &index ) const;
 virtual void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;

};

#endif // OBJEKTDELEGATE_H
