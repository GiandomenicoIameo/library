#include <stdlib.h>
#include "include/stdlist.h"

struct elem *create( int key ) {

  struct elem *node;

  node = ( struct elem* )malloc( sizeof( struct elem ) );
  if( node == NULL ) return node;

  node->data = key;
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

struct elem *inorder( struct elem *top, struct elem *node ) {

  struct elem *res;

  if( top == NULL )
      res = node;
  else {
      if( top->data > node->data ) {
          node->next = top;
          res = node;
      }
      else {
          top->next = inorder( top->next, node );
          res = top;
      }
  }
  return res;
}

struct elem *delete( struct elem *top, int key ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      if( top->data == key ) {
          res = top->next;
          free( top );
      }
      else {
          top->next = delete( top->next, key );
          res = top;
      }
  }
  return res;
}

struct elem *address( struct elem *top, int key ) {

  struct elem *res;

  if( top == NULL )
      res = top;
  else {
      if( top->data == key )
          res = top;
      else
          res = address( top->next, key );
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

struct elem *concatenate( struct elem *top1, struct elem *top2 ) {

  struct elem *res;

  if( top1 == NULL )
      res = top2;
  else {
      top1->next = concatenate( top1->next, top2 );
      res = top1;
  }
  return res;
}

struct elem *merge( struct elem *top1, struct elem *top2 ) {

  struct elem *res;

  if( top1 == NULL || top2 == NULL ) {
      if( top1 == NULL )
          res = top1;
      else
          res = top2;
  }
  else {
      if( top1->data < top2->data ) {
          top1->next = merge( top1->next, top2 );
          res = top1;
      }
      else {
          top2->next = merge( top1, top2->next );
          res = top2;
      }
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