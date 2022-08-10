#ifndef TEFLON_XTRAITS_INFO_ISVOIDPOINTER_HPP
#define TEFLON_XTRAITS_INFO_ISVOIDPOINTER_HPP

#include <type_traits>
#include <teflon/xtraits/conversions/remove_cvr.hpp>

namespace teflon::xtraits {
    template <typename> struct is_void_pointer : std::false_type {};
    template <typename> struct is_void_pointer_helper : std::false_type {};

    template <> struct is_void_pointer_helper<void*> : std::true_type {};

    template <typename Ty> struct is_void_pointer<Ty*> {
        static constexpr bool value = is_void_pointer_helper<typename remove_cvr<Ty>::type>::value;
    };

    template <typename Ty> 
    constexpr bool is_void_pointer_v = is_void_pointer<Ty>::value;
}

#endif // !TEFLON_TRAITS_INFO_ISVOIDPOINTER_HPP
