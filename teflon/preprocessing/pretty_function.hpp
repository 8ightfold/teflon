#ifndef TEFLON_PREPROCESSING_PRETTYFUNCTION_HPP
#define TEFLON_PREPROCESSING_PRETTYFUNCTION_HPP

#if defined(__clang__)
#  define TEFLON_PRETTY_FUNCTION __PRETTY_FUNCTION__
#  define TEFLON_PRETTY_FUNCTION_START "[Ty = "
#  define TEFLON_PRETTY_FUNCTION_END "]\0"
#elif defined(__GNUC__) && defined(__GNUG__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
#  define TEFLON_PRETTY_FUNCTION __PRETTY_FUNCTION__
#  define TEFLON_PRETTY_FUNCTION_START "[with Ty = "
#  define TEFLON_PRETTY_FUNCTION_END "]\0"
#elif defined(_MSC_VER)
#  define TEFLON_PRETTY_FUNCTION __FUNCSIG__
#  define TEFLON_PRETTY_FUNCTION_START "pretty_function_array<"
#  define TEFLON_PRETTY_FUNCTION_END ">(void)\0"
#else
#endif

#endif // TEFLON_PREPROCESSING_PRETTYFUNCTION_HPP