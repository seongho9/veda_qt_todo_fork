#ifndef FINISHENABLETAB_H
#define FINISHENABLETAB_H

#include <QWidget>

namespace Ui {
class FinishEnableTab;
}

class FinishEnableTab : public QWidget
{
    Q_OBJECT

public:
    explicit FinishEnableTab(QWidget *parent = nullptr);

    void setEnable(bool enable);
    ~FinishEnableTab();

private:
    Ui::FinishEnableTab *ui;
    bool enabling;

signals:
    void clickTab(bool enabling);
};

#endif // FINISHENABLETAB_H
