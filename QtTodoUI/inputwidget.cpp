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

    ui->calendar->setIcon(":/icons/calender.png");
    ui->submit->setIcon(":/icons/submit.png");
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

    ui->submit->setClick(this, [&](){
        if(input.isEmpty()){
            QMessageBox::warning(this, "Todo 입력 오류","Todo 내용이 입력되지 않았습니다.",QMessageBox::Ok);
        }
        else if(due.isEmpty()){
            QMessageBox::warning(this, "Todo 입력 오류","Todo 마감일이 입력되지 않았습니다.",QMessageBox::Ok);
        }
        else{
            if(isEdit){
                qDebug()<<"editddd";
                emit editPressed(id, userName, input, due);
            }
            else{
                emit enterPressed(userName, input, due);
            }
            input.clear();
            due.clear();
            isEdit = false;
            ui->input->clear();
        }
    });

    isEdit = false;
}
void InputWidget::setUserName(QString userName)
{
    this->userName = userName;

}
void InputWidget::setInput(QString input)
{
    this->input = input;
    ui->input->setText(this->input);
}
void InputWidget::setDue(QString due)
{
    this->due = due;
}
void InputWidget::setId(unsigned int id)
{
    this->id = id;
    isEdit=true;
}
InputWidget::~InputWidget()
{
    delete ui;
}
