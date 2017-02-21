#include "intrusive-ptr.h"

#include <vector>
#include <cassert>

class class_with_8bit_counter
{
public:
    // ACHTUNG!!! 8-bit
    typedef std::uint8_t counter_t;

    void add_ref()
    {
        ++counter_;
    }

    counter_t release()
    {
        return --counter_;
    }

private:
    counter_t counter_ = 0;
};

int main()
{
    // should not work since VS 2017 RTM (https://blogs.msdn.microsoft.com/vcblog/2017/02/06/stl-fixes-in-vs-2017-rtm/)

    intrusive_ptr<class_with_8bit_counter> ptr(new class_with_8bit_counter);
    std::vector<intrusive_ptr<class_with_8bit_counter>> v(254, ptr);
    assert(v.capacity() == v.size());
    v.push_back(std::move(ptr));
}

//#include <boost/utility/string_ref.hpp>
//
//namespace
//{
//    struct S1
//    {
//        boost::string_ref str;
//    };
//
//    struct S2
//    {
//        boost::string_ref str;
//
//        S2(S2 &&) noexcept = default;
//    };
//
//    static_assert(!std::is_nothrow_move_constructible_v<S1>, "S1 is not nothrow move constructible");
//    static_assert(!std::is_nothrow_move_constructible_v<S2>, "S2 is not nothrow move constructible");
//}