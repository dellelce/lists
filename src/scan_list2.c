/**
 *
 * @file   scan_list2.c
 * @brief  enhanced scan_list
 *
 */

#include "lists.h"

// Scan states
// added: 2131 220510

#define SCAN_STATE_NORMAL	0 // Scanning operating
#define SCAN_STATE_EXIT		1 // Exiting due to matching condition
#define SCAN_STATE_ERROR	2 // Aborting scan due to error
#define SCAN_STATE_WARNING	3 // At least an error happened but continuing scan [?]
#define SCAN_STATE_IGNORE	4 // Ignoring entries [?]

// return type

#define scan_msg_t		unsigned short


int 
scan_list2 (
		list_t *list,
		scan_msg_t (*scanfunc)(list_t *list, node_t *node, void *searchdata),
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
