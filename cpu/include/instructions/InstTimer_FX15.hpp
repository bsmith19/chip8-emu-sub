#ifndef __INSTTIMER_FX15_HPP__
#define __INSTTIMER_FX15_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstTimer_FX15: Inst
{
public:
    InstTimer_FX15(unsigned short opcode) : Inst(opcode) {};
    ~InstTimer_FX15() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets the delay timer to VX.
        systemData->delayTimer = systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8];
        systemData->systemProgramCounter += 2;
        
        return true;
    }

};

#endif







