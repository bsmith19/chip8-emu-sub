#include <gtest/gtest.h>
#include <instructions/InstBitOp_8XY6.hpp>

class InstBitOp_8XY6Tests : public ::testing::Test
{
public:
    void SetUp();
    void TearDown();
    
protected:
    std::shared_ptr<CpuData> mSystemData;
};

void InstBitOp_8XY6Tests::SetUp()
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

void InstBitOp_8XY6Tests::TearDown()
{
}

TEST_F(InstBitOp_8XY6Tests, handle_test)
{
    //Setup initial register values
    mSystemData->systemCpuRegisters[2] = 7;
    mSystemData->systemCpuRegisters[1] = 8;
    
    InstBitOp_8XY6* in = new InstBitOp_8XY6(0x8126);
    EXPECT_TRUE(in->Handle(mSystemData));
    
    EXPECT_EQ(mSystemData->systemCpuRegisters[2], 3);
    EXPECT_EQ(mSystemData->systemCpuRegisters[1], 3);
    
    delete in;
}

