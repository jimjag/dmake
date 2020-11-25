/* RCS  $Id: tempnam.c,v 1.2 2002-07-11 08:53:35 mh Exp $
--
-- SYNOPSIS
--      tempnam
--
-- DESCRIPTION
--      temp file name generation routines.
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

#ifdef __APPLE__

/*LINTLIBRARY*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#if defined(max)
#   undef  max
#endif
#define max(A,B) (((A)<(B))?(B):(A))

extern char *mktemp();
extern int access();
extern pid_t getpid(void);
int d_access();
extern pid_t getpid(void);

char *
dtempnam(dir, prefix)
char *dir;		/* use this directory please (if non-NULL) */
char *prefix;		/* use this (if non-NULL) as filename prefix */
{
   static         int count = 0;
   register char *p, *q, *tmpdir;
   int            tl=0, dl=0, pl;
   char		  buf[30];

   pl = strlen(P_tmpdir);

   if( (tmpdir = getenv("TMPDIR")) != NULL ) tl = strlen(tmpdir);
   else if( (tmpdir = getenv("TMP")) != NULL ) tl = strlen(tmpdir);
   if( dir != NULL ) dl = strlen(dir);

   if( (p = malloc((unsigned)(max(max(dl,tl),pl)+13))) == NULL )
     return(NULL);

   *p = '\0';

   if( (tl == 0) || (d_access( strcpy(p, tmpdir), 0) != 0) )
     if( (dl == 0) || (d_access( strcpy(p, dir), 0) != 0) )
	if( d_access( strcpy(p, P_tmpdir), 0) != 0 )
	   if( !prefix )
	      prefix = "tp";

   if(prefix)
   {
      *(p+strlen(p)+2) = '\0';
      (void)strncat(p, prefix, 2);
   }

   sprintf( buf, "%08x", getpid() );
   buf[6]='\0';
   (void)strcat(p, buf );
   sprintf( buf, "%04d", count++ );
   q=p+strlen(p)-6;
   *q++ = buf[0]; *q++ = buf[1];
   *q++ = buf[2]; *q++ = buf[3];

   if( (q = strrchr(p,'.')) != NULL ) *q = '\0';

   return(p);
}



int d_access( name, flag )
char *name;
int  flag;
{
   extern char *DirSepStr;
   char *p;
   int r;

   if( name == NULL || !*name ) return(1);  /* NULL dir means current dir */
   r = access( name, flag );
   p = name+strlen(name)-1;
   if(*p != '/' && *p != '\\') strcat( p, DirSepStr );

   return( r );
}

#endif
