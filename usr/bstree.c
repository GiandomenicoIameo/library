#include <stdio.h>
#include <stdlib.h>
#include "include/bstree.h"

struct elem *createNode( int data ) {

  struct elem *node;

  node = ( struct elem* )malloc( sizeof( struct elem ) );
  if( !node ) return node;

  node->left = NULL;
  node->data = data;
  node->right = NULL;

  return node;
}

struct elem *insert( struct elem *root, int data ) {

  struct elem *node = createNode( data );
  struct elem *res;

  if( !root ) {
          res = node;
  } else {
          if( data == root->data ) {
                  res = root;
  } else if( root->data < data ) {
          root->right = insert( root->right, data );
                  res = root;
  } else {
          root->left = insert( root->left, data );
          res = root;
      }
  }
  return res;
}

void preOrder( struct elem *root ) {

  if( root ) {
          printf( "%d ", root->data );
          preOrder( root->left );
          preOrder( root->right );
  }
}

void inOrder( struct elem *root ) {

  if( root ) {
          inOrder( root->left );
          printf( "%d ", root->data );
          inOrder( root->right );
  }
}

void postOrder( struct elem *root ) {

  if( root ) {
          postOrder( root->left );
          postOrder( root->right );
          printf( "%d ", root->data );
  }
}

struct elem *minSearch( struct elem* root ) {

  struct elem *res;

  if( !root ) {
          res = root;
  } else {
          if( root->left )
                  res =  minSearch( root->left );
          else
                  res = root;
  }
  return res;
}

struct elem *maxSearch( struct elem* root ) {

  struct elem *res;

  if( !root ) {
      res = root;
  } else {
      if( root->right )
              res =  minSearch( root->right );
      else
              res = root;
  }
  return res;
}

struct elem *search( struct elem *root, int data ) {

  struct elem *res;

  if( !root ) {
          res = root;
  } else {
          if( data == root->data )
                  res = root;
          else if( data > root->data )
                  res = search( root->right, data );
          else
                  res = search( root->left, data );
  }
  return res;
}

int checkBst( struct elem *root ) {

  struct elem *max, *min;

  if( !root ) {
          return 1;
  } else {
          max = maxSearch( root->left );
          min = minSearch( root->right );

          if( max != NULL && max->data > root->data )
                  return 0;
          if( min != NULL && min->data < root->data )
                  return 0;
          return checkBst( root->left ) && checkBst( root->right );
  }
}

void bstSort( int* array, const int len ) {

  struct elem *root = NULL;

  for( int step = 0; step < len; step++ )
          root = insert( root, array[ step ] );
  sort( root, array );
}

void sort( struct elem *root, int* array ) {

  static int step = 0;

  if( root ) {
          sort( root->left, array );
          array[ step++ ] = root->data;
          sort( root->right, array );
  }
}
