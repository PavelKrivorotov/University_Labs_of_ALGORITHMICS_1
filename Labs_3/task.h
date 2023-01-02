#ifndef TASK_H
#define TASK_H

#include <iostream>


class Task {

public:
    Task(int id, int priority = 1, int completeTime = 1);
    virtual ~Task();

    int getId();

    int getPriority();

    int getCompleteTime();

    int getCurrentTime();

    void updateCurrentTime();

    std::string show();

private:
    int _id;
    int _priority;
    int _completeTime;
    int _currentTime;
};

#endif // TASK_H
