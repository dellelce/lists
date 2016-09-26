/**
 *
 * @file  add_empty_tail.c 
 * @brief Adds an "empty" node at end of a list
 *
 */

#include "lists.h"

/* @fn node_t *add_empty_tail (list_t *list)
 *
 */

node_t *
add_empty_tail (list_t *list)
{
  node_t *newnode;
    
#ifdef DEBUG
    printf ("DEBUG: add_empty_tail(list = %p)\n", list);
#endif
    
  newnode = new_node(0,list->defaultnodesize);
  
  if (newnode)
    {
      if (list->node_del_handler)
	{
	  newnode->del_handler = list->node_del_handler;
	}

      if (!add_tail (list, newnode))
	{
	  /* success !!! */

	  return newnode;
	}
      else
	{
	  /* failure ????? */

	  free_node (newnode);
	  return 0;
	}
    }
  else
    {
      /* failed to create a new empty node !?!@!?!? */
      
      return 0;
    }
}

/* EOF */
