
#ifndef __INSTCONST_6XNN_HPP__
#define __INSTCONST_6XNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstConst_6XNN : Inst
{
public:
    InstConst_6XNN(unsigned short opcode) : Inst(opcode) {};
    ~InstConst_6XNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //set vx to nn
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = (mOpCode & 0x00FF);
        
        //skip the normal 2
        systemData->systemProgramCounter += 2;
        return true;
    }

};

#endif



