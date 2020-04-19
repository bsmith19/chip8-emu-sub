#ifndef __INSTBITOP_8XY2_HPP__
#define __INSTBITOP_8XY2_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstBitOp_8XY2 : Inst
{
public:
    InstBitOp_8XY2(unsigned short opcode) : Inst(opcode) {};
    ~InstBitOp_8XY2() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //Sets VX to VX and VY. (Bitwise AND operation)
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4] & systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8];

        //increment program counter
        systemData->systemProgramCounter += 2;

        return true;
    }

};

#endif
