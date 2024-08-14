#include "finishtodotab.h"
#include "ui_finishtodotab.h"

FinishTodoTab::FinishTodoTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FinishTodoTab)
{
    ui->setupUi(this);
}

FinishTodoTab::~FinishTodoTab()
{
    delete ui;
}
