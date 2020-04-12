#include "cpu/Stack.h"

Stack::Stack(int stackSize)
{
    mStackSize = stackSize;
    mStackPointer = 0x0;
    mStack = new unsigned short[mStackSize];
}

Stack::~Stack()
{
    delete mStack;
}

unsigned short Stack::PopStack()
{
    if (mStackPointer > 0x0)
    {
        //Decrement the stack pointer and get new pc value
        mStackPointer--;
        unsigned short newPC = mStack[mStackPointer];

        //erase old stack value
        mStack[mStackPointer] = 0x0;

        return newPC;
    }

    return 0x0;
}

bool Stack::PushStack(unsigned short programCounter)
{
    //Verify this add won't overflow the stack...
    if (mStackPointer < mStackSize)
    {
        //set to new pc value in move up
        mStack[mStackPointer] = programCounter;
        mStackPointer++;

        return true;
    }

    return false;
}