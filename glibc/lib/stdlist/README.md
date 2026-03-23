Libreria stdlist.c
===================

----------

Il file contiene alcune delle più importanti funzioni che operano
sulle **liste semplicemente concatenate**. Ogni funzione dichiarata è
stata studiata nel minimo dettaglio per garantire, a chi le utilizza,
prestazioni efficienti in relazione al **tempo** e allo **spazio** utilizzato.

Strutture dati utilizzate :
----------

Il file header (stdlist.h) introduce le seguenti **strutture dati dinamiche**: 

- **Lista collegata**: è semplicemente una collezione di dati. 
  Trovo molto semplice immaginarli come "allineati in una riga".
  In una lista collegata, le inserzioni e le cancellazioni possono avvenire in un
  qualsiasi punto.

- **Stack**: È un tipo di lista collegata in cui le inserzioni e le cancellazioni avvengono
 _solo a un estremo_, ovvero la sua **cima**.

- **Coda**: È un tipo di lista collegata in cui inserzioni avvengono
  _solo alla fine_ e le rimozioni avvengono _solo all'inizio_.

Tali _strutture autoreferenziale_, anche se apparentemente molto diverse tra di loro, condividono un aspetto: 
possiedono un membro puntatore che punta a una struttura dello stesso tipo. Qui di seguito ho riportato
le definizioni delle strutture **Lista collegata** e **Coda**.

```c
// Struttura del nodo
struct elem {
    int data;
    struct elem *next;
};

// Struttura della coda
struct equeue {
    struct elem *top;
    struct elem *end;
};
```

Lo stile di scrittura del codice, se non fosse già chiaro, rispecchia quello 
adottato in **GNOME**. Sebbene le convenzioni di formattazione siano una questione di gusti, la 
community di **GNOME** preferisce uno stile che promuova coerenza, leggibilità e 
manutenibilità. 

Qui di seguito ho illustrato un esempio di scrittura del codice :

Funzione pop :
----------

```c
struct elem *pop( struct elem *top ) {

  struct elem *res;

  if( !top ) {
          res = top;
  } else {
          res = top->next;
          free( top );
  }
  return res;
}
```

> Note :
> 
> Il file stdlist.c non fa parte della libreria standard del C. Essa
> è stata distribuita nella speranza che sia utile,
> ma **senza alcuna garanzia**.
