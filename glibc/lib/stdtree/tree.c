#include "../include/tree.h"

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
            } else if( node->data > root->data ) {
                    root->right = insert( root->right, node );
                    res = root;
            } else {
                    root->left = insert( root->left, node );
                    res = root;
            }
    }
    return res;
}

struct tree *destroy( struct tree *root ) {

    struct tree *res;

    if( !root ) {
            res = root;
    } else {
            res = destroy( root->left );
            res = destroy( root->right );
            free( root );
    }
    return res;
}

void preorder( struct tree *root ) {

    if( root ) {
            printf( "%d ", root->data );
            preorder( root->left );
            preorder( root->right );
    }
}

void inorder( struct tree *root ) {

    if( root ) {
            inorder( root->left );
            printf( "%d ", root->data );
            inorder( root->right );
    }
}

void postorder( struct tree *root ) {

    if( root ) {
            postorder( root->left );
            postorder( root->right );
            printf( "%d ", root->data );
    }
}

struct tree *bsmin( struct tree* root ) {

    struct tree *res;

    if( !root ) {
            res = root;
    } else {
            if( root->left ) {
                    res =  bsmin( root->left );
            } else {
                    res = root;
            }
    }
    return res;
}

struct tree *bsmax( struct tree* root ) {

    struct tree *res;

    if( !root ) {
        res = root;
    } else {
        if( root->right ) {
                res =  bsmax( root->right );
        } else {
                res = root;
        }
    }
    return res;
}

int checkup( struct tree *root, int min, int max ) {

    int L, R;
    int res;

    if( !root ) {
            res = 1;
    } else {
             if( min <= root->data && root->data <= max ) {
                     L = checkup( root->left, min, root->data );
                     R = checkup( root->right, root->data, max );

                     res = L && R;
             } else {
                     res = 0;
             }
    }
    return res;
}

struct tree *bstree( struct tree *root, int data ) {

    struct tree *res;

    if( !root || data == root->data ) {
            res = root;
    } else if( data < root->data ) {
            res = bstree( root->left, data );
    } else {
            res = bstree( root->right, data );
    }

    return res;
}

/**    
    L'operazione di inserimento di un nodo all'interno di un albero bilanciato costa, in termini di tempo, log2( n ), dove
    n sono i nodi attualmente presenti nell'albero. Ogni nuova inserzione parte dalla radice e scende giù nell'albero esistente
    creato fino a quel momento, per trovare dove agganciare il nodo. Il costo totale per costruire l'albero di len nodi è 
    
    O( log( 1 ) ) + O( log( 2 ) ) + O( log( 3 ) ) + ... + O( log( len ) ) = O( log( len! ) ) = O( len * log( len ) )
*/

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
