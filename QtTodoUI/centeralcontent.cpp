#include "centeralcontent.h"
#include "ui_centeralcontent.h"
#include "todoui.h"

#include "Todo.h"
#include <vector>
CenteralContent::CenteralContent(DataManage* manage, QWidget *parent)

    : QWidget(parent)
    , ui(new Ui::CenteralContent)
{
    ui->setupUi(this);
    this->manager = manage;
    this->content = nullptr;
}
// 여기부터
void CenteralContent::makeTab(QString name)
{
    std::vector<Todo> cur;
    std::vector<Todo> finish;
    manager->getCurrentData(cur, name.toStdString());
    manager->getFinishedData(finish, name.toStdString());

    this->content = new TodoUI(manager, name, this);

    connect(this->content, &TodoUI::edit,[&](unsigned int id, QString userName, QString input, QString date)
            {emit edit(id, userName, input, date); });
}

void CenteralContent::closeTab(QString name)
{
    qDebug() << "close " << name;
    //manager->save();
    delete content;
    content = nullptr;
}
void CenteralContent::refresh(QString userName)
{
    qDebug()<<"refresh"<<userName;
    this->content->showTodoList();
}
CenteralContent::~CenteralContent()
{
    delete ui;
}
