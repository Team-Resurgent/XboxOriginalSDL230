/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

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

#include "../../SDL_internal.h"
#include "../../core/xboxog/SDL_xboxog.h"
#include "../SDL_syslocale.h"

typedef BOOL(WINAPI *pfnGetUserPreferredUILanguages)(DWORD, PULONG, WCHAR *, PULONG);
#ifndef MUI_LANGUAGE_NAME
#define MUI_LANGUAGE_NAME 0x8
#endif

static pfnGetUserPreferredUILanguages pGetUserPreferredUILanguages = NULL;
static HMODULE kernel32 = 0;

/* this is the fallback for WinXP...one language, not a list. */
static void SDL_SYS_GetPreferredLocales_winxp(char *buf, size_t buflen)
{
    char lang[16];
    char country[16];

    const int langrc = GetLocaleInfoA(LOCALE_USER_DEFAULT,
                                      LOCALE_SISO639LANGNAME,
                                      lang, sizeof(lang));

    const int ctryrc = GetLocaleInfoA(LOCALE_USER_DEFAULT,
                                      LOCALE_SISO3166CTRYNAME,
                                      country, sizeof(country));

    /* Win95 systems will fail, because they don't have LOCALE_SISO*NAME ... */
    if (langrc == 0) {
        SDL_SetError("Couldn't obtain language info");
    } else {
        (void)SDL_snprintf(buf, buflen, "%s%s%s", lang, ctryrc ? "_" : "", ctryrc ? country : "");
    }
}

void SDL_SYS_GetPreferredLocales(char *buf, size_t buflen)
{
    if (!kernel32) {
        kernel32 = GetModuleHandle(TEXT("kernel32.dll"));
        if (kernel32) {
            pGetUserPreferredUILanguages = (pfnGetUserPreferredUILanguages)GetProcAddress(kernel32, "GetUserPreferredUILanguages");
        }
    }

    SDL_SYS_GetPreferredLocales_winxp(buf, buflen); /* this is always available */
}

/* vi: set ts=4 sw=4 expandtab: */
