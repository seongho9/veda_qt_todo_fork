#include "DataManage.h"
#include <ctime>
#include <QWidget>
using namespace std;

DataManageImpl::DataManageImpl(TodoRepo* todoRepo, UserTodoConverter* converter)
{
    this->todoRepo = todoRepo;
    this->converter = converter;

    this->converter->load(this->userTodoData);
}
DataManageImpl::~DataManageImpl()
{
    this->converter->save(this->userTodoData);
}
bool DataManageImpl::getCurrentData(vector<Todo>& res, string name)
{
    if (userTodoData.find(name) == userTodoData.end()) {
        //	�Է��� �����Ͱ� ���� ���
        return false;
    }

    userTodoData[name].getCurrentData(res);

    return true;
}

bool DataManageImpl::getFinishedData(vector<Todo>& res, string name)
{
    if (userTodoData.find(name) == userTodoData.end()) {
        return false;
    }

    userTodoData[name].getFinishedData(res);


    return true;
}

Todo DataManageImpl::addTodoData(string name, Todo data)
{
    time_t timer = time(NULL);
    // YYYY-MM-DD
    struct tm* currentTime = localtime(&timer);

    data.setIsDone(false);
    data.setUserName(name);

    if (userTodoData.find(name) == userTodoData.end()) {
        vector<Todo> current;
        vector<Todo> finish;


        UserTodo userData = UserTodo(0, name, current, finish);
        data.setId(0);
        userData.insertData(data);

        userTodoData.insert({name, userData});

        return data;
    }

    unsigned int id = userTodoData[name].getId();

    data.setId(id);
    userTodoData[name].insertData(data);


    return data;
}

bool DataManageImpl::removeTodoData(string name, unsigned int id) {

    if (userTodoData.find(name) == userTodoData.end()) {
        return false;
    }

    userTodoData[name].removeData(id);

    return true;
}

bool DataManageImpl::editTodoData(std::string name, Todo data)
{
    if (userTodoData.find(name) == userTodoData.end()) {
        return false;
    }

    userTodoData[name].editData(data.getId(), data);

    return true;
}

bool DataManageImpl::isUser(string name)
{
    return
        !(userTodoData.find(name) == userTodoData.end());
}

bool DataManageImpl::save()
{
    converter->save(userTodoData);

    return true;
}

void DataManageImpl::convert(string name)
{
    userTodoData[name].convertData();
}

void DataManageImpl::checkTodo(unsigned int id, string name)
{
    std::vector<Todo> data;
    userTodoData[name].getCurrentData(data);
    for(Todo& iter : data){
        if(iter.getId()==id){
            iter.setIsDone(!(iter.getIsDone()));
            break;
        }
    }
    userTodoData[name].setCurrentData(data);

}
