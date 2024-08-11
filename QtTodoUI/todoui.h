#ifndef TODOUI_H
#define TODOUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TodoUI;
}
QT_END_NAMESPACE

class TodoUI : public QWidget
{
    Q_OBJECT

public:
    TodoUI(QWidget *parent = nullptr);
    ~TodoUI();
    void setsize();

private:
    Ui::TodoUI *ui;
};
#endif // TODOUI_H
