#include <iostream>

#include <gtest/gtest.h>

class MemoryTests : public ::testing::Test
{};

TEST_F(MemoryTests, simple)
{
    EXPECT_EQ(1, 1);
}

TEST_F(MemoryTests, will_fail)
{
    EXPECT_EQ(1, 2);
}

