#pragma once

#include <utility>

template<class T>
struct intrusive_ptr
{
    explicit intrusive_ptr(T * ptr)
    {
        assign(ptr);
    }

    ~intrusive_ptr()
    {
        destroy();
    }

    intrusive_ptr(intrusive_ptr const & other)
    {
        assign(other.ptr_);
    }

    intrusive_ptr& operator = (intrusive_ptr const & other)
    {
        if (&other != this)
        {
            destroy();
            assign(other.ptr_);
        }
        return *this;
    }

    intrusive_ptr(intrusive_ptr && other)
        : ptr_(other.ptr_)
    {
        if (&other != this)
            other.ptr_ = nullptr;
    }

    intrusive_ptr& operator = (intrusive_ptr && other)
    {
        std::swap(ptr_, other.ptr_);
        return *this;
    }

private:
    void assign(T * ptr)
    {
        ptr_ = ptr;
        if (ptr)
            ptr->add_ref();
    }

    void destroy()
    {
        if (ptr_ && ptr_->release() == 0)
            delete ptr_;
    }

private:
    T * ptr_;
};
