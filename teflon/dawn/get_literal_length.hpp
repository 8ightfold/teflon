#ifndef TEFLON_DAWN_GETLITERALLENGTH_HPP
#define TEFLON_DAWN_GETLITERALLENGTH_HPP

#include <cstddef>

namespace teflon::dawn {
    // Unfortunately, this cannot be used in functions other than main.
    consteval std::size_t get_literal_length(const char str[]) {
        std::size_t idx = 0;
        for (; str[idx] != '\0'; idx++) {}
        return idx;
    }

    template <std::size_t N> consteval std::size_t 
    get_literal_length(const char(&str)[N]) { return N; }
}

#endif // TEFLON_DAWN_GETLITERALLENGTH_HPP