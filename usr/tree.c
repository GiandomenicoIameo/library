#include "include/tree.h"

struct tree *pose( int data ) {

  struct tree *node;

  node = ( struct tree* )malloc( sizeof( struct tree ) );
  if( !node ) return node;

  node->left = NULL;
  node->data = data;
  node->right = NULL;

  return node;
}

struct tree *insert( struct tree *root, struct tree *node ) {

  struct tree *res;

  if( !root ) {
          res = node;
  } else {
          if( node->data == root->data ) {
                  res = root;
  } else if( root->data < node->data ) {
          root->right = insert( root->right, node );
                  res = root;
  } else {
          root->left = insert( root->left, node );
          res = root;
      }
  }
  return res;
}

void bspre( struct tree *root ) {

  if( root ) {
          printf( "%d ", root->data );
          preOrder( root->left );
          preOrder( root->right );
  }
}

void bsin( struct tree *root ) {

  if( root ) {
          inOrder( root->left );
          printf( "%d ", root->data );
          inOrder( root->right );
  }
}

void bspost( struct tree *root ) {

  if( root ) {
          postOrder( root->left );
          postOrder( root->right );
          printf( "%d ", root->data );
  }
}

struct tree *bsmin( struct tree* root ) {

  struct tree *res;

  if( !root ) {
          res = root;
  } else {
          if( root->left )
                  res =  bsmin( root->left );
          else
                  res = root;
  }
  return res;
}

struct tree *bsmax( struct tree* root ) {

  struct tree *res;

  if( !root ) {
      res = root;
  } else {
      if( root->right )
              res =  bsmax( root->right );
      else
              res = root;
  }
  return res;
}

struct tree *bstree( struct tree *root, int data ) {

  struct tree *res;

  if( !root ) {
          res = root;
  } else {
          if( data == root->data )
                  res = root;
          else if( data > root->data )
                  res = bstree( root->right, data );
          else
                  res = bstree( root->left, data );
  }
  return res;
}

void bsort( int* array, const int len ) {

  struct tree *root = NULL;
  struct tree *node = NULL;

  for( int step = 0; step < len; step++ ) {
          node = pose( array[ step ] );
          root = insert( root, node );
  }
  visit( root, array );
}

static void visit( struct tree *root, int* array ) {

  static int step = 0;

  if( root ) {
          visit( root->left, array );
          array[ step++ ] = root->data;
          visit( root->right, array );
  }
}
