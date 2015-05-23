#include "objektdelegate.h"

ObjektDelegate::ObjektDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}


//https://wiki.qt.io/Combo_Boxes_in_Item_Views

ObjektDelegate::~ObjektDelegate()
{
}


QWidget* ObjektDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    // ComboBox ony in column 2
    if(index.column() != 1)
        return QStyledItemDelegate::createEditor(parent, option, index);

}

void ObjektDelegate::setEditorData ( QWidget *editor, const QModelIndex &index ) const
{
    if(QComboBox *cb = qobject_cast<QComboBox*>(editor)) {
        // get the index of the text in the combobox that matches the current value of the itenm
        QString currentText = index.data(Qt::EditRole).toString();
        int cbIndex = cb->findText(currentText);
        // if it is valid, adjust the combobox



    }
}

void ObjektDelegate::setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
    if(QComboBox *cb = qobject_cast<QComboBox*>(editor))
        // save the current text of the combo box as the current value of the item
        model->setData(index, cb->currentText(), Qt::EditRole);
    else
        QStyledItemDelegate::setModelData(editor, model, index);
}
