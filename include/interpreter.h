#pragma once

#include <array>
namespace bf
{
    auto constexpr data_stack_size = 30000;
    using data_stack_type = std::array<char,data_stack_size>;

    inline auto increment_data_pointer(data_stack_type::iterator data_pointer) {
        return ++data_pointer;
    }
}
