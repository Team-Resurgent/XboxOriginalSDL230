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

#include <xtl.h>

#include "../../SDL_internal.h"
#include "../SDL_syslocale.h"

void SDL_SYS_GetPreferredLocales(char *buf, size_t buflen)
{
    const char *xboxog_locales[] = {
		"en_US",
        "ja_JP",
        "de_DE",
		"fr_FR",
        "es_ES",
        "it_IT",
        "ko_KR",
        "zh_CN",
        "pt_PT",
    };

    DWORD language = XGetLanguage();
    if (language < XC_LANGUAGE_ENGLISH || language > XC_LANGUAGE_PORTUGUESE) {
        language = XC_LANGUAGE_ENGLISH; // default to english
    }

    SDL_strlcpy(buf, xboxog_locales[language - 1], buflen);
}

/* vi: set ts=4 sw=4 expandtab: */
