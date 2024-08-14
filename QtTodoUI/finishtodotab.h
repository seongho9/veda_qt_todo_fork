#ifndef FINISHTODOTAB_H
#define FINISHTODOTAB_H

#include <QWidget>

namespace Ui {
class FinishTodoTab;
}

class FinishTodoTab : public QWidget
{
    Q_OBJECT

public:
    explicit FinishTodoTab(QWidget *parent = nullptr);
    ~FinishTodoTab();

private:
    Ui::FinishTodoTab *ui;
};

#endif // FINISHTODOTAB_H
