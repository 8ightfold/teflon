#ifndef TEFLON_PREPROCESSING_PLATFORM_PLATFORMENUM_HPP
#define TEFLON_PREPROCESSING_PLATFORM_PLATFORMENUM_HPP

#include <teflon/preprocessing/platform/platform_defines.h>
#include <cinttypes>

namespace teflon::platform
{
	enum struct vPlatform : int32_t
	{
		windows = TEFLON_PLATFORM_WINDOWS,
		win32 = TEFLON_PLATFORM_WINDOWS32,
		win64 = TEFLON_PLATFORM_WINDOWS64,
		cygwin = TEFLON_PLATFORM_WINDOWSCYG,
		linux = TEFLON_PLATFORM_LINUX,
		bsd = TEFLON_PLATFORM_BSD,
		android = TEFLON_PLATFORM_ANDROID,
		ios = TEFLON_PLATFORM_IOS,
		iossim = TEFLON_PLATFORM_IOSS,
		iosreal = TEFLON_PLATFORM_IOSR,
		osx = TEFLON_PLATFORM_OSX,
		solaris = TEFLON_PLATFORM_SOLARIS,
		hpux = TEFLON_PLATFORM_HPUX,
		aix = TEFLON_PLATFORM_AIX,
		unknown = TEFLON_PLATFORM_UNKNOWN
	};
}

#endif // TEFLON_PREPROCESSING_PLATFORM_PLATFORMENUM_HPP