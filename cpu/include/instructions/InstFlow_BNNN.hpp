#ifndef __INSTFLOW_BNNN_HPP__
#define __INSTFLOW_BNNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstFlow_BNNN: Inst
{
public:
    InstFlow_BNNN(unsigned short opcode) : Inst(opcode) {};
    ~InstFlow_BNNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //Jumps to address of NNN plus V0, Since it a jump no PC increase
        systemData->systemProgramCounter = (ushort)(systemData->systemCpuRegisters[0] + (mOpCode & 0x0FFF));
        return true;
    }

};

#endif







