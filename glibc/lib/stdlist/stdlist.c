#include "../../include/stdlist.h"

struct elem *allocate( int key ) {

    struct elem *node;

    node = ( struct elem* )malloc( sizeof( struct elem ) );
    if( !node ) return node;

    node->data = key;
    node->next = NULL;

    return node;
}

struct elem *push( struct elem *top, struct elem *const node ) {

    if( !top ) {
            top = node;
    } else {
          node->next = top;
            top = node;
    }
    return top;
}

struct elem *append( struct elem *top, struct elem *const node ) {

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

struct elem *inorder( struct elem *top, struct elem *const node ) {

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

struct elem *reverse_1( struct elem *top ) {

    struct elem *res;

    if( !top ) {
            res = top;
    } else {
            res = append( top, reverse_1( top->next ) );
    }
    return res;
}

struct elem *reverse_2( struct elem *succ, struct elem *const prec ) {

    struct elem *res;

    if( !succ ) {
            res = prec;
    } else {
            res = reverse_2( succ->next, succ );
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
            node = allocate( top->data );
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

int isempty( void *top ) {

    if( !top )
         return 1;
    return 0;
}

struct queue *init( void ) {

    struct queue *equeue;

    equeue = ( struct queue* )malloc( sizeof( struct queue ) );
    if( !equeue ) return equeue;

    equeue->top = NULL;
    equeue->end = NULL;

    return equeue;
}

static struct elem *add( struct elem *end, struct elem *const node ) {

    struct elem *res;

    if( !end ) {
            res = node;
    } else {
            end->next = node;
            res = node;
    }
    return res;
}

struct queue *enqueue( struct queue *equeue, struct elem *const node ) {

    struct queue *res;

    if( !equeue ) {
            res = equeue;
    } else {
            equeue->end = add( equeue->end, node );
            if( isempty( equeue->top ) )
                    equeue->top = equeue->end;
            res = equeue;
    }
    return res;
}

struct queue *dequeue( struct queue *equeue ) {

    struct queue *res;

    if( !equeue ) {
            res = equeue;
    } else {
            equeue->top = pop( equeue->top );
            res = equeue;
    }
    return res;
}
