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

    ui->save->setIcon(":/icons/save.png");
    ui->load->setIcon(":/icons/download.png");
    ui->logout->setIcon(":/icons/logout.png");

    timer = new QTimer();

    ui->label_2->setText(getCurrentDateTime());
    //  10sec

    timer->setInterval(1000);
    connect(timer, &QTimer::timeout,
            [&](){
                ui->label_2->setText(getCurrentDateTime());
    });
    ui->save->setClick([&](){ emit save(); qDebug()<<"s"; });
    ui->load->setClick([&](){ emit load(); qDebug()<<"load";});
    ui->logout->setClick([&](){ emit logout(); qDebug()<<"log";});
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
