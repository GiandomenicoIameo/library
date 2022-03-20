
# Installazione di *SWI-Prolog*

```bash
# Abilita snapd
#
# A partire da Debian 9 ( Stretch ), e in ogni 
# versione successiva, sarà possibile installare
# snap direttamente dalla linea di comando :

sudo apt update
sudo apt install snapd
sudo snap install core

# installa swi-prolog
sudo snap install swi-prolog
```

# Esecuzione di programmi 

```bash
# Se l'installazione è avvenuta con successo non ci resta che avviare l'interprete
# prolog:

$ swipl 
Welcome to SWI-Prolog (threaded, 64 bits, version 8.0.2)
SWI-Prolog comes with ABSOLUTELY NO WARRANTY. This is free software.
Please run ?- license. for legal details.

For online help and background, visit http://www.swi-prolog.org
For built-in help, use ?- help(Topic). or ?- apropos(Word).

?- 
```

```prolog
# Per caricare un programma sono disponibili 3 diversi comandi:

?- [ 'program.pl' ].                # oppure
?- consult( 'program.pl' ).         # viene utilizzato quando si carica un programma per la prima volta
?- reconsult( 'program.pl' ).       # viene utilizzato quando si carica un programma dopo una correzione
```

