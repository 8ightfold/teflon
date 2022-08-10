#ifndef TEFLON_DAWN_HPP
#define TEFLON_DAWN_HPP

#include <teflon/dawn/ctstring.hpp>
// HOW TO USE:
// To create a ctstring from an array, use dawn::generate::ctstring().
// If you use constexpr auto foo = "literal", the array will decay into a pointer.
// In this case, you must use CTSTRING_FROM_POINTER().
// 
// Many of the std::string functions are usable with ctstrings, 
// but some cannot be used in a constexpr context.
// 
// ctstring_t::string() and ctstring_t::string_view() can be used 
// to generate their respective types. 
//
// dawn::ctstr::concat() can concatinate any amout of arguments, with the acceptable
// types being const char[] and ctstrings.
//
// dawn::ctstr::substr<Start, Len>() will generate a substring from an array or an
// existing ctstring. If the second template argument is left blank, it will default to using
// the rest of the ctstring.

#include <teflon/dawn/get_literal_length.hpp>
// The useful part can only be evaluated in main.

#include <teflon/dawn/static_array.hpp>
#include <teflon/dawn/verify_constexpr.hpp>

#endif // TEFLON_DAWN_HPP