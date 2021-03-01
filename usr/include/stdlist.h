/* This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY. For more details consult the code.

   This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 singly-list      <stdlist.h>
*/

#ifndef _LIST_H
#define _LIST_H

struct elem {
  int data;
  struct elem *next;
};

/* Prototype structure for a simply-linked list data structure. */

struct elem *create( int key );
struct elem *delete( struct elem *top, int key );
struct elem *append( struct elem *top, struct elem *node );

/* Search for entry matching 'key' in the singly-list. If
   'key' is 'true' return his address or signal error by returning
   NULL. */
struct elem *address( struct elem *top, int key );
struct elem *copy( struct elem *top );
struct elem *max( struct elem *top );
struct elem *min( struct elem *top );

/* Merging two lists into one is done in linear time 
(depending on the data access model). The following code demonstrates 
an algorithm that merges input lists (either linked lists ) 
top1 and top2 into a new list top3. */

struct elem *merge( struct elem *top1, struct elem *top2 );
struct elem *clear( struct elem *top );

#endif
