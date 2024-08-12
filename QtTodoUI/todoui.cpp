#include "todoui.h"
#include "./ui_todoui.h"
#include <QListWidget>
#include <QLabel>

TodoUI::TodoUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoUI)
{
    ui->setupUi(this);
    auto item1 = std::make_shared<TodoItem>(this);
    item1->setDueDate("2022-04-05");
    item1->setContent("Sample Task 1");
    item1->setIsFinish(true);
    item1->setIsDone(false);

    auto item2 = std::make_shared<TodoItem>(this);
    item2->setDueDate("2022-05-10");
    item2->setContent("Sample Task 2");
    item2->setIsFinish(false);
    item2->setIsDone(true);

    auto item3 = std::make_shared<TodoItem>(this);
    item3->setDueDate("2022-05-15");
    item3->setContent("Sample Task 3");
    item3->setIsFinish(true);
    item3->setIsDone(true);

    auto item4 = std::make_shared<TodoItem>(this);
    item4->setDueDate("2022-12-15");
    item4->setContent("Sample Task 4");
    item4->setIsFinish(true);
    item4->setIsDone(true);
    auto item5 = std::make_shared<TodoItem>(this);
    item5->setDueDate("2021-12-15");
    item5->setContent("Sample Task 5");
    item5->setIsFinish(true);
    item5->setIsDone(true);
    v.push_back(item1);
    v.push_back(item2);
    v.push_back(item3);
    v.push_back(item4);
    v.push_back(item5);

    showTodoList(v);
}


TodoUI::~TodoUI()
{
    delete ui;
}

void TodoUI::showTodoList(const QVector<std::shared_ptr<TodoItem>> &todoList)
{
    ui->Contents->clear();
    for(const auto &itemPtr : todoList)
    {
        QListWidgetItem *listWidgetItem = new QListWidgetItem();
        listWidgetItem->setSizeHint(itemPtr->sizeHint()); // Set size hint based on widget's size
        ui->Contents->addItem(listWidgetItem); // Add item to QListWidget
        ui->Contents->setItemWidget(listWidgetItem, itemPtr.get()); // Set the custom widget
    }
}

// void TodoUI::EndshowTodoList(const QVector<std::shared_ptr<TodoItem>> &todoList)
// {
//     ui->Contents->clear();
//     for(const auto &itemptr : todoList)
//     {
//         TodoItem *widget = new TodoItem(*itemptr);
//         if(widget->
//     }


// }
