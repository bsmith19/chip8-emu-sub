#ifndef __INSTFLOW_00EE_HPP__
#define __INSTFLOW_00EE_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstFlow_00EE: Inst
{
public:
    InstFlow_00EE(unsigned short opcode) : Inst(opcode) {};
    ~InstFlow_00EE() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Exit a Subroutine, pull old spot of stack
        systemData->systemProgramCounter = systemData->systemStack->PopStack();
        
        // increment to the next line
        systemData->systemProgramCounter += 2;
        
        return true;
    }

};

#endif






