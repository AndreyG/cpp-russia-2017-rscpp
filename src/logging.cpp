#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>

void init_log()
{
    boost::log::add_common_attributes();

    auto sink = boost::log::add_console_log(
        std::cout,
        boost::log::keywords::auto_flush = true
    );

    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::info
    );

    namespace expr = boost::log::expressions;

    sink->set_formatter
    (
        expr::stream
            // First, put the current time
            << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f") << " "
            << if_ (expr::has_attr< unsigned int >("LineID"))
               [
                   // if "ID" is present then put it to the record
                   expr::stream << expr::attr< unsigned int >("LineID")
               ]
               .else_
               [
                   // otherwise put a missing marker
                   expr::stream << "--"
               ]
            // and after that goes the log record text
            << " " << expr::message
    );
}

int main()
{
    init_log();

    // Output some simple log message
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    return EXIT_SUCCESS;
}
