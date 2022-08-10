#ifndef TEFLON_FUNCTION_CSTYLE_HPP
#define TEFLON_FUNCTION_CSTYLE_HPP

#include <type_traits>

namespace teflon::function::cstyle {
    template <class T>
    using add_lvalue_unless_rvalue = std::conditional_t <
        std::is_rvalue_reference_v<T>, T, std::add_lvalue_reference_t<T>
    >;

    // Big thanks to Fux for helping me with this standardized C style cast.
    template<auto MemberFunc, class Object, class...Args>
    decltype(auto) convert(Object obj, Args...args) {
        return (static_cast<add_lvalue_unless_rvalue<Object>>(obj).*MemberFunc) (
            static_cast<add_lvalue_unless_rvalue<Args>>(args)...
            );
    };

    //namespace unsafe {

    //    // This works on GCC and Clang due to their much simpler member function
    //    // calling conventions, but MSVC will require a much more indepth method
    //    // to cast. I'll look into the implementation in the future, but for now
    //    // this will stay marked as unsafe.

    //    namespace meta {
    //        template <typename T, class U, typename...Args>
    //        union access_c_like {
    //            T(THISCALL U::* member)(Args...args);
    //            T(CDECL* nonmember)(U*, Args...args);
    //            access_c_like(T(U::* member)(Args...args)) : member(member) {}
    //            access_c_like(T(*nonmember)(U*, Args...args)) : nonmember(nonmember) {}
    //        };
    //    }

    //    template <typename T, class U, typename...Args>
    //    inline auto c_style(T(THISCALL U::* member)(Args...)) {
    //        meta::access_c_like <T, U, Args...> temp_access(member);
    //        return temp_access.nonmember;
    //    };
    //    template <typename T, typename...Args>
    //    inline auto c_style(T(CDECL* nonmember)(Args...args)) { return nonmember; };
    //}
}

#endif // TEFLON_FUNCTION_CSTYLE_HPP