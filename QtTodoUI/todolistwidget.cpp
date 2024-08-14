#include "todolistwidget.h"
#include "ui_todolistwidget.h"

TodoListWidget::TodoListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoListWidget)
{
    ui->setupUi(this);


}

TodoListWidget::~TodoListWidget()
{
    delete ui;
}
