#ifndef TODOUI_H
#define TODOUI_H

#include <QWidget>
#include "todoitem.h"
#include <QVector>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class TodoUI;
}
QT_END_NAMESPACE

class TodoUI : public QWidget
{
    Q_OBJECT

public:
    explicit TodoUI(QWidget *parent = nullptr);
    void showTodoList(const QVector<std::shared_ptr<TodoItem>> &todoList);
    ~TodoUI();

private:
    Ui::TodoUI *ui;
    QVector<std::shared_ptr<TodoItem>> v;
};
#endif // TODOUI_H
