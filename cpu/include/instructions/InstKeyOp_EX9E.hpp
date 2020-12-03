#ifndef __INSTKEYOP_EX9E_HPP__
#define __INSTKEYOP_EX9E_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstKeyOp_EX9E: Inst
{
public:
    InstKeyOp_EX9E(unsigned short opcode) : Inst(opcode) {};
    ~InstKeyOp_EX9E() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Skips the next instruction if the key stored in VX is pressed. (Usually the next instruction is a jump to skip a code block)
        // TODO: Skip this until I have a solution for input
        return true;
    }

};

#endif







