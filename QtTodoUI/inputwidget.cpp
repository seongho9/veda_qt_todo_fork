#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "calendardialog.h"
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


InputWidget::InputWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InputWidget)
{
    ui->setupUi(this);

    connect(
        dynamic_cast<QLineEdit*>(ui->input),
        &QLineEdit::textChanged,
        [&](QString param){
            input.clear();
            input.append(param);
        });

    ui->calendar->setClick([&](){
        CalendarDialog* dialog = new CalendarDialog();

        connect(dialog, &CalendarDialog::closeWindow, this,
                [&](QString date){
                    due = date;
            });
        });

    ui->submit->setClick([&](){
        if(input.isEmpty()){
            QMessageBox::warning(this, "Todo 입력 오류","Todo 내용이 입력되지 않았습니다.",QMessageBox::Ok);
        }
        else if(due.isEmpty()){
            QMessageBox::warning(this, "Todo 입력 오류","Todo 마감일이 입력되지 않았습니다.",QMessageBox::Ok);
        }
        else{
            emit enterPressed(input, due);
            input.clear();
            due.clear();
            ui->input->clear();
        }
    });
}
InputWidget::~InputWidget()
{
    delete ui;
}
