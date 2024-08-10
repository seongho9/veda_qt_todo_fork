#include "centeralcontent.h"
#include "ui_centeralcontent.h"

CenteralContent::CenteralContent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CenteralContent)
{
    ui->setupUi(this);
    ui->tabWidget->clear();
}

CenteralContent::~CenteralContent()
{
    delete ui;
}
