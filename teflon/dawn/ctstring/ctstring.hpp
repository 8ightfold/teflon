#ifndef TEFLON_DAWN_CTSTRING_CTSTRING_HPP
#define TEFLON_DAWN_CTSTRING_CTSTRING_HPP

#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <utility>
#include <teflon/dawn/get_literal_length.hpp>

namespace teflon::dawn {
    namespace ctstr::detail {
        template <std::size_t N = 1> struct ctstring_t {
        public:
            constexpr char& operator[](std::size_t Index) { return _data[Index]; }
            constexpr const char& operator[](std::size_t Index) const { return _data[Index]; }

            friend std::ostream& operator<<(std::ostream& os, ctstring_t<N> cat) {
                os << cat._data; return os;
            }
            
            constexpr char& front() { return _data[0]; }
            constexpr const char& front() const { return _data[0]; }

            constexpr char& back() { return _data[N - 2]; }
            constexpr const char& back() const { return _data[N - 2]; }

            char* const data() noexcept { return &_data[0]; }
            const char* const data() const noexcept { return &_data[0]; }

            constexpr bool empty() { return !(N - 1); }
            constexpr bool empty() const { return !(N - 1); }

            constexpr std::size_t size() { return N - 1; }
            constexpr std::size_t size() const { return N - 1; }
            constexpr std::size_t length() { return N - 1; }
            constexpr std::size_t length() const { return N - 1; }

            std::string string() { return std::string(_data); }
            std::string string() const { return std::string(_data); }

            std::string_view string_view() { return std::string_view(_data); }
            std::string_view string_view() const { return std::string_view(_data); }

        private: char _data[N];
        };
    }

    namespace generate {
        namespace {
            template <std::size_t N, std::size_t...Ns>
            constexpr inline auto ctstring_gen_impl(
                const char(&Data)[N], std::integer_sequence<std::size_t, Ns...>) {
                ctstr::detail::ctstring_t <N> str{}; ((str[Ns] = Data[Ns]), ...); return str;
            };
        }

        template <std::size_t N>
        constexpr inline auto ctstring(const char(&Data)[N]) -> ctstr::detail::ctstring_t<N> {
            return ctstring_gen_impl(Data, std::make_index_sequence<N>{});
        };
        template <std::size_t N>
        constexpr inline ctstr::detail::ctstring_t<N> ctstring(ctstr::detail::ctstring_t<N> Data) { return Data; };

        template <std::size_t N, std::size_t...Ns>
        constexpr inline auto ctstring_from_ptr(
            const char* Data, std::integer_sequence<std::size_t, Ns...>) {
            ctstr::detail::ctstring_t <N> str{}; ((str[Ns] = Data[Ns]), ...); return str;
        };
    }

    template <std::size_t N> using ctstring = ctstr::detail::ctstring_t<N>;
}

#define CTSTRING_FROM_POINTER(str) \
    teflon::dawn::generate::ctstring_from_ptr< \
    teflon::dawn::get_literal_length(str) + 1>(str, \
    std::make_integer_sequence<std::size_t, \
    teflon::dawn::get_literal_length(str)>{})

#endif // TEFLON_DAWN_CTSTRING_CTSTRING_HPP