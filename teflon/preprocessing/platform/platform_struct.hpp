#ifndef TEFLON_PREPROCESSING_PLATFORM_PLATFORMSTRUCT_HPP
#define TEFLON_PREPROCESSING_PLATFORM_PLATFORMSTRUCT_HPP

#include <teflon/preprocessing/platform/platform_defines.h>

namespace teflon::platform
{
	struct windows	{};
	struct win32	{};
	struct win64	{};
	struct cygwin	{};
	struct linux	{};
	struct bsd		{};
	struct android	{};
	struct ios		{};
	struct iossim	{};
	struct iosreal	{};
	struct osx		{};
	struct solaris	{};
	struct hpux		{};
	struct aix		{};
	struct unknown 	{};
}

#endif // TEFLON_PREPROCESSING_PLATFORM_PLATFORMSTRUCT_HPP