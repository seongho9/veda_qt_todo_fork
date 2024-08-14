#include "todoitem.h"
#include "ui_todoitem.h"

TodoItem::TodoItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoItem)
{

    ui->setupUi(this);

    ui->edit->setIcon(":/icons/edit.png");
    ui->remove->setIcon(":/icons/delete.png");
    ui->isDone->setIcon(":/icons/check_done.png");

    ui->isDone->setClick(this, [&](){
        this->isDone = !(this->isDone);

        QString icon = isDone ?
                           ":/icons/check_done.png" : ":/icons/check_dur.png";
        ui->isDone->setIcon(icon);

        emit checked(this->id, this->isDone);
    });
    ui->edit->setClick([&](){
        emit edit(id, content, dueDate);
    });
    ui->remove->setClick([&](){
        emit remove(id);
    });

    ui->content->setText("");
    ui->dueDate->setText("");
}

void TodoItem::setDueDate(QString dueDate)
{
    this->dueDate=dueDate;
    ui->dueDate->setText(dueDate);
}

void TodoItem::setContent(QString content)
{
    this->content = content;
    ui->content->setText(content);
}
void TodoItem::setId(unsigned int id)
{
    this->id = id;
}
void TodoItem::setIsFinish(bool isFinish)
{
    this->isFinish = isFinish;
}

void TodoItem::setIsDone(bool isDone)
{
    this->isDone = isDone;
    QString icon = isDone ?
                       ":/icons/check_done.png" : ":/icons/check_dur.png";
    ui->isDone->setIcon(icon);
}


TodoItem::~TodoItem()
{
    delete ui;
}
