#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QTabWidget>
#include <QToolBar>
#include "inputwidget.h"
#include "head.h"
#include "todoui.h"
#include "DataManage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DataManage* manager, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    DataManage* manager;

    Head* head;

    TodoUI* content;
    InputWidget* inputWidget;
    QDockWidget* inputDock;
signals:

};

#endif // MAINWINDOW_H
