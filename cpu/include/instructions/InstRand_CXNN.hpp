#ifndef __INSTRAND_CXNN_HPP__
#define __INSTRAND_CXNN_HPP__
#include "instructions/Inst.h"
#include "cpu/CpuData.h"
#include <random>

class InstRand_CXNN: Inst
{
public:
    InstRand_CXNN(unsigned short opcode) : Inst(opcode) {};
    ~InstRand_CXNN() {};

public:
    virtual bool Handle(std::shared_ptr<CpuData> systemData)
    {
        // Sets VX to the result of a bitwise AND operation on a random number (Typically: 0 to 255) and NN.
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<unsigned short> dist(0, 255);
        
        unsigned short randomNum = dist(mt);
        systemData->systemCpuRegisters[(mOpCode & 0x0F00) >> 8] = (unsigned char)((mOpCode & 0x00FF) & randomNum);
        systemData->systemProgramCounter += 2;
        
        return true;
    }

};

#endif







