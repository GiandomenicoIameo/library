Combinatory logic
===

```binomial/2```:
---

Il predicato ```binomial/2``` consente di ricercare il numero dei sottoinsiemi, di un particolare insieme, aventi cardinalità non superiore all’insieme di partenza. Oltre a ciò, come accade spesso nel linguaggio Prolog, il suddetto predicato è anche bidirezionale, quindi può essere utilizzato per vari scopi :

Ricercare tutti i possibili sottoinsiemi di un insieme di partenza ( insieme delle parti ) :

```prolog
?- binomial( [ a,b,c ], X ).
X = [a, b, c] ;
X = [a, b] ;
X = [a, c] ;
X = [a] ;
X = [b, c] ;
X = [b] ;
X = [c] ;
X = [].
```
Ricercare solo i sottoinsiemi di cardinalità `k` ( coefficiente binomiale `n` su `k` ) :

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
Ricercare tutti i possibili soprainsiemi di un insieme :

```prolog
?- binomial( X, [ a,b,c ] ).
X = [a, b, c] ;
X = [a, b, c, _4378] ;
X = [a, b, c, _4378, _4384] ;
X = [a, b, c, _4378, _4384, _4390] ;
X = [a, b, c, _4378, _4384, _4390, _4396] ;
X = [a, b, c, _4378, _4384, _4390, _4396, _4402] ;
X = [a, b, c, _4378, _4384, _4390, _4396, _4402, _4408] 
...
```
Ovviamente i risultati non avranno fine.
Come conseguenza dei precedenti predicati, è anche possibile utilizzare lo stesso predicato con il solo scopo di verificare che un insieme `A` sia sottoinsieme di un certo insieme `B` ( relazione di inclusione ). E' sufficiente scrivere la query nel seguente modo :

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
Ricercare ogni possibile insieme partendo da un raggruppamento di `n` oggetti dato in input :

```prolog
?- permutation( [ X,Y ], [ a,b ] ).
X = a,
Y = b ;
X = b,
Y = a ;
false.

?- permutation( [ X ], [ a,b ] ).
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

Nel secondo caso, il predicato ha ricercato dei particolari raggruppamenti chiamati con il nome di **permutazioni**. Inoltre, Come per il primo predicato, anche questo secondo, è in grado di verificare se un raggruppamento è una possibile disposizione di elementi generata dall'insieme di partenza. Basta scrivere la query in questo modo :

```prolog
?- permutation( [ a,b,c ], [ a,b ] ), !.
true.

?- permutation( [ a,b,c ], [ a,d ] ), !.
false.
```
Avvertenze:
---

Il predicato ```binomial/2``` suppone per ipotesi che l'insieme ricevuto come argomento sia effettivamente un insieme. Tuttavia, se per assurdo il predicato dovesse ricevere in input una ennupla ordinata in cui compaiono elementi ripetuti, i risultati che produrrà potrebbero essere non quelli desiderati : verranno generati insiemi con elementi ripetuti. Inoltre, il predicato tiene anche conto dell'ordine degli elementi appartenti a un insieme : l'insieme `[ a,b,c ]` verrà visto in modo diverso rispetto all'insieme `[ b,a,c ]`, producendo quindi risultati diversi anche se i due sono perfettamente equivalenti.

Per ovviare a ciò, è possibile utilizzare il predicato ```generate_binomial/2``` :

```prolog
?- generate_binomial( [ a,b,c,a,c ], X ).
X = [a, b, c] ;
X = [a, b] ;
X = [a, c] ;
X = [a] ;
X = [b, c] ;
X = [b] ;
X = [c] ;
X = [].
```

Il predicato ha considerato l'insieme `[a, b, c, a, c]` prefettamente equivalente all'insieme `[a, b, c]`.

```combination/2```:
---
Il predicato `combination/2` consente di ricercare il numero di disposizioni con ripetizione di `n` elementi a `k` a `k`. A differenza delle disposizioni semplici, generate dal predicato `permutation/2`, non vale il vincolo `k` minore o uguale a `n`: poiché ogni volta è possibile estrarre dall'insieme qualsiasi elemento senza correre il rischio di catturare duplicati. Inoltre, non esiste pericolo alcuno che questi elementi si esauriscono come capita invece nelle disposizioni semplici in cui, dopo `n` estrazioni, non rimangono nell'insieme più elementi da poter estrarre.
Come per i precedenti predicati, anche questo è multidirezionale. I prossimi esempi mostreranno in che modo potrà essere utilizzato :

Ricercare il numero di disposizioni con ripetizione di cardinalità `k` :

```prolog
?- combination( [ 0,1 ], [ X,Y ] ). /* il predicato ricerca le disposizoni di cardinalità 2. */
X = Y, Y = 0 ;
X = 1,
Y = 0 ;
X = 0,
Y = 1 ;
X = Y, Y = 1 ;
false.
```
