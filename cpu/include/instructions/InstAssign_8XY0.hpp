#ifndef __INSTASSIGN_8XY0_HPP__
#define __INSTASSIGN_8XY0_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstAssign_8XY0 : Inst
{
public:
    InstAssign_8XY0(unsigned short opcode) : Inst(opcode) {};
    ~InstAssign_8XY0() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Set vX to the value of vY
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4];

        //increment program counter
        systemData->systemProgramCounter += 2;

        return true;
    }

};

#endif