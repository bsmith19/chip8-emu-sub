#ifndef __INSTMEM_FX55_HPP__
#define __INSTMEM_FX55_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMem_FX55: Inst
{
public:
    InstMem_FX55(unsigned short opcode) : Inst(opcode) {};
    ~InstMem_FX55() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Stores V0 to VX (including VX) in memory starting at address I. I is increased by 1 for each value written.
        for (int i = 0; i < ((mOpCode & 0x0F00) >> 8); i++)
        {
            systemData->systemMemory->SetByte(systemData->systemIndexRegister + i, systemData->systemCpuRegisters[i]);
        }
        systemData->systemProgramCounter += 2;

        //Move I to the end, not all emulators do this
        //TODO: maybe remove this
        systemData->systemIndexRegister += (ushort)(((mOpCode & 0x0F00) >> 8) + 1);
        return true;
    }

};

#endif







