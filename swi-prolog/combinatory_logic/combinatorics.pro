member( X, [ X|_ ] ).
member( X, [ _|Xs ] ) :- member( X, Xs ).

delete( X, [ X|Xs ], Xs ).
delete( X, [ Y|Ys ], [ Y|Zs ] ) :- delete( X, Ys, Zs ).

binomial( [], [] ).
binomial( [ X|Xs ], [ X|Ys ] ) :- binomial( Xs, Ys ).
binomial( [ _|Xs ], Ys ) :- binomial( Xs, Ys ).

permutation( [], _, [] ).
permutation( [ X|_ ], Acc, [ X|Ys ] ) :- delete( X, Acc, Zs ),
permutation( Zs, Zs, Ys ).
permutation( [ _|Xs ], Acc, Ys ) :- permutation( Xs, Acc, Ys ).

combination( _, [] ).
combination( Ys, [ X|Xs ] ) :-
combination( Ys, Xs ), member( X, Ys ).

disposition( Xs, Ys ) :-
permutation( Xs, Xs, Ys ).
