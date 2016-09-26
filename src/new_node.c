/**
 *
 * @file  new_node.c
 * @brief Create a new empty node of specified or default size !!
 *
 */

#include "lists.h"


/* @fn node_t *new_node (list_t *holder, int nodesize) 
 * @retval 0 new_node failed to create a new node.
 * 
 */

#warning "Segmented lists not completed."

#ifndef SEGMENTED_LISTS

node_t *
new_node (list_t *holder, int nodesize) /* holder is optional!!! */
{
  node_t *node;

  if (nodesize < sizeof(node_t))
    {
      nodesize = sizeof(node_t);
    }

  node = malloc (nodesize);

  if (!node)
    {
      return 0;
    }
  else
    {
      /* Some init */
      
      memset(node, 0, nodesize);

      if (holder) 
        {
          if (holder->node_del_handler)
            {
               node->del_handler = holder->node_del_handler;
            }
        }

      node->nodesize = nodesize;

      /* done */

      return node;
    }
}

#else
#warning "segmented nodes not completed yet"
node_t *
new_node (list_t *holder, int nodesize) /* holder is optional!!! */
{
  listsegment_t  *Segment = holder->firstsegment;
  unsigned long   SegSize;
  node_t         *Node = 0;

  /* if there is no segment allocate it... */

  if (!Segment)
    {
      SegSize = sizeof(listsegment_t) + (nodesize * holder->segsize);
      Segment = malloc (SegSize);

      /* malloc() sanity test */
 
      if (!Segment) return 0; /* malloc() failed! */
    
      /* clean-up allocated space... */
 
      memset (Segment, 0, SegSize);

      /* set attributes of the new segment */

      Segment->segitems = Segment->segfreeitems = holder->segsize;
      Segment->segfirstfree = 1;

      /* List will use this segment.... */

      holder->firstsegment = Segment;

      /* set node ... */

      Node = &Segment->segnodes[0]; 

      Node->nodesize = nodesize;
      Node->used     = LISTS_TRUE;
     
      return Node; 
   }
 else
   {
     /* find an unreserved node... */

#warning "add_node: this is complete..."

     int Cnt = 0;

     Segment = holder->firstsegment;

     while (Cnt !=  holder->segsize)
       {
         /* */
         if (Segment->segfreeitems)
         {}
          
       }

   }


}

#endif
