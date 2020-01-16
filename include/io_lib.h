#pragma once

#include <iostream>
inline std::ostream & hello_world(std::ostream & os)
{
    os << "hello world\n";
    return os;
}


/**
 * \brief read the whole bf program from an input source.
 * \todo test with cin.
 * \param input input source to read from.
 * \return the read in bf program.
 */
inline auto read_program(std::istream & input)
{
    auto buffer = std::string{};
    auto constexpr buffer_size = 100000;
    buffer.resize(buffer_size);
    auto characters_read = decltype(input.gcount()){};
    characters_read += input.readsome(buffer.data(), buffer.capacity());
    buffer.resize(characters_read);
    return buffer;
}