#ifndef __INSTMEM_FX65_HPP__
#define __INSTMEM_FX65_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMem_FX65: Inst
{
public:
    InstMem_FX65(unsigned short opcode) : Inst(opcode) {};
    ~InstMem_FX65() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Fills V0 to VX (including VX) with values from memory starting at address I. I is increased by 1 for each value written.
        for (int i = 0; i < ((mOpCode & 0x0F00) >> 8); i++)
        {
            systemData->systemCpuRegisters[i] = systemData->systemMemory->GetByte(systemData->systemIndexRegister + i);
        }
        systemData->systemProgramCounter += 2;

        //Move I to the end, not all emulators do this
        //TODO: maybe remove this
        systemData->systemIndexRegister += (ushort)(((mOpCode & 0x0F00) >> 8) + 1);
        return true;
    }

};

#endif







