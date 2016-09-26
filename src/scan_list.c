/**
 *
 * @file   scan_list.c
 * @brief  Execute a given function for entire list
 *
 */

#include "lists.h"

int 
scan_list (
		list_t *list,
		int (*scanfunc)(list_t *list, node_t *node, void *searchdata),
		void *searchdata
	  )
{
  node_t   *thisnode;

#ifdef DEBUG
  printf ("DEBUG: scan_list(list = %p, scanfunc = %p, searchdata = %p)\n", list, scanfunc, searchdata);
#endif

  if (!list->current)
    {
      list->current = list->first;
    }

  for (;;)
    {
      thisnode = list->current;

      /* 'process' the node */ 
      
      if (scanfunc (list, thisnode, searchdata) == LISTS_ERROR)
	{
#ifdef DEBUG
          printf ("DEBUG: scan_list: error returned by scanfunc()\n");
#endif 
	  return LISTS_ERROR; /* we abort the scan */
	}
	  
      /* let's check the next node */

      thisnode = thisnode->next;

      if (!thisnode)
	{
	  /* we finished scanning the list */
#ifdef DEBUG
          printf ("DEBUG: scan_list: returning with success [finished list]\n");
#endif 
          list->current = 0;
	  return LISTS_TRUE;
	}
      
      list->current = thisnode;
    } 

  list->current = 0;
  return LISTS_TRUE;
}
