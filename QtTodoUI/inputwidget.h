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
    void setId(unsigned int id);
    void setUserName(QString userName);
private:
    Ui::InputWidget *ui;
    QString input;
    QString due;
    QString userName;

    unsigned int id;
    bool isEdit;

signals:

    void enterPressed(QString userName, QString input, QString dueDate);
    void editPressed(unsigned int id, QString userName, QString input, QString dueDate);
};

#endif // INPUTWIDGET_H
