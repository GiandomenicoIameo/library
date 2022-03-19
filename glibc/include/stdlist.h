/*    Author:        Giandomenico Iameo
 *    E-mail:        giandomenicoiameo00@gmail.com
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY. For more details consult the code.
 *    This library is free software; you can redistribute it and/or
 *    modify.
 *
 *    This file define one type of data structure: singly-linked list.
 *    A singly-linked list is headed by a single forward pointer. The
 *    elements are singly linked for minimum space and pointer manipulation
 *    overhead at the expense of O(n) insertion and removal for arbitrary elements.
 *    New elements can be added to the list after an existing element or at the
 *    tail of the list.
 *    A singly-linked list may only be traversed in the forward direction.
 *    Singly-linked lists are ideal for applications with large
 *    datasets and few or no removals.
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

/* node allocation functions */
struct elem *allocate( int key );
struct equeue *init( void );
int isempty( void *list );

/* Standard stack operations */
struct elem *pop( struct elem *top );
struct elem *push( struct elem *top, struct elem *node );

/* Standard queue operations */
struct equeue *enqueue( struct equeue *queue, struct elem *node );
struct equeue *dequeue( struct equeue *queue );


struct elem *append( struct elem *top, struct elem *node );
unsigned int len( struct elem *top );
struct elem *inorder( struct elem *top, struct elem *node );
struct elem *address( struct elem *top, int key );
struct elem *clear( struct elem *top );
struct elem *delete( struct elem *top, int key );
struct elem *copy( struct elem *top );
struct elem *max( struct elem *top );
struct elem *min( struct elem *top );
struct elem *reverse( struct elem *succ, struct elem *prec );
struct elem *concatenate( struct elem *top1, struct elem *top2 );
struct elem *merge( struct elem *top1, struct elem *top2 );
static struct elem *add( struct elem *end, struct elem *node );

#endif
