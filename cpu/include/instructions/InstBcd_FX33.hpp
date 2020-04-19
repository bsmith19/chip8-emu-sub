#ifndef __INSTBCD_FX33_HPP__
#define __INSTBCD_FX33_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"

class InstBcd_FX33 : Inst
{
public:
    InstBcd_FX33(unsigned short opcode) : Inst(opcode) {};
    ~InstBcd_FX33() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Stores the binary-coded decimal representation of VX, with the most significant of three digits at the address in I, 
        // the middle digit at I plus 1, and the least significant digit at I plus 2. 
        // (In other words, take the decimal representation of VX, place the hundreds digit in memory at location in I, 
        // the tens digit at location I+1, and the ones digit at location I+2.)

        *systemData->systemMemory[static_cast<int>(systemData->systemIndexRegister)] = systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] / 100;
    }

};

#endif