#pragma once

#include "uniform_fwd.h"

namespace ejk
{
    class IShaderProgram
    {
    protected:
        ~IShaderProgram() = default;

    public:
        virtual IUniformPtr uniform(const char* name) = 0;
    };
}
