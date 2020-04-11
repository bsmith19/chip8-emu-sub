#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <map>
#include <memory>

enum EMemoryPartitions
{
    None = 0,
    Font,
    Rom
};

class Memory
{
public:
    Memory(int memorySize, const std::map<EMemoryPartitions, int>& memoryMap);
    ~Memory();
    
public:
    bool LoadFont(std::unique_ptr<unsigned char>& font, int size);
    bool LoadRom(std::unique_ptr<unsigned char>& rom, int size);
    unsigned short GetOpCode(unsigned short programCounter);
    
private:
    int mMemorySize;
    std::map<EMemoryPartitions, int> mMemoryMaps;
    unsigned char* mMemory;
};

#endif
