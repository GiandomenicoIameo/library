#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"

struct elem* create( int data ) {

  struct elem *node;

  node = ( struct elem* )malloc( sizeof( struct elem ) );
  if( node == NULL ) return node;

  node->data = data;
  node->next = NULL;

  return node;
}

struct elem* append( struct elem *top, struct elem *node ) {

  struct elem *res;

  if( top == NULL )
      res = node;
  else {
      top->next = append( top->next, node );
      res = top;
  }
  return res;
}

struct elem *delete( struct elem *top, int data ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      if( top->data == data ) {
          res = top->next;
          free( top );
      }
      else {
          top->next = delete( top->next, data );
          res = top;
      }
  }
  return res;
}

struct elem *search( struct elem *top, int data ) {

  if( top == NULL )
      return top;
  else {
      if( top->data == data )
          return top;
      else
          return search( top->next, data );
  }
}

struct elem *duplicate( struct elem *top ) {

  struct elem *res;
  struct elem *node;

  if( top == NULL )
      res = top;
  else {
      node = create( top->data );
      node->next = duplicate( top->next );
      res = node;
  }
  return res;
}
