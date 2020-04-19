#ifndef __CPUDATA_H__
#define __CPUDATA_H__
#include <memory>
#include <vector>

//Local includes
#include "cpu/Stack.h"
#include "cpu/Memory.h"

struct CpuData
{
    std::unique_ptr<Stack> systemStack;
    std::unique_ptr<Memory> systemMemory;
    std::vector<unsigned char> systemCpuRegisters;
    unsigned short systemProgramCounter;
    unsigned short systemIndexRegister;

    unsigned char systemTimer;
    unsigned char delayTimer;
};

#endif