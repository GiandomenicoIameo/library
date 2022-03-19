:- include( 'combinatorics.pro' ).

generate_binomial( Xs, Zs ) :- sort( Xs, Ys ),
binomial( Ys, Zs ).

generate_permutation( Xs, Ys ) :- permutation( Xs, Xs, Ys ).
