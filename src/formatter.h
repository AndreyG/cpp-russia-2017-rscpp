#pragma once

#include <string>

#if defined(__RESHARPER__) || defined(__GNUC__)
    #define PRINTF_ATTR(StringIndex, FirstToCheck) \
        [[gnu::format(printf, StringIndex, FirstToCheck)]]
#else
    #define PRINTF_ATTR(StringIndex, FirstToCheck)
#endif

class Formatter
{
public:
    template<typename... Args>
    PRINTF_ATTR(2, 3) void append(const char * fmt, Args&& ... args)
    {
        auto size = std::snprintf(NULL, 0, fmt, args...);
        auto old_buffer_size = result_.size();
        result_.resize(old_buffer_size + size);
        std::snprintf(&result_[old_buffer_size], size + 1, fmt, args...);
    }

    std::string const & str() const
    {
        return result_;
    }

private:
    std::string result_;
};
