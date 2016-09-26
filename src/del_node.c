/**
 *
 * @file  del_node.c
 * @brief Removes a node from a list 
 *
 */

#include "lists.h"

/* #FUNC:  del_node
 * 
 * 
 */

int
del_node (list_t *list, node_t *node)
{
//1809 190510 Sanity Tests

#ifdef DEBUG
  printf("DEBUG: del_node(list = %p, node = %p)\n", list, node);
#endif

  if (list == NULL || node == NULL) return 1;

// EOST

  if (node->head != list)
    {
      return 1; /* node is not in the list ! */
    }
  else
    {
      if (node == list->last)
	{
	  printf("DEBUG: node is last in list, calling del_tail\n");
	  return del_tail (list);
	}
      else
	{
	  /* worknode has been used to simplify */
	  node_t *worknode = node->next;
	  
	  worknode->prev = node->prev;
	  worknode = node->prev;
	  
	  worknode->next = node->next; 
	  node->prev = node->next = 0;
          // added: 1826 220510
          // clean pointer to former list so delete_handler 
	  // will not thing it is still in the list!
	  node->head= 0;

          if (node->del_handler != NULL)
            {
	      printf("DEBUG: del_node: calling deletion handler\n");
              node->del_handler (node);
            }
	  
	  list->nodecnt -= 1;
	  return 0;
	}
    } 
}
