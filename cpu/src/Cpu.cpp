#include "cpu/Cpu.h"
#include "cpu/CpuData.h"
#include "instructions/InstAssign_8XY0.hpp"

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
    mSystemStorage->systemCpuRegisters = std::vector<unsigned char>(16);
}

Cpu::~Cpu()
{

}

bool Cpu::EmulateCycle()
{
    // fetch opcode
    unsigned short opcode = mSystemStorage->systemMemory->GetOpCode(mSystemStorage->systemProgramCounter);

    //Pick the correct instruction
    InstAssign_8XY0* inst = new InstAssign_8XY0(0x8220);
    inst->Handle(mSystemStorage);
    delete inst;
    //update the timers

    return true;
}