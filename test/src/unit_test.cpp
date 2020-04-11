#include <iostream>

#include <gtest/gtest.h>

class UnitTests : public ::testing::Test
{};

TEST_F(UnitTests, simple)
{
    EXPECT_EQ(1, 1);
}

TEST_F(UnitTests, will_fail)
{
    EXPECT_EQ(1, 1);
}

