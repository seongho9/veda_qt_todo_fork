#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = nullptr);
    ~InputWidget();
    void setInput(QString input);
    void setDue(QString due);
private:
    Ui::InputWidget *ui;
    QString input;
    QString due;

signals:

    void enterPressed(QString input, QString dueDate);
};

#endif // INPUTWIDGET_H
