#include "cpu/Memory.h"

Memory::Memory(int memorySize, const std::map<EMemoryPartitions, int>& memoryMap)
{
    mMemorySize = memorySize;
    mMemoryMaps = memoryMap;
    
    mMemory = new unsigned char[memorySize];
}

Memory::~Memory()
{
    delete mMemory;
}

bool Memory::LoadRom(std::unique_ptr<char>& romData, int size)
{
    // Need to check if the game can actually fit in memory first..
    int rom_available_size = mMemorySize - mMemoryMaps[Rom];
    
    if(size <= rom_available_size)
    {
        for(int i = 0; i < size; i++)
        {
            mMemory[mMemoryMaps[Rom] + i] = romData.get()[i];
        }
        
        return true;
    }
    
    return false;
}

bool Memory::LoadFont(std::unique_ptr<unsigned char>& fontData, int size)
{
    // Need to check if the game can actually fit in memory first..
    int font_available_size = mMemorySize - mMemoryMaps[Font];
    
    if(size <= font_available_size)
    {
        for(int i = 0; i < size; i++)
        {
            mMemory[mMemoryMaps[Font] + i] = fontData.get()[i];
        }
        
        return true;
    }
    
    return false;
}

unsigned short Memory::GetOpCode(unsigned short programCounter)
{
    //Opcode is 2 bytes, so we need to pull them both out
    unsigned char op1 = mMemory[programCounter];
    unsigned char op2 = mMemory[programCounter + 1];
    
    //Merge two parts to one opcode
    unsigned short opCode = op1 << 8 | op2;
    return opCode;
}
