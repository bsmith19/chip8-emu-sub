#ifndef __STACK_H__
#define __STACK_H__
#include <memory>


class Stack
{
public:
    Stack(int stackSize);
    ~Stack();

public:
    unsigned short PopStack();
    bool PushStack(unsigned short programCounter);

private:
    int mStackSize;
    unsigned short mStackPointer;
    unsigned short* mStack;
};

#endif