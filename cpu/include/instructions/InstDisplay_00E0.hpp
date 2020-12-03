#ifndef __INSTDISPLAY_00E0_HPP__
#define __INSTDISPLAY_00E0_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstDisplay_00E0 : Inst
{
public:
    InstDisplay_00E0(unsigned short opcode) : Inst(opcode) {};
    ~InstDisplay_00E0() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // TODO: Must implement this after I have a solution to drawing
        // TODO: This Clears the buffer/screen
        return true;
    }

};

#endif





