
#include <gtest/gtest.h>
#include <instructions/InstConst_7XNN.hpp>

class InstConst_7XNNTests : public ::testing::Test
{
public:
    void SetUp();
    void TearDown();
    
protected:
    std::shared_ptr<CpuData> mSystemData;
};

void InstConst_7XNNTests::SetUp()
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

void InstConst_7XNNTests::TearDown()
{
}

TEST_F(InstConst_7XNNTests, handle_test_pass)
{
    //Setup initial register values
    mSystemData->systemCpuRegisters[0x2] = 7;
    mSystemData->systemCpuRegisters[0x1] = 8;
    
    InstConst_7XNN* in = new InstConst_7XNN(0x5120);
    EXPECT_TRUE(in->Handle(mSystemData));
    
    EXPECT_EQ(mSystemData->systemCpuRegisters[0x2], 7);
    EXPECT_EQ(mSystemData->systemCpuRegisters[0x1], 40);
    EXPECT_EQ(mSystemData->systemProgramCounter, 0x200 + 2);
    
    delete in;
}






