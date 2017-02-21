#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

namespace lib
{
    struct S
    {
        int value;
    };

    void print(std::ostream& out, std::vector<S> const & vec)
    {
        out << "vector size: " << vec.size() << "\n";
        for (auto const & s : vec)
            out << "value = " << s.value << "\n";
    }
}

namespace app
{
    template<class T>
    void print(std::ostream& out, std::vector<T> const & vec)
    {
        out << "[";
        for (auto const & e : vec)
            out << "(value = " << e.value << ")";
        out << "]\n";
    }

    void run()
    {
        std::vector<lib::S> v = {
            { 1 }, { 2 }, { 3 }
        };
        print(std::cout, v);
        (print)(std::cout, v);
    }
}

int main()
{
    app::run();
}