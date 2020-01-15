
#include "gtest/gtest.h"
#include "io_lib.h"

//TEST(example_test_suit, example_test){EXPECT_EQ(2*2*2, cubic(2));}

TEST(example_test_suit, example_text)
{
    std::ostringstream os{};
    hello_world(os);
    EXPECT_EQ(os.str(), "hello world\n");
}

