#pragma once

#include <iostream>
#include <algorithm>
#include <array>
#include <type_traits>

auto constexpr valid_commands =
    std::array{'>', '<', '+', '-', '.', ',', '[', ']'};

/**
 * \brief read the whole bf program from an input source. Stop after reading two consecutive '\\'.
 * \param input input source to read from.
 * \return the read in bf program.
 */
inline auto read_program(std::istream & input)
{
    auto buffer = std::string{};
    auto result = std::string{};
    auto constexpr buffer_size = 100000;
    buffer.resize(buffer_size);
    auto characters_read = decltype(input.gcount()){};

    auto previous_character = '\0';
    for (auto && current_character : buffer)
    {
        input.get(current_character);
        characters_read += 1;
        if (current_character == '\\' && previous_character == '\\')
        {
            characters_read -= 2;// discard last 2 characters which is "\\\\"
            break;
        }
        previous_character = current_character;
    }

    buffer.resize(characters_read);
    return buffer;
}

inline auto strip_program(std::string program)
{
    using character_type = std::remove_reference_t<decltype(program)>::value_type;
    auto const end_of_valid_program = std::remove_if(std::begin(program), std::end(program), 
        [](character_type const character) {
            return std::find(std::begin(valid_commands), std::end(valid_commands),
                character) == std::end(valid_commands);
    });
    return std::string(std::begin(program), end_of_valid_program);
}