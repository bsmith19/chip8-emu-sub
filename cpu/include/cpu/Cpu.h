#ifndef __CPU_H__
#define __CPU_H__

#include <memory>

struct CpuData;

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