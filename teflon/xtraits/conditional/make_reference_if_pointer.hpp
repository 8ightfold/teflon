#ifndef TEFLON_XTRAITS_CONDITIONAL_MAKEREFERENCEIFPOINTER_HPP
#define TEFLON_XTRAITS_CONDITIONAL_MAKEREFERENCEIFPOINTER_HPP

#include <type_traits>
#include <teflon/xtraits/conversions/pointer_to_reference.hpp>

namespace teflon::xtraits {
	template <typename Ty>
	using make_reference_if_pointer = std::conditional_t <
		std::is_pointer_v<Ty>, pointer_to_rvalue_reference_t<Ty>, Ty
	>;
}

#endif // TEFLON_XTRAITS_CONDITIONAL_MAKEREFERENCEIFPOINTER_HPP