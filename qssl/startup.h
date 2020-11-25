/* RCS  $Id: startup.h,v 1.2 2006-04-20 12:09:40 hr Exp $
--
-- SYNOPSIS
--      Definition of MAKESTARTUP
-- 
-- DESCRIPTION
--      Default MAKESTARTUP value defining where dmake locates the
--      startup file.
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

"DMAKEROOT *:= $(ROOTDIR)/usr/local/lib/dmake/startup",
"MAKESTARTUP := $(DMAKEROOT)/startup.mk",
