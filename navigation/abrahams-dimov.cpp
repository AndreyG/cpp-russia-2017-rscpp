#pragma once

#include <iostream>

namespace v1
{
    template<class T>
    int foo(T)
    {
        return 1;
    }

    template<class T>
    int foo(T *)
    {
        return 2;
    }

    template<>
    int foo<>(int *)
    {
        return 3;
    }
}

namespace v2
{
    template<class T>
    int foo(T)
    {
        return 1;
    }

    template<>
    int foo<>(int *)
    {
        return 3;
    }

    template<class T>
    int foo(T *)
    {
        return 2;
    }
}

int main()
{
    int * p = nullptr;
    std::cout << "v1: function " << v1::foo(p) << " will be called\n";
    std::cout << "v2: function " << v2::foo(p) << " will be called\n";
}
