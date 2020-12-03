#ifndef __INSTSOUND_FX18_HPP__
#define __INSTSOUND_FX18_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstSound_FX18: Inst
{
public:
    InstSound_FX18(unsigned short opcode) : Inst(opcode) {};
    ~InstSound_FX18() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets the sound timer to VX.
        systemData->systemTimer = systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8];
        systemData->systemProgramCounter += 2;
        
        return true;
    }

};

#endif







