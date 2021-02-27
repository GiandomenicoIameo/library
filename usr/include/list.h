/* /* This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 List      <list.h>
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>

struct elem {
  int data;
  struct elem *next;
};

struct elem* createList( void );
struct elem* creatNode( int data );
struct elem* push( struct elem *top, struct elem *node );
struct elem* enqueue( struct elem *top, struct elem *node );

#endif
