#ifndef TEFLON_DAWN_CTSTRING_SUBSTR_HPP
#define TEFLON_DAWN_CTSTRING_SUBSTR_HPP

#include <utility>
#include <teflon/dawn/ctstring/ctstring.hpp>
#include <teflon/dawn/ctstring/concat.hpp>

namespace teflon::dawn::ctstr {
	namespace {
		template <std::size_t Start, std::size_t Len, std::size_t N, std::size_t...Ns>
		constexpr auto substr_helper(teflon::dawn::ctstring<N> str, std::integer_sequence<std::size_t, Ns...>) {
			ctstring<Len + 1> arr{}; ((arr[Ns] = str[Ns + Start]), ...); return arr;
		};
	}

	template <std::size_t Start, std::size_t Len, std::size_t N>
	inline constexpr auto substr(const char(&Data)[N]) -> ctstring<Len + 1> {
		static_assert(Start < N, "Invalid start position.");
		static_assert(Len < N, "Invalid substring length.");

		return substr_helper<Start, Len>(
			teflon::dawn::generate::ctstring(Data), std::make_index_sequence<Len>{});
	};

	template <std::size_t Start, std::size_t Len, std::size_t N>
	inline constexpr auto substr(teflon::dawn::ctstring<N> Data) -> ctstring<Len + 1> {
		static_assert(Start < N, "Invalid start position.");
		static_assert(Len < N, "Invalid substring length.");

		return substr_helper<Start, Len>(Data, std::make_index_sequence<Len>{});
	};

	template <std::size_t Start, std::size_t N>
	inline constexpr auto substr(const char(&Data)[N]) {
		return substr<Start, N - Start - 1, N>(Data);
	};

	template <std::size_t Start, std::size_t N>
	inline constexpr auto substr(teflon::dawn::ctstring<N> Data) {
		return substr<Start, N - Start - 1, N>(Data);
	};
}

#endif