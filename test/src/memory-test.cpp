#include <gtest/gtest.h>
#include <cpu/Memory.h>

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