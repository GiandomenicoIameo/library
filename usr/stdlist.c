#include "include/stdlist.h"

struct elem *create( int key ) {

  struct elem *node;

  node = ( struct elem* )malloc( sizeof( struct elem ) );
  if( !node ) return node;

  node->data = key;
  node->next = NULL;

  return node;
}

struct elem *push( struct elem *top, struct elem *node ) {

  if( !top ) {
          top = node;
  } else {
          node->next = top;
          top = node;
  }
  return top;
}

struct elem *append( struct elem *top, struct elem *node ) {

  struct elem *res;

  if( !top ) {
          res = node;
  } else {
          top->next = append( top->next, node );
          res = top;
  }
  return res;
}

unsigned int len( struct elem *top ) {

  unsigned int res;

  if( !top ) {
          res = 0;
  } else {
          res = len( top->next );
          res = res + 1;
  }
  return res;
}

struct elem *inorder( struct elem *top, struct elem *node ) {

  struct elem *res;

  if( !top ) {
          res = node;
  } else {
          if( top->data > node->data ) {
                  node->next = top;
                  res = node;
          } else {
                  top->next = inorder( top->next, node );
                  res = top;
          }
  }
  return res;
}

struct elem *delete( struct elem *top, int key ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          if( top->data == key ) {
                  res = top->next;
                  free( top );
          } else {
                  top->next = delete( top->next, key );
                  res = top;
          }
  }
  return res;
}

struct elem *pop( struct elem *top ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          res = top->next;
          free( top );
  }
  return res;
}

struct elem *address( struct elem *top, int key ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          if( top->data == key )
                  res = top;
          else
                  res = address( top->next, key );
  }
  return res;
}

struct elem *reverse( struct elem *succ, struct elem *prec ) {

  struct elem *res;

  if( !succ ) {
          res = prec;
  } else {
          res = reverse( succ->next, succ );
          succ->next = prec;
  }
  return res;
}

struct elem *copy( struct elem *top ) {

  struct elem *res;
  struct elem *node;

  if( !top ) {
          res = top;
  } else {
          node = create( top->data );
          node->next = copy( top->next );
          res = node;
  }
  return res;
}

struct elem *max( struct elem *top ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          res = max( top->next );

          if( !res ) {
                  res = top;
          } else {
                  if( top->data > res->data )
                          res = top;
          }
  }
  return res;
}

struct elem *min( struct elem *top ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          res = min( top->next );

          if( !res ) {
                  res = top;
          } else {
                 if( top->data < res->data )
                         res = top;
          }
  }
  return res;
}


struct elem *concatenate( struct elem *top1, struct elem *top2 ) {

  struct elem *res;

  if( !top1 ) {
          res = top2;
  } else {
          top1->next = concatenate( top1->next, top2 );
          res = top1;
  }
  return res;
}

struct elem *merge( struct elem *top1, struct elem *top2 ) {

  struct elem *res;

  if( !top1 || !top2 ) {
          if( !top1 )
                  res = top1;
          else
                  res = top2;
  } else {
          if( top1->data < top2->data ) {
                  top1->next = merge( top1->next, top2 );
                  res = top1;
          } else {
                  top2->next = merge( top1, top2->next );
                  res = top2;
          }
  }
  return res;
}

struct elem *clear( struct elem *top ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          res = clear( top->next );
          free( top );
  }
  return res;
}

int isempty( void *list ) {

  if( !list )
       return 1;
  return 0;
}

struct equeue *init( void ) {

  struct equeue *queue;

  queue = ( struct equeue* )malloc( sizeof( struct equeue ) );
  if( !queue ) return queue;

  queue->top = NULL;
  queue->end = NULL;

  return queue;
}

static struct elem *add( struct elem *end, struct elem *node ) {

  struct elem *res;

  if( !end ) {
          res = node;
  } else {
          end->next = node;
          res = node;
  }
  return res;
}

struct equeue *enqueue( struct equeue *queue, struct elem *node ) {

  struct equeue *res;

  if( !queue ) {
          res = queue;
  } else {
          queue->end = add( queue->end, node );

          if( isempty( queue->top ) )
                  queue->top = queue->end;
          res = queue;
  }
  return res;
}

struct equeue *denqueue( struct equeue *queue ) {

  struct equeue *res;

  if( !queue ) {
          res = queue;
  } else {
          queue->top = pop( queue->top );
          res = queue;
  }
  return res;
}
