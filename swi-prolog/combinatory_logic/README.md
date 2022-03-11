Combinatory logic
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
Ricercare solo i sottoinsiemi di cardinalità `k` :

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
Inoltre, come è facilmente intuibile, è anche possibile utilizzare il predicato con il solo scopo di verificare che un insieme ```A``` sia sottoinsieme di un certo insieme ```B```. E' sufficiente scrivere il predicato nel seguente modo :

```prolog
?- binomial( [ a,b,c ], [ a,b ] ), !. /* il predicato verifica se [ a,b ] è incluso in [ a,b,c ] */
true.

?- binomial( [ a,b ], [ a,b,d ] ), !. /* il predicato verifica se [ a,b,d ] è incluso in [ a,b ] */
false.
```

```permutation/2```:
---

Il predicato ```permutation/2``` consente di ricercare ogni raggruppamento di oggetti, la cui cardinalità non supera il numero di tali oggetti. Per ogni sottoinsieme ordinato di ```k``` elementi estratti da un insieme di ```n``` elementi, i vari sottoinsiemi possono differire almeno in un elemento oppure, in presenza degli stessi elementi, nel modo in cui sono ordinati. Anche questo predicato è multidirezionale, quindi può essere utilizzato per vari scopi :

Ricercare tutti i possibili raggruppamenti di ```n``` oggetti di cardinalità non superiore a ```n``` :

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

Ricercare tutti i possibili raggruppamenti di ```n``` oggetti di cardinalità ```k``` :

```prolog
?- permutation( [ a,b ], [ X ] ). /* il predicato ricerca i raggruppamenti di cardinalità 1. */
X = a ;
X = b ;
false.

?- permutation( [ a,b ], [ X,Y ] ). /* il predicato ricerca i raggruppamenti di cardinalità 2. */
X = a,
Y = b ;
X = b,
Y = a ;
false.
```

Nel secondo caso, il predicato ha ricercato dei particolari raggruppamenti chiamati con il nome di **permutazioni**. Il predicato consente anche di ricercare ogni possibile insieme ```A``` che genera ```B``` come raggruppamento :

```prolog
?- permutation( X, [ a,b ] ).
X = [a, b|_4558] ;
X = [a, _4556, b|_4564] ;
X = [a, _4556, _4568, b|_4576] ;
X = [a, _4556, _4568, _4580, b|_4588] ;
X = [a, _4556, _4568, _4580, _4592, b|_4600] 
...
```

Come per il primo predicato, anche questo secondo, è in grado di verificare se un raggruppamento è una possibile disposizione di elementi generata dall'insieme di partenza.

```prolog
?- permutation( [ a,b,c ], [ a,b ] ).
true.

?- permutation( [ a,b,c ], [ a,d ] ).
false.
```

***

>NOTE:
>
> Il predicato ```binomial/2``` suppone per ipotesi che l'insieme ricevuto come argomento sia effettivamente un insieme. Tuttavia, se per assurdo il predicato dovesse ricevere in input una ennupla ordinata in cui compaiono elementi ripetuti, i risultati che produrrà potrebbero essere non quelli desiderati : verranno generati insiemi con elementi ripetuti.

***

Per ovviare a ciò, è possibile utilizzare il predicato ```generate_binomial/2``` :

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
