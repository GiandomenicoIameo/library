/* This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY. For more details consult the code.

   This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 List      <list.h>
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

struct elem {
  int data;
  struct elem *next;
};

struct elem *create( int data );
struct elem *delete( struct elem *top, int data );
struct elem *append( struct elem *top, struct elem *node );
struct elem *search( struct elem *top, int data );
struct elem *duplicate( struct elem *top );

#endif
