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
    (void ) option;
    (void ) index;
    QComboBox *bx= new QComboBox(parent);
    bx->addItem("C2");
    bx->addItem("C1");
    return bx;

    // return new QComboBox(parent) ;

}

void ObjektDelegate::setEditorData ( QWidget *editor, const QModelIndex &index ) const
{

  QComboBox *box = static_cast<QComboBox*> (editor);
  box->setCurrentText(index.data().toString());

}

void ObjektDelegate::setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
   QComboBox *cb = qobject_cast<QComboBox*>(editor);
   model->setData(index,cb->currentText());

}



void ObjektDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {

    editor->setGeometry(option.rect);
    (void) index;

}

