
#include "gtest/gtest.h"
#include "io_lib.h"

#include <iostream>
#include <sstream>

TEST(example_test_suit, example_text)
{
    std::ostringstream os{};
    hello_world(os);
    EXPECT_EQ(os.str(), "hello world\n");
}

TEST(io_test_suit, read_single_line)
{
    std::istringstream input{};
    auto const test_string = "test\n";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ(test_string, result.c_str());
}

TEST(io_test_suit, read_multiple_lines)
{
    std::istringstream input{};
    auto const test_string = "test\ntest line 2\n";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ(test_string, result.c_str());
}