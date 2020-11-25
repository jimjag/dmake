/* RCS  $Id: posix.h,v 1.3 2006-04-20 12:01:40 hr Exp $
--
-- SYNOPSIS
--      Definition for POSIX conforming defines in dmake.
-- 
-- DESCRIPTION
--	This file is intended to make certain that defines used within dmake
--	for file name lengths, and number of children processes are defined.
--
-- AUTHOR
--      Dennis Vadura, dvadura@dmake.wticorp.com
--
-- WWW
--      http://dmake.wticorp.com/
--
-- COPYRIGHT
--      Copyright (c) 1996,1997 by WTI Corp.  All rights reserved.
-- 
--      This program is NOT free software; you can redistribute it and/or
--      modify it under the terms of the Software License Agreement Provided
--      in the file <distribution-root>/COPYING.
--
-- LOG
--      Use cvs log to obtain detailed change logs.
*/

/* Define the minimum values that each system requires, and do so only if
 * we have not defined these includes elsewhere.  These should already be
 * defined in <limits.h> if you have a C compiler that is POSIX compliant.
 */
#ifndef _POSIX_NAME_MAX
#define _POSIX_NAME_MAX 14
#endif

#ifndef _POSIX_PATH_MAX
#define _POSIX_PATH_MAX 64
#endif

#ifndef _POSIX_CHILD_MAX
#define _POSIX_CHILD_MAX 1
#endif

/* Now define the actual manifests used in the code. */
#ifndef NAME_MAX
#define NAME_MAX _POSIX_NAME_MAX
#endif

#ifndef PATH_MAX
#define PATH_MAX _POSIX_PATH_MAX
#endif

#ifndef CHILD_MAX
#define CHILD_MAX _POSIX_CHILD_MAX
#endif

/* FIXME! This is a very big hammer, these values should be set to
 * sensible values in the architecture dependent sysintf.h files. */
#if NAME_MAX < 255
#undef NAME_MAX
#define NAME_MAX 255
#endif

#if PATH_MAX < 1024
#undef PATH_MAX
#define PATH_MAX 1024
#endif
