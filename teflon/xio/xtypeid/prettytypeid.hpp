#ifndef TEFLON_XIO_XTYPEID_PRETTYTYPEID_HPP
#define TEFLON_XIO_XTYPEID_PRETTYTYPEID_HPP

#include <teflon/xio/xtypeid/prettyparse.hpp>

namespace teflon::xio 
{
    template <typename Ty>
    struct prettytypeid final : prettyparse<Ty>
    {
        prettytypeid(Ty&&) {}
        std::string name() { return this->nameof; }
        std::string name() const { return this->nameof; }
        friend std::ostream& operator << (std::ostream& os, const prettytypeid id) { return os << id.name(); }
    private:
        std::string nameof = { cttypeid<Ty>::pretty_name.data(), cttypeid<Ty>::pretty_name.size() };
    };
}

#endif // TEFLON_XIO_XTYPEID_PRETTYTYPEID_HPP