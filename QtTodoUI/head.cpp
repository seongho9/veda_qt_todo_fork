#include "head.h"
#include "ui_head.h"
#include <QTimer>
#include <QDateTime>
#include <QPushButton>

Head::Head(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Head)
{
    ui->setupUi(this);

    timer = new QTimer();

    ui->label_2->setText(getCurrentDateTime());
    //  10sec
    timer->setInterval(10000);
    connect(timer, &QTimer::timeout,
            [&](){  ui->label_2->setText(getCurrentDateTime()); });

    connect(
        dynamic_cast<QPushButton*>(ui->save),
        &QPushButton::clicked,
        [&](){  emit save();    });
    connect(
        dynamic_cast<QPushButton*>(ui->load),
        &QPushButton::clicked,
        [&](){  emit load();    });
    connect(
        dynamic_cast<QPushButton*>(ui->logout),
        &QPushButton::clicked,
        [&](){  emit logout();  });
}

Head::~Head()
{
    delete ui;
    delete timer;
}

QString Head::getCurrentDateTime()
{
    QDateTime current = QDateTime::currentDateTime();
    QDate curDate = current.date();
    QTime curTime = current.time();
    QString timeStr;
    timeStr.append(QString::number(curDate.year())).append("-");
    //  month
    if(curDate.month()<10){
        timeStr.append("0").append(QString::number(curDate.month())).append("-");
    }
    else{
        timeStr.append(QString::number(curDate.month())).append("-");
    }
    //  day
    if(curDate.day()<10){
        timeStr.append("0").append(QString::number(curDate.day())).append(" ");
    }
    else{
        timeStr.append(QString::number(curDate.day())).append(" ");
    }
    // hour
    if(curTime.hour()<10){
        timeStr.append("0").append(QString::number(curTime.hour())).append(":");
    }
    else{
        timeStr.append(QString::number(curTime.hour())).append(":");
    }
    //  minute
    if(curTime.minute()<10){
        timeStr.append("0").append(QString::number(curTime.minute()));
    }
    else{
        timeStr.append(QString::number(curTime.minute()));
    }

    return timeStr;
}
