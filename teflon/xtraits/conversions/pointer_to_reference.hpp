#ifndef TEFLON_XTRAITS_CONVERSIONS_POINTERTOREFERENCE_HPP
#define TEFLON_XTRAITS_CONVERSIONS_POINTERTOREFERENCE_HPP

namespace teflon::xtraits {
	template <typename> struct pointer_to_lvalue_reference;
	template <typename> struct pointer_to_rvalue_reference;

	template <typename Ty>
	struct pointer_to_lvalue_reference <Ty*> {
		using type = Ty&;
	};

	template <typename Ty>
	struct pointer_to_rvalue_reference <Ty*> {
		using type = Ty&&;
	};

	template <typename Ty> using pointer_to_lvalue_reference_t = typename pointer_to_lvalue_reference<Ty>::type;
	template <typename Ty> using pointer_to_rvalue_reference_t = typename pointer_to_rvalue_reference<Ty>::type;
}

#endif // TEFLON_XTRAITS_CONVERSIONS_POINTERTOREFERENCE_HPP