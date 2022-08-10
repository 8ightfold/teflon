#ifndef TEFLON_PREPROCESSING_PLATFORM_PLATFORM_HPP
#define TEFLON_PREPROCESSING_PLATFORM_PLATFORM_HPP

#include <teflon/preprocessing/platform/platform_defines.h>
#include <teflon/preprocessing/platform/platform_current.h>
#include <teflon/preprocessing/platform/platform_enum.hpp>
#include <teflon/preprocessing/platform/platform_struct.hpp>
#include <teflon/preprocessing/stringify.hpp>

#include <cinttypes>
#include <string_view>

namespace teflon::platform
{
	struct current_platform {
		using type = TEFLON_PLATFORM_NAME;
		static constexpr vPlatform value = vPlatform::TEFLON_PLATFORM_NAME;
		static constexpr std::string_view name = TEFLON_STRINGIFY(TEFLON_PLATFORM_NAME);
	};
}

#endif // TEFLON_PREPROCESSING_PLATFORM_PLATFORM_HPP