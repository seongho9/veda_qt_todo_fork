#ifndef TODOITEM_H
#define TODOITEM_H

#include <QFrame>
#include <vector>
namespace Ui {
class TodoItem;
}

class TodoItem : public QFrame
{
    Q_OBJECT

public:
    explicit TodoItem(QWidget *parent = nullptr);
    void setDueDate(QString DueDate);
    void setContent(QString Content);
    void LEDBlink();
    void VectorAdd();
    ~TodoItem();

private:
    Ui::TodoItem *ui;
    vector<TodoItem> DataList;
    QString DueDate;
    QString Contents;
};

#endif // TODOITEM_H
