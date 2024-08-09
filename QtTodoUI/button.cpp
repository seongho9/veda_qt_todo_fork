#include "ui_button.h"
#include "button.h"
#include <QIcon>
Button::Button(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Button)
{
    ui->setupUi(this);

}

void Button::setIcon(QString icon)
{
    ui->pushButton->setIcon(QIcon(icon));
}

void Button::setIcon(const char* icon)
{
    QString iconStr(icon);
    ui->pushButton->setIcon(QIcon(iconStr));
}

void Button::setText(QString text)
{
    ui->pushButton->setText(text);
}

void Button::setText(const char* text)
{
    QString textStr(text);
    ui->pushButton->setText(textStr);
}


void Button::setClick(std::function<void(void)> slot)
{
    ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, slot);
}

void Button::setClick(QObject* object, std::function<void(void)> slot)
{
    ui->pushButton->connect(
        ui->pushButton, &QPushButton::clicked,
        object, slot
    );
}
Button::~Button()
{
    delete ui;
}
