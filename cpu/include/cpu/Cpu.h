#ifndef __CPU_H__
#define __CPU_H__

#include <memory>
#include "cpu/Memory.h"
#include "cpu/Stack.h"


struct CpuData
{
    std::unique_ptr<Stack> systemStack;
    std::unique_ptr<Memory> systemMemory;
    std::unique_ptr<unsigned char> systemCpuRegisters;
    unsigned short systemProgramCounter;
    unsigned short systemIndexRegister;

    unsigned char systemTimer;
    unsigned char delayTimer;
};

class Cpu
{
public:
    Cpu(int stackSize, int memorySize, int programSpace);
    ~Cpu();

public:
    bool EmulateCycle();

private:
    std::shared_ptr<CpuData> mSystemStorage;
};

#endif