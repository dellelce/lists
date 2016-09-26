/**
 *
 * @file  new_list.c
 * @brief Create an empty list given a node size 
 *
 */

#include "lists.h"
#ifdef DEBUG
#include <stdio.h>
#endif

#include <string.h>


/* #FUNC: new_list
 * 
 * 
 */

list_t *
new_list (int listsize, int defaultnodesize)
{
  list_t *list;
#ifdef DEBUG
  printf ("DEBUG: new_list (listsize = %d, defaultnodesize = %d)\n", listsize, defaultnodesize);
#endif

  if (listsize < sizeof(list_t))
    {
      listsize = sizeof(list_t);
    }

  if (defaultnodesize < sizeof(node_t))
    {
      defaultnodesize = sizeof(node_t);
    }

  list = malloc (listsize);

  if (!list)
    {
#ifdef DEBUG
      printf ("DEBUG: failed to allocate list_t header\n");
#endif
      return 0;
    }
  else
    {
      /* Some init */

      memset (list, 0, listsize);

      list->defaultnodesize = defaultnodesize;

        /* done */
        
#ifdef DEBUG
      printf ("DEBUG: new_list RESULT = %p\n", list);
#endif
      return list;
    }
}
