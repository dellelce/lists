/**
 *
 * @file  add_node_after.c
 * @brief Adds a node in a list after a specified node
 *
 */

#include "lists.h"

/* @fn int add_node_after (list_t *list, node_t *location, node_t *newnode)
 * 
 * Adds a node in a list after a speficied node
 * 
 */


int
add_node_after (list_t *list, node_t *location, node_t *newnode)
{
#ifdef DEBUG
    printf ("DEBUG: add_node_after(list = %p, location = %p, newnode = %p)\n",
			list, location, newnode);
#endif

  /* Sanity Checks */

  if (location->head != list)
    { 
      return LISTS_FALSE;
    }
 
  /* Verify if where exactly we have to add the node */

  if (location == list->last) /* If at the end we use  ... ? */
    {
      add_tail (list,newnode);
      return 0;
    }
  else
    {
      /* Add new node after specified node */


      return 0;
      
    }
 
 #warning "add_node_after: incomplete"

}

/* EOF */
