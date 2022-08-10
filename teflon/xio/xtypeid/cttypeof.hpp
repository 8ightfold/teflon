#ifndef TEFLON_XIO_XTYPEID_CTTYPEOF_HPP
#define TEFLON_XIO_XTYPEID_CTTYPEOF_HPP

#include <teflon/xio/xtypeid/prettyparse.hpp>

namespace teflon::xio
{
    template <typename Ty>
    struct cttypeof final : prettyparse<Ty>
    {
        static inline constexpr auto name() -> std::string_view
        {
            constexpr auto& pn = cttypeid<Ty>::pretty_name;
            return std::string_view{ pn.data(), pn.size() };
        }
    };
}

#endif // TEFLON_XIO_XTYPEID_CTTYPEOF_HPP