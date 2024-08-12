#include "todoui.h"
#include "mainwindow.h"
#include "button.h"
#include "calendardialog.h"
#include "centeralcontent.h"
#include "head.h"
#include "inputwidget.h"
#include "todoitem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TodoUI w;
    w.show();
    return a.exec();
}
