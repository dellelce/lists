/**
 * 
 * @file  del_all_list.c
 * @brief Deletes a list removing every single node...
 * 
 */ 

#include "lists.h"

/* @fn int del_all_list (list_t *list)
 * @retval 0 Success
 * @retval 1 Failure 
 * 
 */

int
del_all_list (list_t *list)
{
  node_t      *currnode;
  node_t      *nextnode;

  if (!list->first)
    {
      return 1; /* list is empty */
    }

  currnode = list->first;
  
  while (currnode)
    {
      nextnode = currnode->next;
      //added 220510
      currnode->head=0;

      if (currnode->del_handler)
        {
          currnode->del_handler (currnode);
        }

      free (currnode);
      currnode = nextnode;
    }

 return 0;  
}

/* EOF */
