:- include( 'combinatorics.pro' ).

generate_binomial( Xs, Zs ) :- sort( Xs, Ys ),
binomial( Ys, Zs ).

generate_combination( Xs, Zs ) :- sort( Xs, Ys ),
combination( Ys, Zs ).
