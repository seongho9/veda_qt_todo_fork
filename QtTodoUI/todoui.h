#ifndef TODOUI_H
#define TODOUI_H

#include <QMainWindow>

class TodoUI : public QMainWindow
{
    Q_OBJECT

public:
    TodoUI(QWidget *parent = nullptr);
    ~TodoUI();
};
#endif // TODOUI_H
