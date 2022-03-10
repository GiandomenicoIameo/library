/* This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY. For more details consult the code.

   This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 Bstree      <bstree.h>
*/

#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

struct tree {
  struct tree *left;
  int data;
  struct tree* right;
};

struct tree *pose( int data );
struct tree *insert( struct tree *root, struct tree *node );
struct tree *destroy( struct tree *root );
int checkup( struct tree *root, int min, int max );

// Algorithms for visiting binary trees
void preOrder( struct tree *root );
void inOrder( struct tree *root );
void postOrder( struct tree *root );

// Search algorithms
struct tree *bsmin( struct tree* root );
struct tree *bsmax( struct tree* root );
struct tree *bstree( struct tree *root, int data );

void bsort( int* array, const int len  );
static void visit( struct tree *root, int *array );

#endif
