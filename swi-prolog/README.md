
# Installazione di *SWI-Prolog*

```bash
# Linux ( Debian )
# Installazione Snapd
#
# Snapd è la tecnologia che permette ai pacchetti 
# Snap di essere eseguiti su Linux. Questi ultimi 
# possono essere installati dallo snap store e contengono 
# al loro interno tutto ciò che il programma ha bisogno per 
# essere avviato correttamente come ad esempio file audio, 
# librerie, file binari e così via. 
#
# A partire da Debian 9 ( Stretch ), 
# e in ogni versione successiva, sarà possibile installare
# snap direttamente dalla linea di comando :

sudo apt update
sudo apt install snapd
sudo snap install core

# installa swi-prolog

sudo snap install swi-prolog

# Linux ( Ubuntu )
# Installazione tramite PPA ( Ubuntu Personal Package Archive )
#
# Esistono PPA per lo sviluppo e alcuni basati sulla struttura
# di pacchettizzazione Debian. Indipendentemente dalla scelta,
# questi vengono aggiornati ogni volta si presenta una nuova
# versione.

# Versioni stabili

sudo apt-add-repository ppa:swi-prolog/stable
sudo apt update
sudo apt install swi-prolog

# Versioni di sviluppo

sudo apt-add-repository ppa:swi-prolog/devel
sudo apt update
sudo apt install swi-prolog

```

# Esecuzione di programmi 

```bash
# Una volta installato il pacchetto swi-prolog non ci resta 
# che avviare l'interprete prolog da riga di comando :

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

