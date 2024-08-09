#ifndef HEAD_H
#define HEAD_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Head;
}

class Head : public QWidget
{
    Q_OBJECT

public:
    explicit Head(QWidget *parent = nullptr);
    ~Head();

private:

    QString getCurrentDateTime();
    Ui::Head *ui;
    QTimer* timer;

signals:
    void save();
    void load();
    void logout();
};

#endif // HEAD_H
