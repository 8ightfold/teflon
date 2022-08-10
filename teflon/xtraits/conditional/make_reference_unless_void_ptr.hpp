#ifndef TEFLON_XTRAITS_CONDITIONAL_MAKEREFERENCEUNLESSVOIDPTR_HPP
#define TEFLON_XTRAITS_CONDITIONAL_MAKEREFERENCEUNLESSVOIDPTR_HPP

#include <type_traits>

#include <teflon/xtraits/conditional/make_reference_if_pointer.hpp>
#include <teflon/xtraits/info/is_void_pointer.hpp>

namespace teflon::xtraits {
    template <typename Ty>
    using make_reference_unless_void_pointer = std::conditional_t <
        is_void_pointer_v<Ty>, Ty, make_reference_if_pointer<Ty>
    >;

    template <typename> struct make_reference_unless_void_pointer_f;

    template <typename Ret, typename...Args> 
    struct make_reference_unless_void_pointer_f <Ret(*)(Args...)> {
        using type = Ret(*)(make_reference_unless_void_pointer<Args>...);
    };

    template <typename Ty> 
    using make_reference_unless_void_pointer_ft = typename make_reference_unless_void_pointer_f<Ty>::type;
}

#endif // TEFLON_XTRAITS_CONDITIONAL_MAKEREFERENCEUNLESSVOIDPTR_HPP