
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
    auto const test_string = "test\n\\\\\n";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ("test\n", result.c_str());
}

TEST(io_test_suit, read_multiple_lines)
{
    std::istringstream input{};
    auto const test_string = "test line 1\ntest line 2\n\\\\\n";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ("test line 1\ntest line 2\n", result.c_str());
}


/**
 * \brief Test read_program stop after reading two consecutive '\\'.
 */
TEST(io_test_suit, ignore_remaining_text)
{
    std::istringstream input{};
    auto const test_string = "test\ntest line 2\n\\\\\njunk";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ("test\ntest line 2\n", result.c_str());
}