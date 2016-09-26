/**
 *
 * @file  add_head.c
 * @brief Adds a node to the tope of a list
 *
 */

#include "lists.h"

/* @fn int add_head (list_t *list, node_t *newnode)
 * 
 * @brief Adds a node to the head of the list
 * 
 */

int
add_head (list_t *list, node_t *newnode)
{
  node_t *tempnode = list->first;

#ifdef DEBUG
  printf ("DEBUG: add_head(list = %p, newnode = %p)\n", list, newnode);
#endif

  newnode->head = list;

  if (!list->first && !list->last)
    {
      /* empty list !!! easy job!!! */
      
      list->last = list->first = newnode;
      list->nodecnt = 1;
      
      return LISTS_TRUE; 
    }

  tempnode = list->first;
      
  tempnode->prev = newnode;
  newnode->next = tempnode;
      
  /* we make sure that the first node has 'prev'
     set to zero (sanity check)
  */
  newnode->prev = 0;
  
  list->nodecnt += 1;
  
  return LISTS_TRUE;
 
}

/* EOF */
