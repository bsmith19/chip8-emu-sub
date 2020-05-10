#ifndef __INSTCOND_5XY0_HPP__
#define __INSTCOND_5XY0_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstCond_5XY0 : Inst
{
public:
    InstCond_5XY0(unsigned short opcode) : Inst(opcode) {};
    ~InstCond_5XY0() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //Must shift 8 in CpuRegister to make if X instead of X0000000 for the index
        //Must shift 4 in 2nd CPURegister since we are pull one digit closeer to the right
        //Skips the next instruction if vX == vY
        if(systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] == systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4])
        {
            //skip 4 bytes instead of 2
            systemData->systemProgramCounter += 4;
            return true;
        }
        
        //skip the normal 2
        systemData->systemProgramCounter += 2;
        return true;
    }

};

#endif


