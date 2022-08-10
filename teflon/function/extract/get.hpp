#ifndef TEFLON_FUNCTION_EXTRACT_GET_HPP
#define TEFLON_FUNCTION_EXTRACT_GET_HPP

#include <teflon/function/extract/detail.hpp>
#include <teflon/function/cstyle.hpp>

namespace teflon::function::extract {
    namespace {
        namespace helper {
            template <typename, typename> struct from;

            template <typename UUID, typename Ret, class Parent, typename...Args>
            struct from <UUID, Ret(Parent::*)(Args...)> {
                static auto ret(Parent&) -> Ret(*)(Parent&, Args...) {
                    return teflon::function::cstyle::convert<teflon_function_extract_detail_access(UUID())>;
                }
            };

            template <typename UUID, typename Member, class Parent>
            struct from <UUID, typename Member Parent::*> {
                static Member ret(Parent& parent) {
                    return parent.*teflon_function_extract_detail_access(UUID());
                }
            };


            template <typename, typename, typename> struct with;

            template <typename UUID, typename Ret, class Parent, typename...Args, typename Custom_Parent>
            struct with <UUID, Ret(Parent::*)(Args...), Custom_Parent> {
                static auto ret() -> Ret(*)(teflon::function::cstyle::add_lvalue_unless_rvalue<Custom_Parent>, Args...) {
                    return teflon::function::cstyle::convert<teflon_function_extract_detail_access(UUID())>;
                }
            };
        }
    }

    namespace temporary {
        template <typename> struct characteristics;

        template <typename Member, class Object>
        struct characteristics <typename Member Object::*> {
            using Parent = Object;
        };

        template <typename Ret, class Object, typename...Args>
        struct characteristics <Ret(Object::*)(Args...)> {
            using Parent = Object;
        };
    }

    template <typename UUID> struct Get {
        template <class Parent>
        static auto from(Parent& parent) {
            static_assert(
                std::is_same_v<temporary::characteristics<UUID::type>::Parent, 
                std::remove_reference_t<Parent>>,
                "ERROR: The bound UUID type and function parameter are not the same type.");
            static helper::from<UUID, UUID::type> helper{};
            return helper.ret(parent);
        };
        template <class Parent>
        static auto with() {
            static_assert (
                std::is_same_v<temporary::characteristics<UUID::type>::Parent, 
                std::remove_reference_t<Parent>>,
                "ERROR: The bound UUID type and function parameter are not the same type.");
            return helper::with<UUID, UUID::type, Parent>::ret();
        };
    };
}

#endif