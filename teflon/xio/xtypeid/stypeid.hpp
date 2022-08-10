#ifndef TEFLON_XIO_XTYPEID_STYPEID_HPP
#define TEFLON_XIO_XTYPEID_STYPEID_HPP

#include <teflon/xio/xtypeid/demangler.hpp>

namespace teflon::xio 
{
    struct stypeid final : demangler 
    {
        stypeid() { this->demangled = "void"; }
        template<typename Ty> stypeid(Ty&& ty) { this->demangled = demangle(typeid(ty).name()); };
        std::string name() { return this->demangled.value_or("(null)"); }
        std::string name() const { return this->demangled.value_or("(null)"); }
        friend std::ostream& operator << (std::ostream& os, const stypeid id) { return os << id.name(); }
    };
}

#endif // TEFLON_XIO_XTYPEID_STYPEID_HPP