#ifndef __INSTMEM_FX1E_HPP__
#define __INSTMEM_FX1E_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMem_FX1E: Inst
{
public:
    InstMem_FX1E(unsigned short opcode) : Inst(opcode) {};
    ~InstMem_FX1E() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Adds VX to I.
        // VF is set to 1 when range overflow (I+VX>0xFFF), and 0 when there isn't.
        if(systemData->systemIndexRegister + systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] > 0xFFF)
        {
            systemData->systemCpuRegisters[0xF] = 1;
        }
        else
        {
            systemData->systemCpuRegisters[0xF] = 0;
        }

        //Add..
        systemData->systemIndexRegister += systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8];
        systemData->systemProgramCounter += 2;

        return true;
    }

};

#endif







