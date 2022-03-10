Calcolo combinatorio
===

***

```binomial/2```:
---

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

Inoltre, come è facilmente intuibile, è anche possibile utilizzare il predicato con il solo scopo di verificare che un insieme ```A``` sia sottoinsieme di un certo insieme ```B```.

```prolog
?- binomial( [ a,b,c ], [ a,b ] ). /* il predicato verifica se [ a,b ] è incluso in [ a,b,c ] */
true.

?- binomial( [ a,b ], [ a,b,d ] ). /* il predicato verifica se [ a,b,d ] è incluso in [ a,b ] */
false.
```


---
```permutation/2```:
---

Il predicato ```permutation/2``` consente di ricercare ogni raggruppamento di oggetti, la cui cardinalità non supera il numero di tali oggetti. Nel caso in cui la cardinalità di ogni raggruppamento è strettamente inferiore al numero di oggetti in questione, si parlerà di disposizioni mentre nell'altro caso si parlerà di permutazioni. Anche questo predicato è multidirezionale, quindi può essere utilizzato per vari scopi :

Ricercare tutti i possibili raggruppamenti di n oggetti di cardinalità non superiore a n :

```prolog
?- permutation( [ a,b,c ], X ).
X = [] ;
X = [a] ;
X = [a, b] ;
X = [a, b, c] ;
X = [a, c] ;
X = [a, c, b] ;
X = [b] ;
X = [b, a] ;
X = [b, a, c] ;
X = [b, c] ;
X = [b, c, a] ;
X = [c] ;
X = [c, a] ;
X = [c, a, b] ;
X = [c, b] ;
X = [c, b, a] ;
false.
```

Ricercare tutti i possibili raggruppamenti di n oggetti di cardinalità k :

```prolog
?- permutation( [ a,b ], [ X ] ).
X = a ;
X = b ;
false.

?- permutation( [ a,b ], [ X,Y ] ).
X = a,
Y = b ;
X = b,
Y = a ;
false.
```

Nel secondo caso, il predicato ha ricercato le permutazioni, poichè la cardinalità dei raggruppamenti è pari al numero di oggetti.




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
