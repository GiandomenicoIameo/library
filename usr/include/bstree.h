/* This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 Bstree      <bstree.h>
*/

#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>

struct elem {
  struct elem *left;
  int data;
  struct elem* right;
};

struct elem *createNode( int data );
struct elem* insert( struct elem *root, int data );
int checkBst( struct elem *root );

// Algorithms for visiting binary trees
void preOrder( struct elem *root );
void inOrder( struct elem *root );
void postOrder( struct elem *root );

// Search algorithms
struct elem *minSearch( struct elem* root );
struct elem *maxSearch( struct elem* root );
struct elem *search( struct elem *root, int data );

/* The following algorithm is able to sort
every element belonging to a set. Consequently, 
the elements must necessarily be different. 
moreover the complexity of this 
algorithm, in the best case, is O( nlogn )*/

void bstSort( int* array, const int len  );
void sort( struct elem *root, int* array );

#endif
