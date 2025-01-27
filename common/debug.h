/*
 * debug.h
 * contains utilitary functions for debugging
 *
 * Copyright (c) 2008 Jonathan Beck All Rights Reserved.
 * Copyright (c) 2010 Martin S. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __DEBUG_H
#define __DEBUG_H

#include <plist/plist.h>
#include "libimobiledevice/libimobiledevice.h"

/** Enables calling applications to capture debug messages from libimobiledevice */
typedef void(*idevice_debug_cb_t) (char *message);
void internal_set_debug_callback(idevice_debug_cb_t callback);

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L && !defined(STRIP_DEBUG_CODE)
#define debug_info(...) debug_info_real (__func__, __FILE__, __LINE__, __VA_ARGS__)
#define debug_plist(a) debug_plist_real (__func__, __FILE__, __LINE__, a)
#elif ((defined(__GNUC__) && __GNUC__ >= 3) || (defined(_MSC_VER))) && !defined(STRIP_DEBUG_CODE)
#define debug_info(...) debug_info_real (__FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)
#define debug_plist(a) debug_plist_real (__FUNCTION__, __FILE__, __LINE__, a)
#else
#define debug_info(...)
#define debug_plist(a)
#endif

void debug_info_real(const char *func,
											const char *file,
											int	line,
											const char *format, ...);

void debug_buffer(const char *data, const int length);
void debug_buffer_to_file(const char *file, const char *data, const int length);
void debug_plist_real(const char *func,
											const char *file,
											int	line,
											plist_t plist);

void internal_set_debug_level(int level);

#endif
