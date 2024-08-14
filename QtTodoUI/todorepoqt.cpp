#include "todorepoqt.h"
#include <QIODevice>
TodoRepoQt::TodoRepoQt(QString dir)
{
    output = QFile();
    input = QFile();
    this->dir = dir;
}


unsigned int TodoRepoQt::saveArray(const QVector<Todo>& data)
{
    int i = 0;
    lock.lock();
    output.open(QIODevice::WriteOnly | QIODevice::Append);
    if (!output.isOpen()) // Append 모드시 자동으로 파일의 끝으로 이동함
    {
        qCritical() << "Cannot open output file for writing";
        lock.unlock();
        return 0;
    }
    QDataStream out(&output);
    for (int i = 0; i < data.size(); i++)
    {
        out << data[i];
    }
    output.close();
    lock.unlock();
    return i;
}
void TodoRepoQt::load(QVector<Todo>& res)
{
    lock.lock();  // 잠금을 획득하여 스레드 안전성을 보장합니다.

    input.open(dir, QIODevice::ReadOnly);
    if (!input.isOpen())
    {
        qCritical() << "input stream cannot open";
        lock.unlock();  // 파일 열기에 실패하면 잠금을 해제합니다.
        return;
    }

    QDataStream in(&input);
    QVector<Todo> tmp;

    while (!in.atEnd()) {
        Todo todo;
        in >> todo;  // QDataStream에서 Todo 객체를 읽습니다.
        tmp.push_back(todo);
    }

    res.swap(tmp);  // 읽은 데이터를 기존의 res에 교환하여 반환합니다.
    input.close();  // 파일을 닫습니다.
    lock.unlock();  // 작업 완료 후 잠금을 해제합니다.
}
