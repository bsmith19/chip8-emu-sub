#include <gtest/gtest.h>
#include <instructions/InstCond_3XNN.hpp>

class InstCond_3XNNTests : public ::testing::Test
{
public:
    void SetUp();
    void TearDown();
    
protected:
    std::shared_ptr<CpuData> mSystemData;
};

void InstCond_3XNNTests::SetUp()
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

void InstCond_3XNNTests::TearDown()
{
}

TEST_F(InstCond_3XNNTests, handle_test_pass)
{
    //Setup initial register values
    mSystemData->systemCpuRegisters[2] = 7;
    mSystemData->systemCpuRegisters[0x1] = 0x20;
    
    InstCond_3XNN* in = new InstCond_3XNN(0x3120);
    EXPECT_TRUE(in->Handle(mSystemData));
    
    EXPECT_EQ(mSystemData->systemCpuRegisters[2], 7);
    EXPECT_EQ(mSystemData->systemCpuRegisters[0x1], 0x20);
    EXPECT_EQ(mSystemData->systemProgramCounter, 0x200 + 4);
    
    delete in;
}

TEST_F(InstCond_3XNNTests, handle_test_fail)
{
    //Setup initial register values
    mSystemData->systemCpuRegisters[2] = 7;
    mSystemData->systemCpuRegisters[0x1] = 0x21;
    
    InstCond_3XNN* in = new InstCond_3XNN(0x3120);
    EXPECT_TRUE(in->Handle(mSystemData));
    
    EXPECT_EQ(mSystemData->systemCpuRegisters[2], 7);
    EXPECT_EQ(mSystemData->systemCpuRegisters[0x1], 0x21);
    EXPECT_EQ(mSystemData->systemProgramCounter, 0x200 + 2);
    
    delete in;
}


