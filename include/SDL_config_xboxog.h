/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2019 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef _SDL_config_xbox_h
#define _SDL_config_xbox_h

#include "SDL_platform.h"

typedef signed char int8_t;
typedef short int16_t;
typedef long int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

#define HAVE_LIBC 1

#define HAVE_XINPUT_H 1

/* C headers */
#define STDC_HEADERS 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDARG_H 1
#define HAVE_STRING_H 1
//#define HAVE_INTTYPES_H 1
//#define HAVE_STDINT_H 1
#define HAVE_CTYPE_H 1
#define HAVE_MATH_H 1

/* C library features */
#define HAVE_MALLOC 1
#define HAVE_CALLOC 1
#define HAVE_REALLOC 1
#define HAVE_FREE 1
#undef HAVE_ALLOCA
#define HAVE_GETENV 1
#define HAVE_QSORT 1
#define HAVE_ABS 1
#define HAVE_MEMSET 1
#define HAVE_MEMCPY 1
#define HAVE_MEMMOVE 1
#define HAVE_MEMCMP 1
#define HAVE_STRLEN 1
#define HAVE_STRCHR 1
#define HAVE_STRRCHR 1
#define HAVE_STRSTR 1
#undef HAVE_STRTOD
#define HAVE_ATOI 1
#define HAVE_STRCMP 1
#define HAVE_STRNCMP 1
#undef HAVE_STRCASECMP
#undef HAVE_STRNCASECMP
#define HAVE_SSCANF 1
#define HAVE_SNPRINTF 1
#define HAVE__EXIT 1

/* math library features */
#define SDL_HIDAPI_DISABLED 1

/* Enable the Xbox audio driver (src/audio/xbox/\*.c) */
//#define SDL_AUDIO_DRIVER_XBOXOG 1
//#define HAVE_DSOUND_H 1;

/* Enable the Xbox joystick driver (src/joystick/xbox/\*.c) */
#define SDL_JOYSTICK_XBOXOG   1

/* Enable the stub haptic driver (src/haptic/dummy/\*.c) */
#define SDL_HAPTIC_DISABLED 1

/* Enable the stub shared object loader (src/loadso/dummy/\*.c) */
#define SDL_LOADSO_DISABLED 1

/* Enable the stub sensor driver (src/sensor/dummy/\*.c) */
#define SDL_SENSOR_DISABLED 1

/* Enable the Xbox thread support (src/thread/windows/\*.c) */
#define SDL_THREAD_GENERIC_COND_SUFFIX 1
#define SDL_THREAD_XBOXOG 1

#define SDL_POWER_DISABLED 1

/* Enable the Xbox timer support (src/timer/windows/\*.c) */
//#define SDL_TIMER_XBOXOG 1

/* Enable the Xbox video driver (src/video/xbox/\*.c) */
//#define SDL_VIDEO_DRIVER_XBOX  1

/* Enable the dummy filesystem driver (src/filesystem/dummy/\*.c) */
#define SDL_FILESYSTEM_DUMMY  1

#endif /* _SDL_config_xbox_h */