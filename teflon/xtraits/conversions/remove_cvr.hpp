#ifndef TEFLON_XTRAITS_CONVERSIONS_REMOVECVR_HPP
#define TEFLON_XTRAITS_CONVERSIONS_REMOVECVR_HPP

#include <type_traits>

namespace teflon::xtraits {
	template <typename Ty>
	struct remove_cvr {
		using type = typename std::remove_cv<typename std::remove_reference<Ty>::type>::type;
	};

	template <typename Ty> using remove_cvr_t = typename remove_cvr<Ty>::type;
}

#endif // TEFLON_XTRAITS_CONVERSIONS_REMOVECVR_HPP