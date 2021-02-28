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

// algorithms for visiting binary trees
void preOrder( struct elem *root );
void inOrder( struct elem *root );
void postOrder( struct elem *root );

// search algorithms
struct elem *minSearch( struct elem* root );
struct elem *maxSearch( struct elem* root );
struct elem *search( struct elem *root, int data );

// sorting algorithm of an array
void bstSort( int* array, const int len  );
void sort( struct elem *root, int* array );

#endif
