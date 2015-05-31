#ifndef ROOMITEMDELEGATE_H
#define ROOMITEMDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QComboBox>
#include <QFontComboBox>
#include <QSize>

#include <QStyledItemDelegate>

//https://www.youtube.com/watch?v=QJj3sgT5quY



class RoomItemDelegate : public QStyledItemDelegate
{
 Q_OBJECT

public:
 explicit RoomItemDelegate(QObject *parent = 0);
 ~RoomItemDelegate();

protected:
    virtual QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    virtual void setEditorData ( QWidget *editor, const QModelIndex &index ) const;
    virtual void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};
#endif // ROOMITEMDELEGATE_H
