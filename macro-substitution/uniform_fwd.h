#pragma once

#include <memory>

namespace ejk
{
    class IUniform;
    using IUniformPtr = std::shared_ptr<IUniform>;

    template <class T>
    class Uniform;

    template <class T>
    using UniformPtr = std::shared_ptr<Uniform<T>>;

    template <class T>
    UniformPtr<T> cast(IUniformPtr);
}