#ifndef CENTERALCONTENT_H
#define CENTERALCONTENT_H

#include <QWidget>

namespace Ui {
class CenteralContent;
}

class CenteralContent : public QWidget
{
    Q_OBJECT

public:
    explicit CenteralContent(QWidget *parent = nullptr);
    ~CenteralContent();

private:
    Ui::CenteralContent *ui;
};

#endif // CENTERALCONTENT_H
