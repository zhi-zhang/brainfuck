#include "interpreter.h"

#include "gtest/gtest.h"
#include <array>

namespace
{

class InterpreterTest : public ::testing::TestWithParam<std::size_t>
{
public:
    void SetUp() override
    {
        index_ = GetParam();
        data_stack_[index_ + 1] = indicator_value;
    }
    void TearDown() override{}

protected:
    static char constexpr indicator_value = 'H';
    bf::data_stack_type data_stack_ {};
    std::size_t index_ {};
};
    
TEST_P(InterpreterTest, increment_data_pointer)
{
    auto const data_pointer =
        bf::increment_data_pointer(std::begin(data_stack_)+index_);
    EXPECT_EQ(indicator_value,
        *bf::increment_data_pointer(std::begin(data_stack_) + index_));
}

INSTANTIATE_TEST_SUITE_P(
    InterpreterTestSuit, InterpreterTest,
    // last valid data stack pointer is (data_stack_size-1)
    ::testing::Values(0, 1, 100, 1000, 10000, bf::data_stack_size-2));
} // namespace
/*
 * \brief Increment 
 */

