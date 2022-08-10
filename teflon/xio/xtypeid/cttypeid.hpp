#ifndef TEFLON_XIO_XTYPEID_CTTYPEID_HPP
#define TEFLON_XIO_XTYPEID_CTTYPEID_HPP

#include <teflon/xio/xtypeid/prettyparse.hpp>

namespace teflon::xio
{
    template <typename Ty>
    struct cttypeid final : prettyparse<Ty>
    {
        constexpr cttypeid(Ty&& ty) {}
        constexpr auto name() -> std::string_view
        {
            constexpr auto& pn = cttypeid<Ty>::pretty_name;
            return std::string_view{ pn.data(), pn.size() };
        }
        constexpr auto name() const -> std::string_view
        {
            constexpr auto& pn = cttypeid<Ty>::pretty_name;
            return std::string_view{ pn.data(), pn.size() };
        }
    };
}

#endif // TEFLON_XIO_XTYPEID_CTTYPEID_HPP