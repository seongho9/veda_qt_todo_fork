#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "todoui.h"
MainWindow::MainWindow(DataManage* manager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->manager = manager;


    head = new Head(this);
    this->setMenuWidget(head);
    this->content = new TodoUI(manager, "", this);


    this->setCentralWidget(content);


    inputDock = new QDockWidget(this);
    inputWidget = new InputWidget(this);
    inputDock->setWidget(inputWidget);
    inputDock->setFloating(false);
    this->addDockWidget(Qt::BottomDockWidgetArea, inputDock);


    connect(inputWidget, &InputWidget::enterPressed, this,
    [&](QString userName, QString content, QString duedate){
        Todo todo;
        todo.setContent(content.toStdString());
        todo.setDueDate(duedate.toStdString());
        todo.setIsDone(false);
        todo.setUserName(userName.toStdString());

        manager->addTodoData(this->content->getUserName().toStdString(), todo);

        this->content->removeListItems();
        this->content->showTodoList();

    });

    connect(inputWidget, &InputWidget::editPressed, this,
        [&](unsigned int id, QString userName, QString input, QString dueDate){

        Todo todo;
        todo.setContent(input.toStdString());
        todo.setDueDate(dueDate.toStdString());
        todo.setUserName(userName.toStdString());

        todo.setId(id);
        manager->editTodoData(userName.toStdString(), todo);
        this->content->removeListItems();
        this->content->showTodoList();
    });

    connect(head, &Head::login,this,
            [&](QString user){
                if(!manager->isUser(user.toStdString())){
                    Todo data;
                    data.setUserName(user.toStdString());
                    manager->addTodoData(user.toStdString(), data);
                    manager->removeTodoData(user.toStdString(), 0);

                }
                content->setUser(user);
                head->setUserLabel(user);
                content->showTodoList();
            });
    connect(head, &Head::save,this,
            [&](){
                manager->save();
            });
    connect(head, &Head::logout, this,
            [&](){
                content->setUser("");
                head->setUserLabel("");
            });
    connect(content, &TodoUI::edit, this,
            [&](unsigned int id, QString userName, QString input, QString date){
                inputWidget->setUserName(userName);
                inputWidget->setInput(input);
                inputWidget->setDue(date);
                inputWidget->setId(id);
            });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete head;
    delete inputDock;
    delete inputWidget;
}
