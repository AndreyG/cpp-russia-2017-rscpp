#pragma once

#include "uniform_fwd.h"

namespace ejk
{
    class IUniform
    {
    protected:
        ~IUniform() = default;

    public:
        template <class T>
        Uniform<T>& cast();
    };

    template <class T>
    class Uniform : public IUniform
    {
    protected:
        ~Uniform() = default;
    public:
        virtual void set(T const &) = 0;
    };

    template <class T>
    UniformPtr<T> cast(IUniformPtr uniform)
    {
        auto typed_uniform = &uniform->cast<T>();
        return{ move(uniform), typed_uniform };
    }
}
