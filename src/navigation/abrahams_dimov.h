#pragma once

#include <iostream>

namespace abrahams_dimov
{
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
        inline int foo<>(int *)
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
        inline int foo<>(int *)
        {
            return 3;
        }

        template<class T>
        int foo(T *)
        {
            return 2;
        }
    }

    inline void run()
    {
        int * p = nullptr;
        std::cout << "Abrahams/Dimov example (v1): function " << v1::foo(p) << " will be called\n";
        std::cout << "Abrahams/Dimov example (v2): function " << v2::foo(p) << " will be called\n";
    }
}
