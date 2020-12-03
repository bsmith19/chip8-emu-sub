#ifndef __INSTFLOW_2NNN_HPP__
#define __INSTFLOW_2NNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstFlow_2NNN: Inst
{
public:
    InstFlow_2NNN(unsigned short opcode) : Inst(opcode) {};
    ~InstFlow_2NNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Calls subroutine at NNN
        //Push current location on stack and jump to NNN
        if(systemData->systemStack->PushStack(systemData->systemProgramCounter))
        {
            //Jump to NNN
            systemData->systemProgramCounter = (ushort)(mOpCode & 0x0FFF);
            return true;
        }
        // Stack Overflow, Fail
        return false;
    }

};

#endif







