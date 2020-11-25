/* RCS  $Id: string.h,v 1.1.1.1 2000-09-22 15:33:34 hr Exp $
--
-- SYNOPSIS
--      string function headers
-- 
-- DESCRIPTION
--      Supply correct definitions for certain string functions.
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
#ifndef STRING_h
#define STRING_h

/*
** BSD does this wrong
*/
#include <strings.h>

#include "stdmacs.h"
extern	char*	strpbrk ANSI((char* src, char* any));

#ifndef DBUG
#define	strchr(str,c)	index(str,c)
#define	strrchr(str,c)	rindex(str,c)
#else
char *strchr ANSI((char*, char));
char *strrchr ANSI((char*, char));
#endif
#endif
