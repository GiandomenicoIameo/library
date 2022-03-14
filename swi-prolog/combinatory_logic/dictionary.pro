:- include( 'combinatorics.pro' ).

generate_binomial( Xs, Zs ) :- sort( Xs, Ys ),
binomial( Ys, Zs ).
