#ifndef CENTERALCONTENT_H
#define CENTERALCONTENT_H

#include <QWidget>
#include <QVector>
#include "todoui.h"
#include "DataManage.h"

namespace Ui {
class CenteralContent;
}

class CenteralContent : public QWidget
{
    Q_OBJECT

public:
    explicit CenteralContent(DataManage* manage, QWidget *parent = nullptr);
    ~CenteralContent();
    void makeTab(QString userName);
    void closeTab(QString userName);
    void refresh(QString userName);
private:
    Ui::CenteralContent *ui;
    TodoUI* content;
    DataManage* manager;


signals:
    void edit(unsigned int id, QString userName, QString content, QString date);

};

#endif // CENTERALCONTENT_H
