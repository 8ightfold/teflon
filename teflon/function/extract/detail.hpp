#ifndef TEFLON_FUNCTION_EXTRACT_DETAIL_HPP
#define TEFLON_FUNCTION_EXTRACT_DETAIL_HPP

#include <type_traits>

namespace teflon::function::extract::detail {
    template <typename UUID, typename UUID::type Member>
    struct Extract {
        using Ret = typename UUID::type;
        friend constexpr Ret teflon_function_extract_detail_access(UUID) noexcept { return Member; }
    };

    template <typename UUID, typename Member>
    struct UUIDbase {
        using type = Member;
        friend constexpr type teflon_function_extract_detail_access(UUID) noexcept;
    };
}

#endif // TEFLON_FUNCTION_EXTRACT_DETAIL_HPP