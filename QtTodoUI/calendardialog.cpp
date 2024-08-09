#include "calendardialog.h"
#include <QDate>
CalendarDialog::CalendarDialog()
{
    layout = new QVBoxLayout(this);

    submit = new QPushButton(this);
    calendar = new QCalendarWidget(this);
    date = new QDate();

    connect(calendar, &QCalendarWidget::clicked,
            [&](QDate param){
                date->setDate(param.year(), param.month(), param.daysInMonth());
        });
    connect(submit, &QPushButton::clicked,
            [&](){
                this->close();
                emit closeWindow(date->toString("yyyy-MM-dd"));
                delete this;
        });
    layout->addWidget(calendar);
    layout->addWidget(submit);
    layout->setSpacing(10);

    show();
}

CalendarDialog::~CalendarDialog()
{
    delete submit;
    delete calendar;
    delete date;
}
