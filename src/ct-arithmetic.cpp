#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/at.hpp>

#include <boost/preprocessor/arithmetic/div.hpp>

#include <iostream>

template<int N>
constexpr int fib = fib<N - 1> + fib<N - 2>;

template<> constexpr int fib<0> = 0;
template<> constexpr int fib<1> = 1;

int main()
{
    std::cout << fib<30> << "\n";

    using namespace boost::mpl;

    using int_13 = plus<int_<6>, int_<7>>;
    std::cout << int_13::value << "\n";

    std::cout   << "BOOST_PP_DIV_BASE(72, 9) = " << BOOST_PP_DIV_BASE(72, 9) << "\n"
                << "BOOST_PP_DIV(72, 9) = "      << BOOST_PP_DIV(72, 9)      << "\n";

    using ll_type = at_c<
        pop_front<
            pop_front<
                push_back<
                    vector<short, int, long>, long long
                >::type
            >::type
        >::type,
        1
    >::type;
}
