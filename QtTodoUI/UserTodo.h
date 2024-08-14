#ifndef __USER_TODO_H
#define __USER_TODO_H
#include<string>
#include<vector>
#include<mutex>
#include"Todo.h"

class UserTodo
{
    std::string userName;
    unsigned int lastIdx;

    std::vector<Todo> currentData;
    std::vector<Todo> finishedData;
    std::mutex idxLock;

public:


    UserTodo();
    UserTodo(unsigned int lastIdx, std::string userName, std::vector<Todo> current, std::vector<Todo> finish);
    UserTodo(const UserTodo& obj);

    std::string getUserName();
    void getCurrentData(std::vector<Todo>& res);
    void getFinishedData(std::vector<Todo>& res);

    unsigned int getId();
    void setId(unsigned int idx);

    void setUserName(std::string userName);
    void setCurrentData(std::vector<Todo> data);

    void insertData(Todo data);
    void removeData(unsigned int id);
    void convertData();
    void editData(unsigned int id, Todo data);
};
#endif // !__USER_TODO_H
