#include "todoitem.h"
#include "ui_todoitem.h"

TodoItem::TodoItem(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TodoItem)
{
    ui->setupUi(this);
}

TodoItem::setDueDate(QString DueDate)
{
    ui->DueDate->setText(DueDate);
}

TodoItem::setContent(QString Contents)
{
    this->Contents->setText(Contents);
}

TodoItem::LEDBlink()
{
                     ui->
}
TodoItem::~TodoItem()
{
    delete ui;
}
