#include "formatter.h"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>

#include <boost/format.hpp>

BOOST_AUTO_TEST_SUITE(FormatterTests)

BOOST_AUTO_TEST_CASE(WithoutArgs)
{
    Formatter fmt;
    fmt.append("1");
    fmt.append("2");
    fmt.append("3");
    BOOST_CHECK_EQUAL(fmt.str(), "123");
}

BOOST_AUTO_TEST_CASE(Numbers)
{
    Formatter fmt;
    fmt.append("%d %.2f", 1, 2.3f);
    BOOST_CHECK_EQUAL(fmt.str(), "1 2.30");
}

BOOST_AUTO_TEST_CASE(Date)
{
    auto today = boost::gregorian::day_clock::local_day();
    auto year = today.year();
    auto month = today.month().as_short_string();

    Formatter our_fmt;
    our_fmt.append("%u-%s-%u", year, month, today.day());
    auto boost_fmt = boost::format("%1%-%2%-%3%") % year % month % today.day();
    BOOST_CHECK_EQUAL(our_fmt.str(), boost_fmt.str());
}

BOOST_AUTO_TEST_SUITE_END()