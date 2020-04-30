#ifndef __INSTBITOP_8XY6_HPP__
#define __INSTBITOP_8XY6_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstBitOp_8XY6 : Inst
{
public:
    InstBitOp_8XY6(unsigned short opcode) : Inst(opcode) {};
    ~InstBitOp_8XY6() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        //Set register VF to the least significant bit of VY prior to the shift
        systemData->systemCpuRegisters[0xF] = systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4] & 0x1;

        //Sets VX to VY >> 1
        systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4] >>= 1;
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = systemData->systemCpuRegisters[(mOpCode & 0x00F0) >> 4];

        //increment program counter
        systemData->systemProgramCounter += 2;

        return true;


        //Set register VF to the least significant bit of VY prior to the shift
        //systemData->systemCpuRegisters[0xF] = systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] & 0x1;

        //Sets VX to VX >> 1. (Bitwise SHR operation)
        //systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] >>= 1;

        //increment program counter
        //systemData->systemProgramCounter += 2;

        //return true;
    }

};

#endif
