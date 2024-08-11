#ifndef TODOITEM_H
#define TODOITEM_H

#include <QWidget>
namespace Ui {
class TodoItem;
}

class TodoItem : public QWidget
{
    Q_OBJECT

public:
    explicit TodoItem(QWidget *parent = nullptr);
    TodoItem(TodoItem& obj);
    void setDueDate(QString dueDate);
    void setContent(QString content);
    void setIsFinish(bool isFinish);
    void setIsDone(bool isDone);
    ~TodoItem();

private:
    Ui::TodoItem *ui;

    QString dueDate;
    QString content;
    bool isFinish;
    bool isDone;

signals:
    void checked(bool flag);
    void edit(QString content, QString date);
};

#endif // TODOITEM_H
