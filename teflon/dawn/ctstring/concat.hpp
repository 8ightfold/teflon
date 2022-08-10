#ifndef TEFLON_DAWN_CTSTRING_CONCAT_HPP
#define TEFLON_DAWN_CTSTRING_CONCAT_HPP

#include <utility>
#include <teflon/dawn/ctstring/ctstring.hpp>

namespace teflon::dawn::ctstr {
    namespace {
        namespace helper {
            namespace detail {
                template <std::size_t F, std::size_t S, std::size_t...Fs, std::size_t...Ss>
                constexpr auto concat_impl(ctstring<F> First, ctstring<S> Second,
                    std::integer_sequence<std::size_t, Fs...>,
                    std::integer_sequence<std::size_t, Ss...>) -> ctstring<F + S - 1> {
                    ctstring<F + S - 1> arr{};
                    ((arr[Fs] = First[Fs]), ...); ((arr[Ss + F - 1] = Second[Ss]), ...);
                    arr[F + S - 2] = '\0';
                    return arr;
                }
            }
            template <std::size_t N>
            constexpr inline auto concat(ctstring<N> Final) { return Final; };

            template <std::size_t F, std::size_t S, typename...Tys>
            constexpr inline auto concat(ctstring<F> First, ctstring<S> Second, Tys...tys) {
                auto cat = detail::concat_impl(First, Second,
                    std::make_index_sequence<F - 1>{},
                    std::make_index_sequence<S - 1>{});
                return concat(cat, tys...);
            };
        }
    }

    template <typename T, typename U, typename...Tys>
    constexpr inline auto concat(T&& t, U&& u, Tys&&...tys) {
        return helper::concat(
            generate::ctstring(t), 
            generate::ctstring(u), 
            generate::ctstring(tys)...
        );
    };

    template <typename T>
    constexpr inline auto concat(T&& t) { return t; };
}

#endif // TEFLON_DAWN_CTSTRING_CONCAT_HPP