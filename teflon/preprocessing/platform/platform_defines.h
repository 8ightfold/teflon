#ifndef TEFLON_PREPROCESSING_PLATFORM_PLATFORMDEFINES_H
#define TEFLON_PREPROCESSING_PLATFORM_PLATFORMDEFINES_H

#define TEFLON_PLATFORM_WINDOWS      0x00
#  define TEFLON_PLATFORM_WINDOWS32  0x01
#  define TEFLON_PLATFORM_WINDOWS64  0x02
#  define TEFLON_PLATFORM_WINDOWSCYG 0x03

#define TEFLON_PLATFORM_ANDROID      0x10
								     
#define TEFLON_PLATFORM_LINUX	     0x20
								     
#define TEFLON_PLATFORM_BSD		     0x30
								     
#define TEFLON_PLATFORM_HPUX	     0x40
								     
#define TEFLON_PLATFORM_AIX		     0x50
								     
#define TEFLON_PLATFORM_IOS		     0x60
#  define TEFLON_PLATFORM_IOSR	     0x61
#  define TEFLON_PLATFORM_IOSS	     0x62
								     
#define TEFLON_PLATFORM_OSX		     0x70
								     
#define TEFLON_PLATFORM_SOLARIS      0x80
								     
#define TEFLON_PLATFORM_UNKNOWN      -0x1

#endif 