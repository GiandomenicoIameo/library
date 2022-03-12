elem( X, [ X|_ ] ).
elem( X, [ _|Xs ] ) :- elem( X, Xs ).

delete( Y, [ Y|Ys ], Ys ).
delete( X, [ Y|Ys ], [ Y|Zs ] ) :- delete( X, Ys, Zs ).

binomial( [], [] ).
binomial( [ X|Xs ], [ X|Ys ] ) :- binomial( Xs, Ys ).
binomial( [ _|Xs ], Ys ) :- binomial( Xs, Ys ).

permutation( _, [] ).
permutation( Ys, [ X|Xs ] ) :- delete( X, Ys, Zs ),
permutation( Zs, Xs ).

combination( _, [] ).
combination( Ys, [ X|Xs ] ) :- elem( X, Ys ),
combination( Ys, Xs ).
