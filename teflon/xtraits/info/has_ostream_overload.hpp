#ifndef TEFLON_XTRAITS_INFO_HASOSTREAMOVERLOAD_HPP
#define TEFLON_XTRAITS_INFO_HASOSTREAMOVERLOAD_HPP

#include <iostream>
#include <type_traits>
#include <utility>

namespace teflon::xtraits
{
    namespace impl
    {
        template <class C>
        concept has_cout_overload =
            !std::is_void<decltype(std::cout << std::declval<C&>())>::value ||
            !std::is_void<decltype(std::cout << std::declval<C&&>())>::value;
    }

    template <typename Ty>
    struct has_ostream_overload {
    private:
        template <impl::has_cout_overload>
        static std::true_type test(char);

        template <typename = void>
        static std::false_type test(...);

    public: static constexpr bool value = decltype(test<Ty>(0))::value;
    };

    template <typename Ty>
    concept ostream_overload_c = has_ostream_overload<Ty>::value;
}

#endif // TEFLON_XTRAITS_INFO_HASOSTREAMOVERLOAD_HPP