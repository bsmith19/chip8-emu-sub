#ifndef __INSTKEYOP_FX0A_HPP__
#define __INSTKEYOP_FX0A_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstKeyOp_FX0A: Inst
{
public:
    InstKeyOp_FX0A(unsigned short opcode) : Inst(opcode) {};
    ~InstKeyOp_FX0A() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // A key press is awaited, and then stored in VX. (Blocking Operation. All instruction halted until next key event).
        return true;
    }

};

#endif







