#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H
#include <QDialog>
#include <QCalendarWidget>
#include <QDate>
#include <QPushButton>
#include <QVBoxLayout>
class CalendarDialog : public QWidget
{
    Q_OBJECT
public:
    CalendarDialog();


    ~CalendarDialog();

private:
    QVBoxLayout* layout;
    QCalendarWidget* calendar;
    QPushButton* submit;
    QDate* date;

signals:
    void closeWindow(QString date);
};

#endif // CALENDARDIALOG_H
