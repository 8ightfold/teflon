#ifndef TEFLON_DAWN_VERIFYCONSTEXPR_HPP
#define TEFLON_DAWN_VERIFYCONSTEXPR_HPP

#include <type_traits>

#define verify_constexpr static_assert(std::is_constant_evaluated(), "Not a constant context.")
#define is_consteval verify_constexpr

#endif // TEFLON_DAWN_VERIFYCONSTEXPR_HPP