/**
 *
 * @file  del_list.c
 * @brief Removes an entire list 
 *
 */

#include "lists.h"

/* #FUNC: del_list
 * 
 * 
 */

int
del_list (list_t *list, int freenode)
{
  node_t *worknode = 0;
  node_t *nextnode = 0;

#ifdef DEBUG
  printf("DEBUG: del_list(list = %p, freenode = %d)\n", list, freenode);
#endif
  
  if (list)
    {
      worknode = list->first;
    }
  else
    {
      return 1;
    }

#ifdef DEBUG
  printf("DEBUG: del_list: after sanity checks\n");
#endif

  while (worknode)
    {
      nextnode = worknode->next;

      if (freenode == LISTS_FALSE)
	{
	  if (worknode->prev)
	    {
	      worknode->prev = 0;
	    } 
	  
	  if (worknode->next)
	    {
	      worknode->prev = 0;
	    }
	}
      else
	{
	  if (worknode->del_handler)
	    {
	      worknode->del_handler (worknode); 
	    }
	
	  free_node (worknode);
	}

      worknode = nextnode;
    }


  return 0;
}
