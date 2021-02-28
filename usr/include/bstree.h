#ifndef _BSTREE_H
#define _BSTREE_H

struct elem {
  struct elem *left;
  int data;
  struct elem* right;
};

#include <stdio.h>

struct elem *createNode( int data );
struct elem* insert( struct elem *root, struct elem *node );
void preOrder( struct elem *root );
void inOrder( struct elem *root );
void postOrder( struct elem *root );
struct elem *minSearch( struct elem* root );
struct elem *maxSearch( struct elem* root );
struct elem *search( struct elem *root, int data );
int checkBst( struct elem *root );

#endif
