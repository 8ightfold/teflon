#ifndef TEFLON_XIO_XTYPEID_PRETTYPARSE_HPP
#define TEFLON_XIO_XTYPEID_PRETTYPARSE_HPP

#include <teflon/preprocessing/pretty_function.hpp>
#include <teflon/util/substr_to_array.hpp>

namespace teflon::xio 
{
    namespace 
    {
        template <typename Ty>
        constexpr auto pretty_function_array()
        {
            constexpr std::string_view name = std::string_view{ TEFLON_PRETTY_FUNCTION };
            constexpr std::string_view prefix = { TEFLON_PRETTY_FUNCTION_START };
            constexpr std::string_view suffix = { TEFLON_PRETTY_FUNCTION_END };

            constexpr std::size_t start = name.find(prefix) + prefix.size();
            constexpr std::size_t end = name.rfind(suffix);

            static_assert(start < end, "Invalid arguments.");

            constexpr std::string_view pname = name.substr(start, (end - start));
            return teflon::util::substr_to_array(pname, std::make_index_sequence<pname.size()>{});
        };
    }

    // Base for all other compile time "demanglers"

    template <typename Ty> 
    struct prettyparse {
    protected: static inline constexpr auto pretty_name = pretty_function_array<Ty>();
    };
}

#endif // TEFLON_XIO_XTYPEID_PRETTYPARSE_HPP