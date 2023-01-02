#include "task.h"

using namespace std;

Task::Task(int id, int priority, int completeTime) {
    _currentTime = 0;

    if (id < 1) { _id = 1; } else { _id = id; }
    if (priority < 1) { _priority = 1; } else { _priority = priority; }
    if (completeTime < 1) { _completeTime = 1; } else { _completeTime = completeTime; }
}


Task::~Task() {

}


int Task::getId() {
    return _id;
}


int Task::getPriority() {
    return _priority;
}


int Task::getCompleteTime() {
    return _completeTime;
}


int Task::getCurrentTime() {
    return _currentTime;
}


void Task::updateCurrentTime() {
    _currentTime += 1;
}


string Task::show() {
    string str;

    str.append("<id = ");
    str.append(to_string(_id));
    str.append(", priority = ");
    str.append(to_string(_priority));
    str.append(", time = ");
    str.append(to_string(_currentTime));
    str.append(" out of ");
    str.append(to_string(_completeTime));
    str.append(">");

    return str;
}

