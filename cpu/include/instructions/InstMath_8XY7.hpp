#ifndef __INSTMATH_8XY7_HPP__
#define __INSTMATH_8XY7_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMath_8XY7: Inst
{
public:
    InstMath_8XY7(unsigned short opcode) : Inst(opcode) {};
    ~InstMath_8XY7() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
        if(systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] > systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4])
        {
            // set the borrow here
            systemData->systemCpuRegisters[0xF] = 0;
        }
        else
        {
            //no borrow, continue on
            systemData->systemCpuRegisters[0xF] = 1;
        }

        // subtract here
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = (unsigned char)(systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4] - systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8]);
        systemData->systemProgramCounter += 2;
        
        return true;
    }

};

#endif







