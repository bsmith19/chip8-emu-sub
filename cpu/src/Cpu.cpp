#include "cpu/Cpu.h"

Cpu::Cpu(int stackSize, int memorySize, int programSpace)
{
    mSystemStorage = std::make_unique<CpuData>();

    //TODO: read this info from memory map
    mSystemStorage->systemIndexRegister = 0;
    mSystemStorage->systemProgramCounter = 0x200;

    //Define memory layout
    std::map<EMemoryPartitions, int> memMap;
    memMap.insert({ Font, 0 });
    memMap.insert({ Rom, 512 }); //511?

    //Create Other System componenets
    mSystemStorage->systemStack = std::make_unique<Stack>(stackSize);
    mSystemStorage->systemMemory = std::make_unique<Memory>(memorySize, memMap);
    mSystemStorage->systemCpuRegisters = std::unique_ptr<unsigned char>(new unsigned char[16]);
}

Cpu::~Cpu()
{

}

bool Cpu::EmulateCycle()
{
    // fetch opcode
    unsigned short opcode = mSystemStorage->systemMemory->GetOpCode(mSystemStorage->systemProgramCounter);

    //Pick the correct instruction

    //update the timers

    return true;
}