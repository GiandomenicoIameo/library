
# Installazione di *SWI-Prolog*

![red](https://via.placeholder.com/15/f03c15/000000?text=ok)

```diff
+ text in red
text in green
text in orange
text in gray
```

```bash
# Linux ( Debian )
#
# Abilita snapd :
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
# prolog, nel terminale, con il seguente comando:

swipl 
Welcome to SWI-Prolog (threaded, 64 bits, version 8.0.2)

?- 
```

```bash
# Per caricare un programma sono disponibili 3 diversi comandi:

?- [ 'program.pl' ].                # oppure
?- consult( 'program.pl' ).         # viene utilizzato quando si carica un programma per la prima volta
?- reconsult( 'program.pl' ).       # viene utilizzato quando si carica un programma dopo una correzione
```

