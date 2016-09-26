/**
 *
 * @file  seg_free_node.c
 * @brief Uncompleted implementation of "Segmented-lists free_node()" 
 *
 */
/*
 * (yet another) Lists management library - by Antonio Dell'elce
 *
 */


#include "lists.h"

#warning "this file has not been completed"


#ifdef SEGMENTED_LISTS

int 
_seg_free_node(node_t *Node)
{
 if (!Node) return 1;

 if (Node->used) 
   {
     Node->used = 0; /* release node! */

     /* Increase number of Free Nodes for Node's Segment */

     ((listsegment_t *) Node->segment)->segfreeitems += 1;

     /* *SHOULD* free() segment if completely free... */
   }
 else
   {
     return 1;
   }
}

#endif /* SEGMENTED_LISTS */

#ifdef DO_NOT_COMPILE

/* normal list */

typedef struct __list_t
{
  struct __node_t   *first;
  struct __node_t   *last;
  struct __node_t   *current;                                /* if browsing a list  */
  int                lastmsg;                                /* for searching       */
  struct __node_t   *lastsearch;                             /* for searching       */
  int              (*node_del_handler)(struct __node_t *);
#ifdef SEGMENTED_LISTS
  /* number of node in a single segment */
  int               segsize; 

  /* first segment */
  void             *firstsegment;

  /* last segment */
  void             *lastsegment;
#endif
  unsigned long     defaultnodesize;
  unsigned long     nodecnt;
} list_t;

#ifdef SEGMENTED_LISTS
typedef struct __segmented_list_t
{
  int               segitems;
  int               segfreeitems; 
  node_t            segnodes[];
} listsegment_t;

#endif

#endif
