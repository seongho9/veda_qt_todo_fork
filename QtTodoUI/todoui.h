#ifndef TODOUI_H
#define TODOUI_H

#include <QWidget>
#include "todoitem.h"
#include <QVector>
#include <QVBoxLayout>
#include <QListWidget>

#include "finishenabletab.h"
#include "DataManage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TodoUI;
}
QT_END_NAMESPACE

class TodoUI : public QWidget
{
    Q_OBJECT

public:
    explicit TodoUI(DataManage* manager, QString userName, QWidget *parent = nullptr);

    ~TodoUI();

    QString getUserName() const;

    void showTodoList();
    void removeListItems();
    void setUser(QString name);
private:


    void loadTodo();

    Ui::TodoUI *ui;

    bool enabled;

    QVector<QListWidgetItem*> finishLayout;
    QVector<TodoItem*> doneTodo;

    QListWidgetItem* enableLayout;
    FinishEnableTab* enablingWidget;

    QVector<QListWidgetItem*> duringLayout;
    QVector<TodoItem*> dueTodo;

    DataManage* manager;
    QString userName;

signals:
    void edit(unsigned int id, QString userName, QString input, QString date);

};

#endif // TODOUI_H
