#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

struct elem *createNode( int data ) {

  struct elem *node;

  node = ( struct elem* )malloc( sizeof( struct elem ) );
  if( node == NULL ) return node;

  node->left = NULL;
  node->data = data;
  node->right = NULL;

  return node;
}

struct elem *insert( struct elem *root, struct elem *node ) {

  struct elem *res;

  if( root == NULL ) {
      res = node;
  }
  else {
      if( node->data == root->data ) {
          res = root;
      }
      else if( node->data > root->data ) {
          root->right = insert( root->right, node );
          res = root;
      }
      else {
          root->left = insert( root->left, node );
          res = root;
      }
  }
  return res;
}

void preOrder( struct elem *root ) {

  if( root != NULL ) {
      printf( "%d ", root->data );
      preOrder( root->right );
      preOrder( root->left );
  }
}

void inOrder( struct elem *root ) {

  if( root != NULL ) {
      preOrder( root->right );
      printf( "%d ", root->data );
      preOrder( root->left );
  }
}

void postOrder( struct elem *root ) {

  if( root != NULL ) {
      preOrder( root->right );
      preOrder( root->left );
      printf( "%d ", root->data );
  }
}
