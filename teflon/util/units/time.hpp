#ifndef TEFLON_UTIL_UNITS_TIME_HPP
#define TEFLON_UTIL_UNITS_TIME_HPP

#include <type_traits>

namespace teflon::unit
{
	struct second {      static inline constexpr long double value = 1.0E0L;   };
	struct decisecond {  static inline constexpr long double value = 1.0E-1L;  };
	struct centisecond { static inline constexpr long double value = 1.0E-2L;  };
	struct millisecond { static inline constexpr long double value = 1.0E-3L;  };
	struct microsecond { static inline constexpr long double value = 1.0E-6L;  };
	struct nanosecond {  static inline constexpr long double value = 1.0E-9L;  };
	struct picosecond {  static inline constexpr long double value = 1.0E-12L; };
	struct femtosecond { static inline constexpr long double value = 1.0E-15L; };
	struct minute {      static inline constexpr long double value = 60.0L *   second::value; };
	struct hour {        static inline constexpr long double value = 60.0L *   minute::value; };
	struct day {         static inline constexpr long double value = 24.0L *   hour::value;   };
	struct week {        static inline constexpr long double value = 7.0L *    day::value;    };
	struct year {        static inline constexpr long double value = 365.25L * day::value;    };

	namespace impl
	{
		template <typename>	struct is_unit_time      : std::false_type {};
		template <>	struct is_unit_time<year>        : std::true_type {};
		template <>	struct is_unit_time<week>        : std::true_type {};
		template <>	struct is_unit_time<day>         : std::true_type {};
		template <>	struct is_unit_time<hour>        : std::true_type {};
		template <>	struct is_unit_time<minute>      : std::true_type {};
		template <>	struct is_unit_time<second>      : std::true_type {};
		template <>	struct is_unit_time<decisecond>  : std::true_type {};
		template <>	struct is_unit_time<centisecond> : std::true_type {};
		template <>	struct is_unit_time<millisecond> : std::true_type {};
		template <>	struct is_unit_time<microsecond> : std::true_type {};
		template <>	struct is_unit_time<nanosecond>  : std::true_type {};
		template <>	struct is_unit_time<picosecond>  : std::true_type {};
		template <>	struct is_unit_time<femtosecond> : std::true_type {};
	}
}

struct time {
	using yr =  teflon::unit::year;
	using wk =  teflon::unit::week;
	using dy =  teflon::unit::day;
	using hr =  teflon::unit::hour;
	using min = teflon::unit::minute;
	using s =   teflon::unit::second;
	using ds =  teflon::unit::decisecond;
	using cs =  teflon::unit::centisecond;
	using ms =  teflon::unit::millisecond;
	using us =  teflon::unit::microsecond;
	using ns =  teflon::unit::nanosecond;
	using ps =  teflon::unit::picosecond;
	using fs =  teflon::unit::femtosecond;
};

namespace teflon::unit
{
	namespace impl
	{
		template <>	struct is_unit_time<time::yr>  : std::true_type {};
		template <>	struct is_unit_time<time::wk>  : std::true_type {};
		template <>	struct is_unit_time<time::dy>  : std::true_type {};
		template <>	struct is_unit_time<time::hr>  : std::true_type {};
		template <>	struct is_unit_time<time::min> : std::true_type {};
		template <>	struct is_unit_time<time::s>   : std::true_type {};
		template <>	struct is_unit_time<time::ds>  : std::true_type {};
		template <>	struct is_unit_time<time::cs>  : std::true_type {};
		template <>	struct is_unit_time<time::ms>  : std::true_type {};
		template <>	struct is_unit_time<time::us>  : std::true_type {};
		template <>	struct is_unit_time<time::ns>  : std::true_type {};
		template <>	struct is_unit_time<time::fs>  : std::true_type {};
	}

	template <typename Ty>
	struct is_unit_time {
		static inline constexpr bool value = impl::is_unit_time<Ty>::value;
	};
}

#endif // TEFLON_UTIL_UNITS_TIME_HPP
