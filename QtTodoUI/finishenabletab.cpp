#include "finishenabletab.h"
#include "ui_finishenabletab.h"
#include <QPushButton>

FinishEnableTab::FinishEnableTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FinishEnableTab)
{
    ui->setupUi(this);
    enabling=false;

    ui->enabling->setClick(this, [&](){

        this->enabling = !(this->enabling);
        emit clickTab(enabling);
    });



}

void FinishEnableTab::setEnable(bool enable)
{
    this->enabling = enable;

    if(enabling)
        ui->enabling->setIcon(":/icons/arrow_up.png");
    else
        ui->enabling->setIcon(":/icons/arrow_down.png");
}
FinishEnableTab::~FinishEnableTab()
{
    delete ui;
}
