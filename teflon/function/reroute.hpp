#ifndef TEFLON_FUNCTION_REROUTE_HPP
#define TEFLON_FUNCTION_REROUTE_HPP

#include <utility>
#include <type_traits>

#include <teflon/xtraits.hpp>

namespace teflon::function {
    template<typename Fn, Fn F>
    struct CFunc;

    template<typename Ret, typename...Args, auto F>
    struct CFunc<Ret(*)(Args...), F> {
        Ret exec(Args...args) {
            return F(static_cast<Args>(args)...);
        }
    };

    // Thank Fux for making a better implementation of this,
    // it was kinda tedious to use before.
    template<auto...Fs>
    struct Reroute : CFunc<decltype(Fs), Fs>...
    {
        using CFunc<decltype(Fs), Fs>::exec...;
        template<class...Args>
        decltype(auto) operator ()(Args&&...args) {
            return exec(std::forward<Args>(args)...);
        }
    };
}

#endif // TEFLON_FUNCTION_REROUTE_HPP
