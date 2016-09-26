/**
 *
 * @file  del_tail.c
 * @brief Removes the last node from a list
 *
 */

#include "lists.h"

/* #FUNC:  del_tail
 * 
 * Removes last node in list
 * 
 */

int
del_tail (list_t *list)
{
  /* minimal sanity check */

  printf("DEBUG: del_tail (list = %p)\n", list);
  
  if (list->last)
    {
      node_t *worknode, *lastnode;

      printf ("DEBUG: del_tail: last is not empty\n");
      printf ("DEBUG: del_tail: nodecnt=%d\n",list->nodecnt);
      
      lastnode = list->last;
      printf ("DEBUG: del_tail: after set lastnode\n");
      worknode = lastnode->prev;

      if (worknode != NULL)
       {
         worknode->next = 0;
       }
      printf ("DEBUG: del_tail: after set worknode [worknode=%p]\n",worknode);
      
      /* let's break the chain */
      
      printf ("DEBUG: del_tail: after set worknode\n");
      lastnode->prev = 0; 
      lastnode->head = 0; 
      list->nodecnt -= 1;

      /* let's call the deletion handler if any exists */

      printf("DEBUG: del_tail: checking for custom deletion handler\n");

      if (lastnode->del_handler)
        {
          printf("DEBUG: del_tail: calling custom deletion handler\n");
          lastnode->del_handler (lastnode);
        }

      return 0;
    }
  else
    {
      return 1;
    }
}

