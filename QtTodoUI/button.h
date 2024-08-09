#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QString>
namespace Ui {
class Button;
}


class Button : public QWidget
{
    Q_OBJECT

public:
    explicit Button(QWidget *parent = nullptr);

    void setIcon(QString icon);
    void setIcon(const char* icon);

    void setText(QString text);
    void setText(const char* text);

    void setClick(std::function<void(void)> slot);
    void setClick(QObject* object, std::function<void(void)> slot);

    ~Button();

private:
    Ui::Button *ui;
};

#endif // BUTTON_H
