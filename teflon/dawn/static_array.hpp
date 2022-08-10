#ifndef TEFLON_DAWN_STATICARRAY_HPP
#define TEFLON_DAWN_STATICARRAY_HPP

#include <array>
#include <type_traits>

namespace teflon::dawn 
{
	template <typename Ty, Ty...tys>
	struct static_array {
		constexpr static inline auto value = std::array{ tys... };
	};

	template <char...chars>
	using static_literal = static_array<char, chars..., '\0'>;

	template <wchar_t...wchars>
	using static_wliteral = static_array<wchar_t, wchars..., L'\0'>;
}

#endif // TEFLON_DAWN_STATICARRAY_HPP