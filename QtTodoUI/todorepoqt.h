#ifndef TODOREPO_H
#define TODOREPO_H

#include "Todo.h"
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QString>

class TodoRepo
{
public:
    TodoRepo() = default;
    virtual ~TodoRepo() = default;
    virtual unsigned int saveArray(const QVector<Todo>& data) = 0;
    virtual void load(QVector<Todo>& res) = 0;
};

class TodoRepoQt : public TodoRepo
{
private:
    QFile output;
    QFile input;
    QString dir;
    QMutex lock;
public:

    TodoRepoQt() = delete;
    TodoRepoQt(const QString& dir);
    unsigned int saveArray(const QVector<Todo>& data) override;
    void load(QVector<Todo>& res) override;

};

friend QDataStream& operator<<(QDataStream& out, const Todo& todo)
{
    out << todo.id << todo.userName << todo.content
        << todo.insertDate << todo.dueDate
        << todo.isDone << todo.isFin;

    return out;
}

friend QDataStream& operator>>(QDataStream& in, Todo& todo)
{
    in >> todo.id >> todo.userName >> todo.content
        >> todo.insertDate >> todo.dueDate
        >> todo.isDone >> todo.isFin;
    return in;
}
#endif // TODOREPO_H
