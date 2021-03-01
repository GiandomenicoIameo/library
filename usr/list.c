#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"

struct elem *create( int data ) {

  struct elem *node;

  node = ( struct elem* )malloc( sizeof( struct elem ) );
  if( node == NULL ) return node;

  node->data = data;
  node->next = NULL;

  return node;
}

struct elem *append( struct elem *top, struct elem *node ) {

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

struct elem *address( struct elem *top, int data ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      if( top->data == data )
          res = top;
      else
          res = address( top->next, data );
  }
  return res;
}

struct elem *copy( struct elem *top ) {

  struct elem *res;
  struct elem *node;

  if( top == NULL )
      res = top;
  else {
      node = create( top->data );
      node->next = copy( top->next );
      res = node;
  }
  return res;
}

struct elem *max( struct elem *top ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      res = max( top->next );

      if( res == NULL ) res = top;
      else {
        if( top->data > res->data ) res = top;
      }
  }
  return res;
}

struct elem *min( struct elem *top ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      res = min( top->next );

      if( res == NULL ) res = top;
      else {
        if( top->data < res->data ) res = top;
      }
  }
  return res;
}

struct elem *merge( struct elem *top1, struct elem *top2 ) {

  struct elem *res;

  if( top1 == NULL )
      res = top2;
  else {
      top1->next = merge( top1->next, top2 );
      res = top1;
  }
  return res;
}

struct elem *clear( struct elem *top ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      res = clear( top->next );
      free( top );
  }
  return res;
}
