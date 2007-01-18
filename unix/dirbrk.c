/* RCS  $Id: dirbrk.c,v 1.2 2007-01-18 09:44:04 vg Exp $
--
-- SYNOPSIS
--      Define the directory separator string.
-- 
-- DESCRIPTION
-- 	Define this string for any character that may appear in a path name
--	and can be used as a directory separator.  Also provide a function
--	to indicate if a given path begins at the root of the file system.
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
--      in the file <distribution-root>/readme/license.txt.
--
-- LOG
--      Use cvs log to obtain detailed change logs.
*/

#include "extern.h"

/* Unix only uses / */
char*	DirBrkStr = "/";

/*
** Return TRUE if the name is the full specification of a path name to a file
** starting at the root of the file system, otherwise return FALSE
*/
PUBLIC int
If_root_path(name)
char *name;
{
   return( strchr(DirBrkStr, *name) != NIL(char)
#ifdef HAVE_DRIVE_LETTERS
	   || (*name && name[1] == ':' && isalpha(*name))
#endif
	   );
}
