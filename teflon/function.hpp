#ifndef TEFLON_FUNCTION_HPP
#define TEFLON_FUNCTION_HPP

#include <teflon/function/cstyle.hpp>
#include <teflon/function/extract.hpp>
// HOW TO USE:
// You must first put one of these 3 macros in the global namespace:
// 
// GENERATE_MEMBER_KEY : Used for non function attributes.
//    Example: class Foo { int Bar; };
//		-> GENERATE_MEMBER_KEY(UUID_F, Foo, Bar, int)
//
// GENERATE_FUNCTION_KEY : Used for (you guessed it) functions.
//    Example: class Baz { int Qux(float) {} }; 
//		-> GENERATE_FUNCTION_KEY(UUID_B, Baz, Qux, int, float)
//
// GENERATE_GENERAL_KEY : The most general case. You must specify the type directly.
//    Example 1: class Foo { int Bar; };
//		-> GENERATE_GENERAL_KEY(UUID_F, Foo::Bar, int Foo::*)
//    Example 2: class Baz { int Qux(float) {} }; 
//		-> GENERATE_GENERAL_KEY(UUID_B, Baz::Qux, int(Baz::*)(float))
//
// You can then access the member via the from() and with() functions 
// (with() is for function pointers only). Using the examples from before,
// We could say:
// int Bar = teflon::function::extract::Get<UUID_F>::from(foo);
// auto Qux = teflon::function::extract::Get<UUID_B>::with<Baz&&>();

#include <teflon/function/reroute.hpp>
// HOW TO USE:
// If we had a C library containing:
// 
//	int Foo_int(int i) { return i * 2; }
//	float Foo_float(float f) { return f * 3.f; }
//	double Foo_double(double d) { return d * 4.; }
// 
// We can define "teflon::function::Reroute<Foo_int, Foo_float, Foo_double> Foo"
// in the global namespace. This gives us compile time indirection creating an
// overload interface for C libraries. This has very little overhead when compared to
// runtime indirection, such as virtuals, which require deducing the type on the fly.

#endif // TEFLON_FUNCTION_HPP