
#ifndef __INSTCONST_7XNN_HPP__
#define __INSTCONST_7XNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstConst_7XNN : Inst
{
public:
    InstConst_7XNN(unsigned short opcode) : Inst(opcode) {};
    ~InstConst_7XNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //add nn to vx
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] += (mOpCode & 0x00FF);
        
        //skip the normal 2
        systemData->systemProgramCounter += 2;
        return true;
    }

};

#endif




