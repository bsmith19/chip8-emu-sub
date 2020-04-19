
#include <gtest/gtest.h>
#include <instructions/InstBcd_FX33.hpp>

class InstBcd_FX33Tests : public ::testing::Test
{
public:
    void SetUp();
    void TearDown();
    
protected:
    std::shared_ptr<CpuData> mSystemData;
};

void InstBcd_FX33Tests::SetUp()
{
    // create memory map
    std::map<EMemoryPartitions, int> partitionMap;
    partitionMap.insert({ Font, 0 });
    partitionMap.insert({ Rom, 512 });
    
    // build cpu data
    mSystemData = std::make_shared<CpuData>();
    mSystemData->delayTimer = 1;
    mSystemData->systemIndexRegister = 1;
    mSystemData->systemCpuRegisters = std::vector<unsigned char>(16);
    mSystemData->systemMemory = std::make_unique<Memory>(1024, partitionMap);
    mSystemData->systemProgramCounter = 0x200;
    mSystemData->systemStack = std::make_unique<Stack>(16);
    mSystemData->systemTimer = 10;
}

void InstBcd_FX33Tests::TearDown()
{
}

TEST_F(InstBcd_FX33Tests, handle_test)
{
    //Setup index register value
    mSystemData->systemIndexRegister = 548;
    
    //Setup initial register values
    mSystemData->systemCpuRegisters[2] = 235;
    mSystemData->systemCpuRegisters[1] = 8;
    mSystemData->systemCpuRegisters[8] = 255;
    
    InstBcd_FX33* in = new InstBcd_FX33(0xF233);
    EXPECT_TRUE(in->Handle(mSystemData));
    
    //Verify registers didn't change
    EXPECT_EQ(mSystemData->systemCpuRegisters[2], 235);
    EXPECT_EQ(mSystemData->systemCpuRegisters[1], 8);
    
    //verify new values in memory
    EXPECT_EQ(mSystemData->systemMemory->GetByte(548), 2);
    EXPECT_EQ(mSystemData->systemMemory->GetByte(549), 3);
    EXPECT_EQ(mSystemData->systemMemory->GetByte(550), 5);
    
    delete in;
}
