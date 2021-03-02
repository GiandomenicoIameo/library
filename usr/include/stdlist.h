/* This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY. For more details consult the code.

   This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 singly-list      <stdlist.h>

   This file define one type of data structure: singly-linked list.
   A singly-linked list is headed by a single forward pointer. The
   elements are singly linked for minimum space and pointer manipulation
   overhead at the expense of O(n) insertion and removal for arbitrary elements.
   New elements can be added to the list after an existing element or at the
   tail of the list.
   A singly-linked list may only be traversed in the forward direction.
   Singly-linked lists are ideal for applications with large
   datasets and few or no removals.
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
struct elem *inorder( struct elem *top, struct elem *node );

/* Search for entry matching 'key' in the singly-list. If
'key' is 'true' return his address or signal error by returning
NULL. */

struct elem *address( struct elem *top, int key );
struct elem *copy( struct elem *top );
struct elem *max( struct elem *top );
struct elem *min( struct elem *top );

/* The concatenation of two lists into one occurs in linear time
(depending on the data access model). The following code shows
an algorithm that combines top1 and top2 input lists into a new top3 list. */

struct elem *concatenate( struct elem *top1, struct elem *top2 );
struct elem *clear( struct elem *top );

struct elem *merge( struct elem *top1, struct elem *top2 );

/* This merge algorithm is used repeatedly in the merge sort algorithm.

The first element of both lists is compared. If sorting in
ascending order, the smaller element among two becomes a new
element of the sorted list. This procedure is repeated until
both the smaller sublists are empty and the newly combined sublist
covers all the elements of both the sublists.

The algorithm assumes that the two lists are ordered

In the merge sort algorithm, this subroutine is typically
used to merge two sub-arrays A[p...q], A[q+1...r] of a single
array A. This can be done by copying the sub-arrays into a
temporary array, then applying the merge algorithm above. The allocation
of a temporary array can be avoided, but at the expense
of speed and programming ease.  */

#endif