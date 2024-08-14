#include "todolayoutwidget.h"
#include "ui_todolayoutwidget.h"

TodoLayoutWidget::TodoLayoutWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoLayoutWidget)
{
    ui->setupUi(this);
}

TodoLayoutWidget::~TodoLayoutWidget()
{
    delete ui;
}
