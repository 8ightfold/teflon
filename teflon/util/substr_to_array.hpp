#ifndef TEFLON_UTIL_SUBSTRTOARRAY_HPP
#define TEFLON_UTIL_SUBSTRTOARRAY_HPP

#include <array>
#include <string_view>
#include <type_traits>

namespace teflon::util 
{
    template <std::size_t...Indices>
    constexpr auto substr_to_array(std::string_view str, std::index_sequence<Indices...>)
    {
        return std::array{ str[Indices]..., '\0' };
    };
}

#endif // TEFLON_UTIL_SUBSTRTOARRAY_HPP