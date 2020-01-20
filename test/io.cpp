
#include "gtest/gtest.h"
#include "io_lib.h"

#include <iostream>
#include <sstream>
#include <string>

auto constexpr example_program_raw = "\
++ Cell c0 = 2\
> +++++ Cell c1 = 5\
\
[ Start your loops with your cell pointer on the loop counter(\
c1 in our case) \
< + Add 1 to c0\
> - Subtract 1 from c1\
] End your\
loops with the cell pointer on the loop counter\
\
At this point our program has added 5 to 2 leaving 7 in\
c0 and 0 in c1 but we cannot output this value to the\
terminal since it is not ASCII encoded !\
\
To display the ASCII character \"7\" we must add 48 to the value 7 48 =\
6 * 8 so let's use another loop to help us!\
\
++++++++ c1 = 8 and this will be our loop counter again\
[<++++++ Add 6 to c0\
> - Subtract 1 from c1\
]\
<. Print out c0 which has the value 55 which translates to \"7\" !\
";

auto constexpr example_program_stripped = 
"++>+++++[<+>-]++++++++[<++++++>-]<.";

TEST(IOTestSuit, ReadSinglLine)
{
    std::istringstream input{};
    auto const test_string = "test\n\\\\\n";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ("test\n", result.c_str());
}

TEST(IOTestSuit, ReadMultipleLines)
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
TEST(IOTestSuit, IgnoreRemainingText)
{
    std::istringstream input{};
    auto const test_string = "test\ntest line 2\n\\\\\njunk";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ("test\ntest line 2\n", result.c_str());
}

/*
 * \brief Test reading complex program
 */
TEST(IOTestSuit, ComplexProgram)
{
    std::istringstream input{};
    auto const test_string = std::string{example_program_raw} + "\\\\";
    input.str(test_string);
    auto const result = read_program(input);
    EXPECT_STREQ(example_program_raw, result.c_str());
}

/*
 * \brief Test removing characters not part of bf command set.
 */
TEST(IOTestSuit, StripComments)
{
    auto const result = strip_program(example_program_raw);
    EXPECT_STREQ(example_program_stripped, result.c_str());
}