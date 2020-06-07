#ifndef DELEGATE_H
#define DELEGATE_H
#include <QItemDelegate>
#include <QLineEdit>

class Delegate : public QItemDelegate
{
public:
       QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option,
                         const QModelIndex & index) const
       {
           QLineEdit *lineEdit = new QLineEdit(parent);
           // Set validator
           QIntValidator *validator = new QIntValidator(1, 1000, lineEdit);
           lineEdit->setValidator(new QRegExpValidator(QRegExp("^[1-9][0-9]?$|^100$"), lineEdit));
           return lineEdit;
       }
};
#endif // DELEGATE_H
