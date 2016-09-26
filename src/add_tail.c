/**
 * 
 * @file  add_tail.c
 * @brief Add a node to an of a list
 * 
 */ 

#include "lists.h"

/* @fn int add_tail (list_t *list, node_t *newnode)
 * 
 * Adds a node to the end of the list
 * 
 */

int
add_tail (list_t *list, node_t *newnode)
{
  node_t *tempnode;

#ifdef DEBUG2
  printf ("DEBUG: add_tail (list = %p, newnode = %p)\n", list, newnode);
#endif

  /* we make sure that the first node has 'next'
     set to zero (sanity check)
  */
  newnode->next = 0;
  /* Other sanity check */
  newnode->head = list;

  if (!list->last && !list->first)
    {
      /* empty list !!! easy job!!! */
      
      list->last = list->first = newnode;
      newnode->prev = 0;
      list->nodecnt = 1;
      
      return LISTS_TRUE; /* Success */
    }

  if (!list->last)
    {
      list->first->next = newnode;

      newnode->prev = list->first;

      list->nodecnt = 2;

      return LISTS_TRUE; /* Success */
    }

  /* Save last node to temporary var */

  tempnode = list->last;

  /* Tie together old tail with new one */

  tempnode->next = newnode;
  newnode->prev  = tempnode;

  /* Change tail */

  list->last     = newnode;
  newnode->next  = 0;
  
  list->nodecnt += 1;
  
  return LISTS_TRUE; /* Success */
}

/* EOF */
