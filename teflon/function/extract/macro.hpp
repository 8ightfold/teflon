#ifndef TEFLON_FUNCTION_EXTRACT_MACRO_HPP
#define TEFLON_FUNCTION_EXTRACT_MACRO_HPP

#define GENERATE_GENERAL_KEY(UUID, Member, Type) \
    struct UUID : teflon::function::extract::detail::UUIDbase<UUID, Type>{}; \
    template struct teflon::function::extract::detail::Extract<UUID, & Member>;

#define GENERATE_MEMBER_KEY(UUID, Parent, Member, Type) \
    GENERATE_GENERAL_KEY(UUID, Parent :: Member, Type Parent ::*)

#define GFK_OPEN_P (
#define GFK_CLOSE_P )
#define GENERATE_FUNCTION_KEY(UUID, Parent, Member, Return, ...) \
    GENERATE_GENERAL_KEY(UUID, Parent :: Member, Return GFK_OPEN_P Parent ::* GFK_CLOSE_P GFK_OPEN_P __VA_ARGS__ GFK_CLOSE_P)

#endif // TEFLON_FUNCTION_EXTRACT_MACRO_HPP