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

    connect(this, &TodoItem::checked, ui->isDone,
            [&](bool flag){

                QString icon = flag ?
                    ":/icons/check_done.png" : ":/icons/check_dur.png";
                qDebug() << icon;
                ui->isDone->setIcon(icon);
            });


    ui->isDone->setClick([&](){
        qDebug() << "done";
        setIsDone(!(this->isDone));
    });
    ui->edit->setClick([&](){
        qDebug() << "edit";
        emit edit(content, dueDate);
    });
    ui->remove->setClick([&](){
        qDebug() << "delete";
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

void TodoItem::setIsFinish(bool isFinish)
{
    this->isFinish = isFinish;
}

void TodoItem::setIsDone(bool isDone)
{
    this->isDone = isDone;

    if(isDone){
        emit checked(true);
    }
    else{
        emit checked(false);
    }
}


TodoItem::~TodoItem()
{
    delete ui;
}
