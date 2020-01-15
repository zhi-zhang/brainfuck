#pragma once

#include <iostream>

inline std::ostream & hello_world(std::ostream & os)
{
    os << "hello world\n";
    return os;
}