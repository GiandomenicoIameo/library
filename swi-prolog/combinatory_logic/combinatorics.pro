member( X, [ X|_ ] ).
member( X, [ _|Xs ] ) :- member( X, Xs ).

delete( X, [ X|Xs ], Xs ).
delete( X, [ Y|Ys ], [ Y|Zs ] ) :- X \== Y, delete( X, Ys, Zs ).

binomial( [], [] ).
binomial( [ X|Xs ], [ X|Ys ] ) :- binomial( Xs, Ys ).
binomial( [ _|Xs ], Ys ) :- binomial( Xs, Ys ).

permutation( _, [] ).
permutation( Ys, [ X|Xs ] ) :- delete( X, Ys, Zs ),
permutation( Zs, Xs ).

combination( _, [] ).
combination( Ys, [ X|Xs ] ) :-
combination( Ys, Xs ), member( X, Ys ).
