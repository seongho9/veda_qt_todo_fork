#include "todoui.h"
#include "./ui_todoui.h"

TodoUI::TodoUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoUI)
{
    ui->setupUi(this);
}

TodoUI::~TodoUI()
{
    delete ui;
}
