#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QTabWidget>
#include <QToolBar>
#include "inputwidget.h"
#include "head.h"
#include "centeralcontent.h"
#include "todoui.h"
#include "todoitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Head* head;

    CenteralContent* centeralContent;
    TodoUI* todoui_list;
    InputWidget* inputWidget;
    QDockWidget* inputDock;


};

#endif // MAINWINDOW_H
