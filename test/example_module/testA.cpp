#include "gtest/gtest.h"

#include "add.h"

TEST(AddTest, HandlesPositiveInput)
{
    EXPECT_EQ(3, add(1, 2));
    EXPECT_EQ(29, add(20, 9));
}

TEST(AddTest, HandlesNegativeInput)
{
    EXPECT_EQ(3, add(5, -2));
    EXPECT_EQ(-5, add(-4, -1));
    EXPECT_EQ(0, add(3, -3));
}

TEST(AddTest, HandlesZeroInput)
{
    EXPECT_EQ(2, add(0, 2));
    EXPECT_EQ(8, add(8, 0));
    EXPECT_EQ(0, add(0, 0));
    EXPECT_EQ(-3, add(0, -3));
}

// Failure Case