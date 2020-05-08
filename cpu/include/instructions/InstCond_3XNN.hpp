#ifndef __INSTCOND_3XNN_HPP__
#define __INSTCOND_3XNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstCond_3XNN : Inst
{
public:
    InstCond_3XNN(unsigned short opcode) : Inst(opcode) {};
    ~InstCond_3XNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //Must shift 8 in CpuRegister to make if X instead of X0000000 for the index
        //Skips the next instruction if vX == NN
        int x = (mOpCode & 0x00F0) << 4 | (mOpCode & 0x000F);
        int y = systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8];
        if(systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] == (mOpCode & 0x00FF))
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
