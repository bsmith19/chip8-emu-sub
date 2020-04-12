#include <gtest/gtest.h>
#include <cpu/Stack.h>

class StackTests : public ::testing::Test
{
public:
    virtual void SetUp();
    virtual void TearDown();
protected:
    Stack* stk;
};

void StackTests::SetUp()
{
    stk = new Stack(16);
}

void StackTests::TearDown()
{
    delete stk;
}

TEST_F(StackTests, pop_stack_test)
{
    unsigned short programCounter = 0x200;
    unsigned short instrIncr = 2;

    EXPECT_TRUE(stk->PushStack(programCounter));

    programCounter += instrIncr;
    programCounter += instrIncr;
    EXPECT_TRUE(stk->PushStack(programCounter));

    programCounter += instrIncr;
    programCounter += instrIncr;
    programCounter += instrIncr;
    EXPECT_TRUE(stk->PushStack(programCounter));

    EXPECT_EQ(stk->PopStack(), 0x20A);
    EXPECT_EQ(stk->PopStack(), 0x204);
    EXPECT_EQ(stk->PopStack(), 0x200);
}

TEST_F(StackTests, push_stack_test)
{
    unsigned short programCounter = 0x200;
    unsigned short instrIncr = 2;

    EXPECT_TRUE(stk->PushStack(programCounter));

    programCounter += instrIncr;
    EXPECT_TRUE(stk->PushStack(programCounter));

    programCounter += instrIncr;
    EXPECT_TRUE(stk->PushStack(programCounter));
}
