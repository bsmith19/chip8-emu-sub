#include <gtest/gtest.h>
#include <cpu/Memory.h>
#include <fstream>

class MemoryTests : public ::testing::Test
{};

TEST_F(MemoryTests, load_font_test)
{
    //define font
    unsigned char* mem_raw = new unsigned char[80] {
     0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
     0x20, 0x60, 0x20, 0x20, 0x70, // 1
     0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
     0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
     0x90, 0x90, 0xF0, 0x10, 0x10, // 4
     0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
     0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
     0xF0, 0x10, 0x20, 0x40, 0x40, // 7
     0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
     0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
     0xF0, 0x90, 0xF0, 0x90, 0x90, // A
     0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
     0xF0, 0x80, 0x80, 0x80, 0xF0, // C
     0xE0, 0x90, 0x90, 0x90, 0xE0, // D
     0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
     0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };
    
    //convert to unique pointer
    std::unique_ptr<unsigned char> uFont (mem_raw);
    
    //Create memory map
    std::map<EMemoryPartitions, int> map;
    map.insert({Font, 0});
    map.insert({Rom, 511});
    
    //Create memory and load font
    Memory* mem = new Memory(1024, map);
    EXPECT_EQ(mem->LoadFont(uFont, 80), true);
    
    //Cleanup
    delete mem;
}

TEST_F(MemoryTests, load_rom_test)
{
    //Create memory map
    std::map<EMemoryPartitions, int> map;
    map.insert({ Font, 0 });
    map.insert({ Rom, 511 });

    //load rom from file
    std::ifstream aFile;
    aFile.open("pong2.c8", std::ios::binary | std::ios::ate);

    //Verify files if found and open
    EXPECT_EQ(aFile.is_open(), true);

    std::streampos size = aFile.tellg();
    EXPECT_FALSE(size == 0);

    //Set to start of file..
    aFile.seekg(0, std::ios::beg);

    //load from file
    char* romData = new char[size];
    aFile.read(romData, size);
    std::unique_ptr<char> rom(romData);

    //Create memory and load rom
    Memory* mem = new Memory(1024, map);
    EXPECT_EQ(mem->LoadRom(rom, size), true);

    delete mem;

}

TEST_F(MemoryTests, get_opecode_test)
{
    //Create memory map
    std::map<EMemoryPartitions, int> map;
    map.insert({ Font, 0 });
    map.insert({ Rom, 512 });

    //load rom from file(initial pos is EOF due to ios::ate)
    std::ifstream aFile;
    aFile.open("pong2.c8", std::ios::binary | std::ios::ate);

    //Verify files if found and open
    EXPECT_EQ(aFile.is_open(), true);

    std::streampos size = aFile.tellg();
    EXPECT_FALSE(size == 0);

    //Set to start of file..
    aFile.seekg(0, std::ios::beg);

    //load from file
    char* romData = new char[size];
    aFile.read(romData, size);
    std::unique_ptr<char> rom(romData);

    //Create memory and load rom
    Memory* mem = new Memory(1024, map);
    EXPECT_EQ(mem->LoadRom(rom, size), true);

    //Get first opcode of rom, 0x200(512) is begining of program space
    unsigned short opcode = mem->GetOpCode(0x200);
    EXPECT_EQ(opcode, 0x22FC);
}
