#ifndef TODOLISTWIDGET_H
#define TODOLISTWIDGET_H

#include <QWidget>

namespace Ui {
class TodoListWidget;
}

class TodoListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TodoListWidget(QWidget *parent = nullptr);
    ~TodoListWidget();

private:
    Ui::TodoListWidget *ui;
};

#endif // TODOLISTWIDGET_H
