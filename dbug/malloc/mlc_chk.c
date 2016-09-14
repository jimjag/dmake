/*
 * (c) Copyright 1990 Conor P. Cahill (uunet!virtech!cpcahil).  
 * You may copy, distribute, and use this software as long as this
 * copyright statement is not removed.
 */

#include <stdio.h>
#include "malloc.h"
#include "debug.h"

#ifndef lint
static
char rcs_hdr[] = "$Id: mlc_chk.c,v 1.2 2006-07-25 10:09:34 rt Exp $";
#endif

extern struct mlist	  malloc_start;
extern struct mlist	* malloc_end;
extern char		* malloc_data_start;
extern char		* malloc_data_end;

/*
 * Function:	malloc_in_arena()
 *
 * Purpose:	to verify address is within malloc arena.
 *
 * Arguments:	ptr	- pointer to verify
 *
 * Returns:	TRUE	- if pointer is within malloc area
 *		FALSE	- otherwise
 *
 * Narrative:
 *   IF pointer is >= malloc area start AND <= malloc area end
 *      return TRUE
 *   ELSE
 *      return FALSE
 *
 * Mod History:	
 *   90/01/24	cpcahil		Initial revision.
 */
int
malloc_in_arena(ptr)
	char	* ptr;
{
	extern char	* malloc_data_start;
	extern char	* malloc_data_end;
	int		  rtn = 0;

	if( ptr >= malloc_data_start && ptr <= malloc_data_end )
	{
		rtn = 1;
	}
	
	return(rtn);
}

/*
 * Function:	malloc_check_str()
 *
 * Arguments:	func	- name of function calling this routine
 *		str	- pointer to area to check
 *
 * Purpose:	to verify that if str is within the malloc arena, the data 
 *		it points to does not extend beyond the applicable region.
 *
 * Returns:	Nothing of any use (function is void).
 *
 * Narrative:
 *   IF pointer is within malloc arena
 *      determin length of string
 *      call malloc_verify() to verify data is withing applicable region
 *   return 
 *
 * Mod History:	
 *   90/01/24	cpcahil		Initial revision.
 *   90/01/29	cpcahil		Added code to ignore recursive calls.
 */
void
malloc_check_str(func,str)
	char		* func;
	char		* str;
{
	static int	  layers;
	register char	* s;

	if( (layers++ == 0) &&  malloc_in_arena(str) )
	{
		for( s=str; *s; s++)
		{
		}
		
		malloc_verify(func,str,s-str+1);
	}

	layers--;
}

/*
 * Function:	malloc_check_strn()
 *
 * Arguments:	func	- name of function calling this routine
 *		str	- pointer to area to check
 * 		len     - max length of string
 *
 * Purpose:	to verify that if str is within the malloc arena, the data 
 *		it points to does not extend beyond the applicable region.
 *
 * Returns:	Nothing of any use (function is void).
 *
 * Narrative:
 *   IF pointer is within malloc arena
 *      determin length of string
 *      call malloc_verify() to verify data is withing applicable region
 *   return 
 *
 * Mod History:	
 *   90/01/24	cpcahil		Initial revision.
 *   90/01/29	cpcahil		Added code to ignore recursive calls.
 *   90/08/29	cpcahil		added length (for strn* functions)
 */
void
malloc_check_strn(func,str,len)
	char		* func;
	char		* str;
	int		  len;
{
	register int	  i;
	static int	  layers;
	register char	* s;

	if( (layers++ == 0) &&  malloc_in_arena(str) )
	{
		for( s=str,i=0; (i < len) && *s; s++)
		{
		}
		
		malloc_verify(func,str,s-str+1);
	}

	layers--;
}

/*
 * Function:	malloc_check_data()
 *
 * Arguments:	func	- name of function calling this routine
 *		ptr	- pointer to area to check
 *		len 	- length to verify
 *
 * Purpose:	to verify that if ptr is within the malloc arena, the data 
 *		it points to does not extend beyond the applicable region.
 *
 * Returns:	Nothing of any use (function is void).
 *
 * Narrative:
 *   IF pointer is within malloc arena
 *      call malloc_verify() to verify data is withing applicable region
 *   return 
 *
 * Mod History:	
 *   90/01/24	cpcahil		Initial revision.
 *   90/01/29	cpcahil		Added code to ignore recursive calls.
 */
void
malloc_check_data(func,ptr,len)
	char		* func;
	char		* ptr;
	int		  len;
{
	static int	  layers;

	if( layers++ == 0 )
	{
		DEBUG3(40,"malloc_check_data(%s,0x%x,%d) called...",
			func,ptr,len);
		if( malloc_in_arena(ptr) )
		{
			DEBUG0(10,"pointer in malloc arena, verifying...");
			malloc_verify(func,ptr,len);
		}
	}

	layers--;
}

/*
 * Function:	malloc_verify()
 *
 * Arguments:	func	- name of function calling the malloc check routines
 *		ptr	- pointer to area to check
 *		len 	- length to verify
 *
 * Purpose:	to verify that the data ptr points to does not extend beyond
 *		the applicable malloc region.  This function is only called 
 *		if it has been determined that ptr points into the malloc arena.
 *
 * Returns:	Nothing of any use (function is void).
 *
 * Narrative:
 *
 * Mod History:	
 *   90/01/24	cpcahil		Initial revision.
 */
void
malloc_verify(func,ptr,len)
	char		* func;
	char		* ptr;
	int		  len;
{
	extern struct mlist	* malloc_end;
	extern int		  malloc_errno;
	extern struct mlist 	  malloc_start;
	struct mlist		* mptr;
	
	DEBUG3(40,"malloc_verify(%s,0x%x,%d) called...", func,ptr,len);
	/*
	 * Find the malloc block that includes this pointer
	 */
	mptr = &malloc_start;
	while( mptr && 
		! (((char *)mptr < ptr) && ((mptr->data+mptr->s.size) > ptr) ) )
	{
		mptr = mptr->next;
	}

	/*
	 * if ptr was not in a malloc block, it must be part of
	 *    some direct sbrk() stuff, so just return.
	 */
	if( ! mptr )
	{
		DEBUG1(10,"ptr (0x%x) not found in malloc search", ptr);
		return;
	}
	
	/*
 	 * Now we have a valid malloc block that contains the indicated
	 * pointer.  We must verify that it is withing the requested block
	 * size (as opposed to the real block size which is rounded up to
	 * allow for correct alignment).
	 */

	DEBUG4(60,"Checking  0x%x-0x%x, 0x%x-0x%x",
			ptr, ptr+len, mptr->data, mptr->data+mptr->r_size);
	
	if( (ptr < mptr->data) || ((ptr+len) > (mptr->data+mptr->r_size)) )
	{
		DEBUG4(0,"pointer not within region 0x%x-0x%x, 0x%x-0x%x",
			ptr, ptr+len, mptr->data, mptr->data+mptr->r_size);

		malloc_errno = M_CODE_OUTOF_BOUNDS;
		malloc_warning(func);
	}

	return;
}

