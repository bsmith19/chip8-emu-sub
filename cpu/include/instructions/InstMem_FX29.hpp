#ifndef __INSTMEM_FX29_HPP__
#define __INSTMEM_FX29_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMem_FX29: Inst
{
public:
    InstMem_FX29(unsigned short opcode) : Inst(opcode) {};
    ~InstMem_FX29() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets I to the location of the sprite for the character in VX. Characters 0-F (in hexadecimal) are represented by a 4x5 font.
        systemData->systemIndexRegister = (ushort)(systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] * 0x5);
        systemData->systemProgramCounter += 2;

        return true;
    }

};

#endif







