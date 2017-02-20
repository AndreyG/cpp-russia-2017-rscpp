#pragma once

#include <iostream>

namespace a
{
    namespace b
    {
        constexpr auto value1 = "a::b";
    }

    namespace c
    {
        constexpr auto value2 = "a::c";
    }

    namespace x
    {
        constexpr auto value1 = "a::x";
        constexpr auto value2 = "a::x";

        namespace y
        {
            using b::value1;
            using namespace c;

            namespace z
            {
                inline void run()
                {
                    std::cout << "value1: " << value1 << "\n"
                              << "value2: " << value2 << "\n";
                }
            }
        }
    }
}
