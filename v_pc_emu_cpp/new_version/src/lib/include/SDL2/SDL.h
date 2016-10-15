/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>

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

/**
 *  \file SDL.h
 *
 *  Main include header for the SDL library
 */

/**
 *  \mainpage Simple DirectMedia Layer (SDL)
 *
 *  http://www.libsdl.org/
 *
 *  \section intro_sec Introduction
 *
 *  Simple DirectMedia Layer is a cross-platform development library designed
 *  to provide low level access to audio, keyboard, mouse, joystick, and
 *  graphics hardware via OpenGL and Direct3D. It is used by video playback
 *  software, emulators, and popular games including Valve's award winning
 *  catalog and many Humble Bundle games.
 *
 *  SDL officially supports Windows, Mac OS X, Linux, iOS, and Android.
 *  Support for other platforms may be found in the source code.
 *
 *  SDL is written in C, works natively with C++, and there are bindings 
 *  available for several other languages, including C# and Python.
 *
 *  This library is distributed under the zlib license, which can be found
 *  in the file "COPYING.txt".
 *
 *  The best way to learn how to use SDL is to check out the header files in
 *  the "include" subdirectory and the programs in the "test" subdirectory.
 *  The header files and test programs are well commented and always up to date.
 *  More documentation and FAQs are available online at:
 *      http://wiki.libsdl.org/
 *
 *  If you need help with the library, or just want to discuss SDL related
 *  issues, you can join the developers mailing list:
 *      http://www.libsdl.org/mailing-list.php
 *
 *  Enjoy!
 *      Sam Lantinga                (slouken@libsdl.org)
 */

#ifndef _SDL_H
#define _SDL_H

#include "../../../../../new_version/src/lib/include/SDL2/begin_code.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_assert.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_atomic.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_audio.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_clipboard.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_cpuinfo.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_endian.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_error.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_events.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_filesystem.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_gamecontroller.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_haptic.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_hints.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_joystick.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_loadso.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_log.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_main.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_messagebox.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_mutex.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_power.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_render.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_rwops.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_stdinc.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_system.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_thread.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_timer.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_version.h"
#include "../../../../../new_version/src/lib/include/SDL2/SDL_video.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* As of version 0.5, SDL is loaded dynamically into the application */

/**
 *  \name SDL_INIT_*
 *
 *  These are the flags which may be passed to SDL_Init().  You should
 *  specify the subsystems which you will be using in your application.
 */
/* @{ */
#define SDL_INIT_TIMER          0x00000001
#define SDL_INIT_AUDIO          0x00000010
#define SDL_INIT_VIDEO          0x00000020  /**< SDL_INIT_VIDEO implies SDL_INIT_EVENTS */
#define SDL_INIT_JOYSTICK       0x00000200  /**< SDL_INIT_JOYSTICK implies SDL_INIT_EVENTS */
#define SDL_INIT_HAPTIC         0x00001000
#define SDL_INIT_GAMECONTROLLER 0x00002000  /**< SDL_INIT_GAMECONTROLLER implies SDL_INIT_JOYSTICK */
#define SDL_INIT_EVENTS         0x00004000
#define SDL_INIT_NOPARACHUTE    0x00100000  /**< Don't catch fatal signals */
#define SDL_INIT_EVERYTHING ( \
                SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | \
                SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER \
            )
/* @} */

/**
 *  This function initializes  the subsystems specified by \c flags
 *  Unless the ::SDL_INIT_NOPARACHUTE flag is set, it will install cleanup
 *  signal handlers for some commonly ignored fatal signals (like SIGSEGV).
 */
extern DECLSPEC int SDLCALL SDL_Init(Uint32 flags);

/**
 *  This function initializes specific SDL subsystems
 */
extern DECLSPEC int SDLCALL SDL_InitSubSystem(Uint32 flags);

/**
 *  This function cleans up specific SDL subsystems
 */
extern DECLSPEC void SDLCALL SDL_QuitSubSystem(Uint32 flags);

/**
 *  This function returns a mask of the specified subsystems which have
 *  previously been initialized.
 *
 *  If \c flags is 0, it returns a mask of all initialized subsystems.
 */
extern DECLSPEC Uint32 SDLCALL SDL_WasInit(Uint32 flags);

/**
 *  This function cleans up all initialized subsystems. You should
 *  call it upon all exit conditions.
 */
extern DECLSPEC void SDLCALL SDL_Quit(void);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "../../../../../new_version/src/lib/include/SDL2/close_code.h"

#endif /* _SDL_H */

/* vi: set ts=4 sw=4 expandtab: */