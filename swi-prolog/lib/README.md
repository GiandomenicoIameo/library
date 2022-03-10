# Calcolo combinatorio

## ```binomial/2```:

Il predicato ```binomial/2``` consente di ricercare il numero dei sottoinsiemi, di un particolare insieme, aventi cardinalità non superiore all’insieme di partenza. Oltre a ciò, come accade spesso nel linguaggio Prolog, tale predicato è anche bidirezionale. Infatti, può essere utilizzato per :

Ricercare tutti i possibili sottoinsiemi di un insieme di partenza ( insieme delle parti ) :

```prolog
?- binomial( [ a,b,c ], X ).
X = [] ;
X = [a] ;
X = [a, b] ;
X = [a, b, c] ;
X = [a, c] ;
X = [b] ;
X = [b, c] ;
X = [c] ;
false. 
```
Ricercare solo i sottoinsiemi di cardinalità k:

```prolog
?- binomial( [ a,b,c ], [ X,Y ] ). /* il predicato ricerca i sottoinsiemi di [ a,b,c ] di cardinalità 2. */
X = a,
Y = b ;
X = a,
Y = c ;
X = b,
Y = c ;
false.
```

Ricercare ogni possibile soprainsieme di un certo insieme dato come input :

```prolog
?- binomial( X, [ a,b ] ).
X = [a, b|_3196] ;
X = [a, _3194, b|_3202] ;
X = [a, _3194, _3200, b|_3208] ;
X = [a, _3194, _3200, _3206, b|_3214] ;
...
```
In questo caso, sono stati ricercati tutti i soprainsiemi dell'insieme 
```[a, b]``` e cioè tutti gli insieme ```X``` tali che,```X``` contiene ```[a, b]``` come parte. Ovviamente i risultati non avranno fine.

Inoltre, come è facilmente intuibilie, è anche possibile utilizzare il predicato con il solo scopo di verificare che un insieme ```A``` è sottoinsieme di un certo insieme ```B```, quindi ```B``` risulterà essere soprainsieme di ```A```.

```prolog
?- binomial( [ a,b,c ], [ a,b ] ).
true.

?- binomial( [ a,b ], [ a,b,d ] ).
false.
```


----------
__*N.B.*__ Il predicato ```binomial/2``` suppone per ipotesi che l'insieme ricevuto come argomento sia effettivamente un insieme. Tuttavia, se il predicato riceverà in input una ennupla ordinata in cui compaiono elementi ripetuti, i risultati che produrrà potrebbero essere non quelli desiderati : verranno generati insiemi con elementi ripetuti. Per ovviare a ciò, è possibile utilizzare il predicato ```generate_binomial/2``` :

```prolog
?- generate_binomial( [ a,b,c,a,c ], X ).
X = [] ;
X = [a] ;
X = [a, b] ;
X = [a, b, c] ;
X = [a, c] ;
X = [b] ;
X = [b, c] ;
X = [c] ;
false.
```

Il predicato ha considerato l'insieme ```[a, b, c, a, c]``` prefettamente equivalente all'insieme ```[a, b, c]```. Nonostante questo vantaggio, lo stesso predicato non è bidirezionale.
