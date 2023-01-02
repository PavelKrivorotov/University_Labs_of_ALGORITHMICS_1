#include "processor.h"

using namespace std;

Processor::Processor() {
    _currentTask = nullptr;

    _turn1 = new Turn();
    _turn2 = new Turn();
    _turn3 = new Turn();

    _stack = new Stack();

    fillTurn();
}


Processor::~Processor() {
    delete _turn1;
    delete _turn2;
    delete _turn3;
    delete _stack;
}


void Processor::fillTurn() {
    Task *task1 = new Task(1, 2, 1);
    Task *task2 = new Task(2, 6, 8);
    Task *task3 = new Task(3, 3, 4);
    Task *task4 = new Task(4, 3, 1);
    Task *task5 = new Task(5, 2, 2);
    Task *task6 = new Task(6, 7, 2);
    Task *task7 = new Task(7, 2, 1);
    Task *task8 = new Task(8, 3, 1);
    Task *task9 = new Task(9, 5, 9);
    Task *task10 = new Task(10, 6, 3);
    Task *task11 = new Task(11, 7, 7);

    _turn1->append(task2);
    _turn1->append(task3);
    _turn1->append(task6);
    _turn1->append(task7);
    _turn1->append(task10);

    _turn2->append(task5);
    _turn2->append(task1);
    _turn2->append(task11);

    _turn3->append(task4);
    _turn3->append(task8);
    _turn3->append(task9);
}


void Processor::turnProcessing(Turn *turn) {
    Task *newTask = turn->get();

    if (!_currentTask) {
        _currentTask = newTask;
        return;
    }

    if (_currentTask->getCurrentTime() == _currentTask->getCompleteTime()) {
        delete _currentTask;

        _currentTask = newTask;
        return;
    }

    if (newTask->getPriority() > _currentTask->getPriority()) {
        if (_currentTask->getCurrentTime() < (_currentTask->getCompleteTime() -
                                              _currentTask->getCurrentTime())) {
            _stack->append(_currentTask);
            _currentTask = newTask;
            return;
        }
    }

    _stack->append(newTask);
    _currentTask->updateCurrentTime();
}


void Processor::stackProcessing(Stack *stack) {
    if (_currentTask->getCurrentTime() == _currentTask->getCompleteTime()) {
        Task *newTask = stack->pop();

        delete _currentTask;

        _currentTask = newTask;
        return;
    }

    _currentTask->updateCurrentTime();
}


void Processor::completeLastTask() {
    if (_currentTask->getCurrentTime() == _currentTask->getCompleteTime()) {
        delete _currentTask;

        _currentTask = nullptr;
        return;
    }

    _currentTask->updateCurrentTime();
}


bool Processor::tickTack() {
    if (!_turn1->isEmpty()) {
        turnProcessing(_turn1);
        show();
        return true;
    }

    if (!_turn2->isEmpty()) {
        turnProcessing(_turn2);
        show();
        return true;
    }

    if (!_turn3->isEmpty()) {
        turnProcessing(_turn3);
        show();
        return true;
    }

    if (!_stack->isEmpty()) {
        stackProcessing(_stack);
        show();
        return true;
    }

    if (_currentTask) {
        completeLastTask();
        show();
        return true;
    }

    return false;
}


void Processor::show() {
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t|\t\tProcessor\t\t|" << endl;
    cout << "\t+---------------------------------------+" << endl;

    if (_currentTask) {
        cout << "\t| Task isEmpty \t|\t" << false << "\t\t|" << endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
        cout << "\t|\tid\t|\tpriority\t|\tcurrent time\t|\tcomplete time\t|" << endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
        cout << "\t|\t " << _currentTask->getId() << "\t|\t  " << _currentTask->getPriority()
             << "\t\t|\t" << _currentTask->getCurrentTime() << "\t\t|\t" <<
             _currentTask->getCompleteTime() << "\t\t|"<< endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
    }

    else {
        cout << "\t| Task isEmpty\t|\t" << true << "\t\t|" << endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
        cout << "\t|\tid\t|\tpriority\t|\tcurrent time\t|\tcomplete time\t|" << endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
    }


    cout << endl;
    cout << "\t+---------------------------------------+" << endl;


    cout << "\t|\t\t  Turn 1 \t\t|" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t| isEmpty\t|\t" << _turn1->isEmpty() << "\t\t|" << endl;
    _turn1->show();


    cout << endl;
    cout << "\t+---------------------------------------+" << endl;


    cout << "\t|\t\t  Turn 2 \t\t|" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t| isEmpty\t|\t" << _turn2->isEmpty() << "\t\t|" << endl;
    _turn2->show();


    cout << endl;
    cout << "\t+---------------------------------------+" << endl;


    cout << "\t|\t\t  Turn 3 \t\t|" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t| isEmpty\t|\t" << _turn3->isEmpty() << "\t\t|" << endl;
    _turn3->show();


    cout << endl;
    cout << "\t+---------------------------------------+" << endl;


    cout << "\t|\t\t  Stack  \t\t|" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t| isEmpty\t|\t" << _stack->isEmpty() << "\t\t|" << endl;
    _stack->show();
}

