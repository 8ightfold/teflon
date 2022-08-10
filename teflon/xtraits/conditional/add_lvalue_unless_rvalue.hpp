#ifndef TEFLON_XTRAITS_CONDITIONAL_ADDLVALUEUNLESSRVALUE_HPP
#define TEFLON_XTRAITS_CONDITIONAL_ADDLVALUEUNLESSRVALUE_HPP

#include <type_traits>

namespace teflon::xtraits {
    template <class T>
    using add_lvalue_unless_rvalue = std::conditional_t <
        std::is_rvalue_reference_v<T>, T, std::add_lvalue_reference_t<T>
    >;
}

#endif // TEFLON_XTRAITS_CONDITIONAL_ADDLVALUEUNLESSRVALUE_HPP