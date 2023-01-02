#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "stack.h"
#include "turn.h"


class Processor {

public:
    Processor();
    virtual ~Processor();

    void fillTurn();

    void turnProcessing(Turn *turn);

    void stackProcessing(Stack *stack);

    void completeLastTask();

    void show();

    bool tickTack();

private:
    Task *_currentTask;

    Turn *_turn1;
    Turn *_turn2;
    Turn *_turn3;

    Stack *_stack;
};

#endif // PROCESSOR_H
