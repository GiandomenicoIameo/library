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

#ifndef _STDLIST_H
#define _STDLIST_H

#include <stdlib.h>

struct elem {
    int data;
    struct elem *next;
};

struct equeue {
    struct elem *top;
    struct elem *end;
};

/* Prototype structure for a simply-linked list data structure. */

struct elem *allocate( int key );

// Description alloc()
// memory is allocated for the new node

struct elem *pop( struct elem *top );

// Description pop()

/* Pop operation refers to the removal of an element.
Again, since we only have access to the element at
the top of the stack, there’s only one element that
we can remove. We just remove the top of the stack.
Note: We can also choose to return the value of the
popped element back, its completely at the choice
of the programmer to implement this. */

struct elem *push( struct elem *top, struct elem *node );

// Description push()

/* Push operation refers to inserting an element in the stack.
Since there’s only one position at which the new element can
be inserted top of the stack, the new element is inserted
at the top of the stack. */

struct elem *append( struct elem *top, struct elem *node );

// Description append()

/*Sometimes we must append (or insert to end) new nodes
to the list. Since we only have information about the
head of the list(unless you maintain a last pointer),
we need to traverse the list until we find the last
node. Then we insert new node to the end of the list.
Note that we have to consider special cases such as
list being empty. */

unsigned int len( struct elem *top );

struct elem *inorder( struct elem *top, struct elem *node );

// Description inorder()

/* Sometimes we must insert (to some specific location) new
nodes to a list. It is important that we traverse the list
to find the place to insert the node. In the traversal
process, we must maintain a reference to previous and next
nodes of the list. Then we will insert a new node between
previous and next. */

struct elem *address( struct elem *top, int key );

// Description address()

/* Search for entry matching "key" in the singly-list. If
"key" is "True" return his address or signal error by returning
NULL. */

struct elem *delete( struct elem *top, int key );

// Description delete()

/* Sometimes we must delete a specific node from the list
(if exists). It is important that we traverse the list
to find the node to delete. In the traversal process,
we must maintain a reference to previous node of the
list. We need to worry about de-allocating memory
associated with the deleted node, since C has no
automatic garbage collection.  */

struct elem *copy( struct elem *top );
struct elem *max( struct elem *top );
struct elem *min( struct elem *top );

struct elem *reverse( struct elem *succ, struct elem *prec );

// Complexity reverse()

/* the time complexity of the above solution in
O(n), where n is the total number of nodes
in the linked list, but require any extra space with space complexity O(n). */

struct elem *concatenate( struct elem *top1, struct elem *top2 );

// Description concatenate()

/* The concatenation of two lists into one occurs in linear time
(depending on the data access model). The following code shows
an algorithm that combines top1 and top2 input lists into a new top3 list. */

struct elem *clear( struct elem *top );

struct elem *merge( struct elem *top1, struct elem *top2 );

// Description merge()

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

struct equeue *init( void );

int isempty( void *list );

// Description isempty()

/* To prevent performing operations on an
empty queue, the programmer is required
to internally maintain the size of the
queue which will be updated during enqueue
and deque operations accordingly.
isempty() returns: 1 if size is 0,
else 0 */

static struct elem *add( struct elem *end, struct elem *node );
struct equeue *enqueue( struct equeue *queue, struct elem *node );

// Description enqueue() and add()

/* Dequeue means removing an element from the queue.
Since queue follows the FIFO principle we need to
remove the element of the queue which was inserted
at first. Naturally, the element inserted first
will be at the front of the queue so we will remove
the front element and let the element behind it
be the new front element. */

struct equeue *dequeue( struct equeue *queue );

// Description dequeue()

/* There are several efficient implementations of
FIFO queues. This type of structure perform the
operation en-queuing and de-queuing in O(1) time. */

#endif
