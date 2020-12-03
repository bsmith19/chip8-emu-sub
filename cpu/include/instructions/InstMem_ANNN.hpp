#ifndef __INSTMEM_ANNN_HPP__
#define __INSTMEM_ANNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMem_ANNN: Inst
{
public:
    InstMem_ANNN(unsigned short opcode) : Inst(opcode) {};
    ~InstMem_ANNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets I to the address NNN.
        systemData->systemIndexRegister = (ushort)(mOpCode & 0x0FFF);
        systemData->systemProgramCounter += 2;
        return true;
    }

};

#endif







