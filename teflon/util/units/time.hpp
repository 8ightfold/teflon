#ifndef TEFLON_UTIL_UNITS_TIME_HPP
#define TEFLON_UTIL_UNITS_TIME_HPP

#include <type_traits>

namespace teflon::unit
{
	struct second { static inline constexpr long double value = 1.0E0; };
	struct decisecond { static inline constexpr long double value = 1.0E-1; };
	struct centisecond { static inline constexpr long double value = 1.0E-2; };
	struct millisecond { static inline constexpr long double value = 1.0E-3; };
	struct microsecond { static inline constexpr long double value = 1.0E-6; };
	struct nanosecond { static inline constexpr long double value = 1.0E-9; };
	struct picosecond { static inline constexpr long double value = 1.0E-12; };
	struct femtosecond { static inline constexpr long double value = 1.0E-15; };

	namespace
	{
		template <typename>	struct is_unit_time : std::false_type {};
		template <>	struct is_unit_time<decisecond> : std::true_type {};
		template <>	struct is_unit_time<centisecond> : std::true_type {};
		template <>	struct is_unit_time<millisecond> : std::true_type {};
		template <>	struct is_unit_time<microsecond> : std::true_type {};
		template <>	struct is_unit_time<nanosecond> : std::true_type {};
		template <>	struct is_unit_time<picosecond> : std::true_type {};
		template <>	struct is_unit_time<femtosecond> : std::true_type {};
	}

	template <typename Ty>
	struct is_unit_time {
		static inline constexpr bool value = is_unit_time<Ty>::value;
	};
}

struct time {
	using s =  teflon::unit::second;
	using ds = teflon::unit::decisecond;
	using cs = teflon::unit::centisecond;
	using ms = teflon::unit::millisecond;
	using us = teflon::unit::microsecond;
	using ns = teflon::unit::nanosecond;
	using ps = teflon::unit::picosecond;
	using fs = teflon::unit::femtosecond;
};

#endif // TEFLON_UTIL_UNITS_TIME_HPP
