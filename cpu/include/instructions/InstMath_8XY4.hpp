#ifndef __INSTMATH_8XY4_HPP__
#define __INSTMATH_8XY4_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstMath_8XY4: Inst
{
public:
    InstMath_8XY4(unsigned short opcode) : Inst(opcode) {};
    ~InstMath_8XY4() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.
        //0xF(16) - Call location in memory
        if(systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4] > (0xFF - systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8]))
        {
             //Set carry to 1
            systemData->systemCpuRegisters[0xF] = 1;
        }
        else
        {
            //Set carry to 0
            systemData->systemCpuRegisters[0xF] = 0;
        }

        //add the memory locations
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] += systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4];
        systemData->systemProgramCounter += 2;

        return true;
    }

};

#endif







