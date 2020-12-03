#ifndef __INSTFLOW_1NNN_HPP__
#define __INSTFLOW_1NNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstFlow_1NNN: Inst
{
public:
    InstFlow_1NNN(unsigned short opcode) : Inst(opcode) {};
    ~InstFlow_1NNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //Jumps to address at NNN, Since your already jumping don't increase the PC
        systemData->systemProgramCounter = (ushort)(mOpCode & 0x0FFF);
        
        return true;
    }

};

#endif







