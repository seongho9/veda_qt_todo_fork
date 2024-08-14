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
    TodoItem(const TodoItem& obj) = delete;
    TodoItem& operator=(const TodoItem&) = delete;

    void setDueDate(QString dueDate);
    void setContent(QString content);
    void setIsFinish(bool isFinish);
    void setIsDone(bool isDone);
    void setId(unsigned int id);
    ~TodoItem();

private:
    unsigned int id;
    Ui::TodoItem *ui;
    QString dueDate;
    QString content;
    bool isFinish;
    bool isDone;

signals:
    void checked(unsigned int id, bool flag);
    void edit(unsigned int id, QString content, QString date);
    void remove(unsigned int id);

};

#endif // TODOITEM_H
