#ifndef __INSTTIMER_FX07_HPP__
#define __INSTTIMER_FX07_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstTimer_FX07: Inst
{
public:
    InstTimer_FX07(unsigned short opcode) : Inst(opcode) {};
    ~InstTimer_FX07() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets VX to the value of the delay timer.
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = systemData->delayTimer;
        systemData->systemProgramCounter += 2;
        
        return true;
    }

};

#endif







