#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    head = new Head(this);
    this->setMenuWidget(head);

    centeralContent = new CenteralContent(this);


    this->setCentralWidget(centeralContent);


    inputDock = new QDockWidget(this);
    inputWidget = new InputWidget(this);
    inputDock->setWidget(inputWidget);
    inputDock->setFloating(false);
    this->addDockWidget(Qt::BottomDockWidgetArea, inputDock);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete head;
    delete inputDock;
    delete inputWidget;
}
