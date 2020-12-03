#ifndef __INSTKEYOP_EXA1_HPP__
#define __INSTKEYOP_EXA1_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstKeyOp_EXA1: Inst
{
public:
    InstKeyOp_EXA1(unsigned short opcode) : Inst(opcode) {};
    ~InstKeyOp_EXA1() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //  the next instruction if the key stored in VX isn't pressed. (Usually the next instruction is a jump to skip a code block)
        // TODO: comeback to this once input is figured out
        return true;
    }

};

#endif







