#include <gtest/gtest.h>
#include "util/slice.h"
#include "util/logger.h"
#include <string>

using namespace yodb;

TEST(Slice, constructor) 
{
    EXPECT_EQ(Slice().size(), 0U);
    EXPECT_LT(Slice(), Slice("a"));
    EXPECT_LT(Slice("a"), Slice("ab"));
    EXPECT_TRUE(Slice("a") == Slice("ab", 1));
    EXPECT_EQ(Slice(std::string("ab")), Slice("ab"));
}

TEST(Slice, empty) 
{
    EXPECT_TRUE(Slice().empty());
    EXPECT_TRUE(Slice("").empty());
    EXPECT_FALSE(Slice("a").empty());
}

TEST(Slice, clear) 
{
    Slice ab("ab");
    ab.clear();
    EXPECT_EQ(ab, Slice());
}
