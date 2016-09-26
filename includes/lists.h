/*
 * (yet another) Lists management library - by Antonio Dell'elce
 *
 */

/** @cond NoDoc */
#ifndef LISTS_H
#define LISTS_H 1
/** @endcond */

/* includes */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* generic defines */

#ifndef LISTS_TRUE
#define LISTS_TRUE		 1
#endif

#ifndef LISTS_FALSE
#define LISTS_FALSE		 0
#endif

#ifndef LISTS_ERROR
#define LISTS_ERROR		 2 
#endif


#ifdef SEGMENTED_LISTS

#ifndef DEFAULT_SEGSIZE
#define DEFAULT_SEGSIZE		32
#endif

typedef struct __segment
{
 struct _segment  *s_next;
 struct _segment  *s_prev;
 int               s_size;
} segment_t;
#endif

/* simple node */

typedef struct __node_t
{
  struct __node_t  *next;
  struct __node_t  *prev;
  void             *head;
#ifdef SEGMENTED_LISTS
  int               used;      /* in a segmented list we need to know if node is used or not */
  int               segslotid; /* */
  void		   *segment;   /* segments which holds this node... */
#endif
  int               nodesize;
  int              (*del_handler)(struct __node_t *);
#ifdef HAVE_NODE_NODEID
  int               nodeid;
#endif
#ifdef HAVE_ANYTYPE
  anytype_t         data;
#endif
} node_t;

/* list */

typedef struct __list_t
{
  struct __node_t   *first;
  struct __node_t   *last;
  struct __node_t   *current;                                /* if browsing a list  */
  int                lastmsg;                                /* for searching       */
  struct __node_t   *lastsearch;                             /* for searching       */
  int              (*node_del_handler)(struct __node_t *);
#ifdef SEGMENTED_LISTS
  int               segsize;  /* number of nodes in a single segment */
  void		   *firstsegment;
#endif
  unsigned long     defaultnodesize;
  unsigned long     nodecnt;
/* new 010408 1214 */

  int             (*add_tail_action)(struct __list_t *list, node_t *newnode);
} list_t;

#ifdef SEGMENTED_LISTS

typedef struct __segmented_list_t
{
  int               segitems;
  int               segfreeitems; 
  node_t            segnodes[];
} listsegment_t;

#endif

/* Protos */

list_t     *new_list (int listsize, int defaultnodesize);
node_t     *new_node (list_t *list, int nodesize);
int         add_head (list_t *list, node_t *node);
int         add_tail (list_t *list, node_t *newnode);
node_t     *add_empty_tail (list_t *list);
int         add_node_after (list_t *list, node_t *location, node_t *newnode);
int         add_tail (list_t *list, node_t *newnode);
int         del_tail (list_t *list);
int         del_node (list_t *list, node_t *node);
int         del_all_list (list_t *list);
int         del_list (list_t *list, int freenode);
int         scan_list (list_t *list, int (*scan_handler) (list_t *list, node_t *node, 
							void *searchdata), void *searchdata);

/* temp definitions (?) */

#ifndef SEGMENTED_LISTS

#define     free_node(x) free(x)
#else
#define     free_node(x) _seg_free_node(x)

int	    _seg_free_node(node_t *node);

#endif

#define     free_list(x) free(x)

/** @cond NoDoc */
#endif /* LISTS_H */
/** @endcond */

/* EOF */
